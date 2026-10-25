#include "BookingService.h"
#include "UPIPayment.h"
#include "CreditCardPayment.h"

#include <chrono>
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

int main() {
    try {
        Movie movie1("M101", "DDLJ", 169);
        Movie movie2("M201", "KKKG", 150);
        Movie movie3("M301", "RA.ONE", 200);

        Theatre theatre("T101", "PVR");

        Screen screen1("S101");
        Screen screen2("S102");
        Screen screen3("S103");

        const auto addSeats = [](Screen& screen) {
            screen.addSeat(Seat("A1", SeatType::REGULAR, 200.0));
            screen.addSeat(Seat("A2", SeatType::REGULAR, 200.0));
            screen.addSeat(Seat("B1", SeatType::PREMIUM, 300.0));
        };

        addSeats(screen1);
        addSeats(screen2);
        addSeats(screen3);

        theatre.addScreen(screen1);
        theatre.addScreen(screen2);
        theatre.addScreen(screen3);

        const auto startTime = std::chrono::system_clock::now();
        theatre.addShow(Show("SH101", movie1, screen1, startTime));
        theatre.addShow(Show("SH102", movie2, screen2, startTime));
        theatre.addShow(Show("SH103", movie3, screen3, startTime));

        BookingService bookingService;
        UPIPayment upiPayment;
        CreditCardPayment creditCardPayment;

        const std::vector<std::string> requestedSeats = {"A1", "A2"};
        const std::vector<std::pair<std::string, PaymentStrategy*>> bookingRequests = {
            {"SH101", &upiPayment},
            {"SH102", &creditCardPayment},
            {"SH103", &creditCardPayment}
        };

        std::string firstBookingId;

        std::cout << "Theatre: " << theatre.getName() << std::endl;

        for (const auto& request : bookingRequests) {
            const std::string& showId = request.first;
            PaymentStrategy* paymentStrategy = request.second;
            Show* show = theatre.findShowById(showId);
            if (show == nullptr) {
                throw std::runtime_error("Show not found: " + showId);
            }

            std::cout << std::endl << "Booking "
                      << show->getMovie().getTitle()
                      << " seats A1 and A2..." << std::endl;

            const std::string bookingId = bookingService.bookSeats(
                theatre,
                showId,
                requestedSeats,
                *paymentStrategy
            );

            if (bookingId.empty()) {
                throw std::runtime_error("Booking failed for show: " + showId);
            }

            if (firstBookingId.empty()) {
                firstBookingId = bookingId;
            }

            const Booking* booking =
                bookingService.findBookingById(bookingId);
            if (booking == nullptr) {
                throw std::runtime_error("Created booking could not be retrieved.");
            }

            std::cout << "Booking successful. ID: " << bookingId << std::endl;
            std::cout << "Total amount: Rs. "
                      << booking->getTotalAmount() << std::endl;
        }

        Show* firstShow = theatre.findShowById("SH101");
        std::cout << std::endl << "Is seat A1 available for SH101? "
                  << (firstShow != nullptr && firstShow->isSeatAvailable("A1")
                          ? "Yes"
                          : "No")
                  << std::endl;

        std::cout << std::endl << "Cancelling booking "
                  << firstBookingId << "..." << std::endl;
        if (!bookingService.cancelBooking(theatre, firstBookingId)) {
            throw std::runtime_error("Booking cancellation failed.");
        }

        std::cout << "Booking cancelled successfully." << std::endl;
        std::cout << "Is seat A1 available for SH101 now? "
                  << (firstShow != nullptr && firstShow->isSeatAvailable("A1")
                          ? "Yes"
                          : "No")
                  << std::endl;
    } catch (const std::exception& error) {
        std::cerr << "Error: " << error.what() << std::endl;
        return 1;
    }

    return 0;
}