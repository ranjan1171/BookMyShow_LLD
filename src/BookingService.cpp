#include "BookingService.h"

#include <unordered_set>
#include <utility>

BookingService::BookingService()
    : nextBookingNumber(1001) {
}

std::string BookingService::bookSeats(
    Theatre& theatre,
    const std::string& showId,
    const std::vector<std::string>& seatIds,
    PaymentStrategy& paymentStrategy
) {
    if (seatIds.empty()) {
        return "";
    }

    Show* show = theatre.findShowById(showId);

    if (show == nullptr) {
        return "";
    }

    std::unordered_set<std::string> uniqueSeatIds;

    double totalAmount = 0.0;

    for (const auto& seatId : seatIds) {
        if (!uniqueSeatIds.insert(seatId).second) {
            return "";
        }

        const Seat* seat = show->getScreen().findSeatById(seatId);

        if (seat == nullptr) {
            return "";
        }

        if (!show->isSeatAvailable(seatId)) {
            return "";
        }

        totalAmount += seat->getBasePrice();
    }

    const std::string bookingId =
        "B" + std::to_string(nextBookingNumber);

    Booking booking(
        bookingId,
        showId,
        seatIds,
        totalAmount
    );

    std::vector<std::string> reservedSeatIds;

    for (const auto& seatId : seatIds) {
        if (!show->bookSeat(seatId)) {
            for (const auto& reservedSeatId : reservedSeatIds) {
                show->releaseSeat(reservedSeatId);
            }

            return "";
        }

        reservedSeatIds.push_back(seatId);
    }

    bool paymentSuccessful = false;

    try {
        paymentSuccessful = paymentStrategy.pay(totalAmount);
    } catch (...) {
        for (const auto& reservedSeatId : reservedSeatIds) {
            show->releaseSeat(reservedSeatId);
        }

        throw;
    }

    if (!paymentSuccessful) {
        for (const auto& reservedSeatId : reservedSeatIds) {
            show->releaseSeat(reservedSeatId);
        }

        return "";
    }

    booking.confirm();

    bookings.emplace(bookingId, std::move(booking));

    ++nextBookingNumber;

    return bookingId;
}

bool BookingService::cancelBooking(
    Theatre& theatre,
    const std::string& bookingId
) {
    Booking* booking = findBookingById(bookingId);

    if (booking == nullptr) {
        return false;
    }

    if (booking->getStatus() == BookingStatus::CANCELLED) {
        return false;
    }

    Show* show = theatre.findShowById(booking->getShowId());

    if (show == nullptr) {
        return false;
    }

    for (const auto& seatId : booking->getSeatId()) {
        if (show->getScreen().findSeatById(seatId) == nullptr) {
            return false;
        }

        if (show->isSeatAvailable(seatId)) {
            return false;
        }
    }

    for (const auto& seatId : booking->getSeatId()) {
        if (!show->releaseSeat(seatId)) {
            return false;
        }
    }

    booking->cancel();

    return true;
}

Booking* BookingService::findBookingById(
    const std::string& bookingId
) {
    auto it = bookings.find(bookingId);

    if (it == bookings.end()) {
        return nullptr;
    }

    return &it->second;
}