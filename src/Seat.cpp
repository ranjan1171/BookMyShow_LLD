#include "Seat.h"
#include <stdexcept>

Seat::Seat( const std::string& seatId , SeatType type , double basePrice):seatId(seatId), type(type), basePrice(basePrice){

    if( this->seatId.empty()){
        throw std::invalid_argument("seat id can`t  be empty");
    }

    if ( this->basePrice<0){
        throw std::invalid_argument("Seat base price can`t be negative ");

    }


}

SeatType Seat::getType() const {
    return type ;

}


std::string Seat::getSeatId() const {
    return seatId;
}

double Seat::getBasePrice() const {
    return basePrice;
}