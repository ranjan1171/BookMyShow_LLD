#include"Booking.h"

#include <stdexcept>
#include <unordered_set>
Booking::Booking( const std::string& bookingId , const std::string& showId , const std::vector<std::string>& seatIds, double totalAmount):
bookingId(bookingId), showId(showId), seatIds(seatIds), totalAmount(totalAmount), status (BookingStatus::PENDING){

    if(this->bookingId.empty() || this->showId.empty()){
        throw std::invalid_argument("Booking ID and show id cant be empty");

    }


    if( this-> seatIds.empty()){
        throw std::invalid_argument(" A booking must contain atleast one seat");

    }


    if( this->totalAmount<0){
        throw std::invalid_argument("Booking cant be negative ");
    }

    std::unordered_set<std::string> uniqueSeatIds;

    for ( const auto& seatId:this->seatIds){
        if(seatId.empty()){
            throw std::invalid_argument("seat ID cannot be empty");
        }

        if ( !uniqueSeatIds.insert(seatId).second){
            throw std::invalid_argument("Duplicate  seat ID in booking ");

        }
    }



}


void Booking::confirm(){
    if(status!=BookingStatus::PENDING){
        throw std::logic_error("only pending can be confirmed");
    }

    status= BookingStatus::CONFIRMED;
}


void  Booking::cancel(){
    if(status==BookingStatus::CANCELLED){
        throw std::logic_error("Booking is already cancelled");
    }

    status = BookingStatus::CANCELLED;
}


std::string Booking::getBookingId() const {
     return bookingId;
}


std::string Booking::getShowId() const {
    return showId;

}


std::vector<std::string> Booking::getSeatId()const{
    return seatIds;
}


double Booking::getTotalAmount() const {
    return totalAmount;
}


BookingStatus Booking::getStatus() const {
    return status ;
}
