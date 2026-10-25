#pragma once 

#include<string>
#include <vector>

enum class BookingStatus{
    PENDING,
    CONFIRMED,
    CANCELLED
};

class Booking {

    private:
    std::string bookingId;
    std::string showId;
     
    std::vector<std::string>seatIds;
    double totalAmount;
    BookingStatus status;
    
    public:

    Booking( const std::string& bookingId , const std::string&  showId , const std::vector<std::string>& seatIds, double totalAmount);


    void confirm();
    void cancel();
    std::string getBookingId() const ;

    std::string getShowId() const ;
    std::vector<std::string>getSeatId() const ;
    double getTotalAmount() const ;
    BookingStatus getStatus() const ;

};