#pragma  once 

#include <string>

enum class SeatType{
  REGULAR,
  PREMIUM
};

class  Seat{
    private:
    std::string seatId;
    SeatType type;
    double basePrice;

    public:
    Seat(const std::string&seatId, SeatType type, double basePrice);

    std::string getSeatId() const ;
    SeatType getType() const ;
    double getBasePrice() const;

};
