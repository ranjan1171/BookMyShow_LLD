#pragma once 

#include "Booking.h"
#include "PaymentStrategy.h"
#include "Theatre.h"

#include <string>
#include <unordered_map>
#include <vector> 

class BookingService{
    private:

    std::unordered_map<std::string , Booking> bookings;
     int nextBookingNumber ;

     public : 
     BookingService();
     std::string bookSeats(Theatre& theatre , const std::string& showId , const std::vector<std::string>&seatIds , PaymentStrategy&paymentStrategy);

     bool cancelBooking ( Theatre& theatre , const std::string& bookingId);

     Booking* findBookingById(const std::string& bookingId);


};
