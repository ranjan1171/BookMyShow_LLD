#pragma once 
#include "Seat.h"

#include<string>
#include<vector>

class Screen{

    private:
    std::string screenId;

    std::vector<Seat>seats;
    public:

    explicit Screen(  const std::string&ScreenId );

    void addSeat( const Seat& seat);

    const Seat* findSeatById( const std::string& seatId) const ;


    std::string getScreenId() const;

    int getSeatCount() const;



};

