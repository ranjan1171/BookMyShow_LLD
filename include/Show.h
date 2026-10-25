#pragma once

#include"Movie.h"
#include"Screen.h"

#include<chrono>
#include <string>
#include<unordered_set>


class Show {

    private:
    std::string  showId;
    Movie movie;
    Screen  screen;

    std::chrono::system_clock::time_point startTime;
    std::unordered_set<std::string>bookedSeatIds;
    public:

    Show(const  std::string& showId , const Movie& movie ,const Screen& screen ,  std::chrono::system_clock::time_point startTime);

    bool isSeatAvailable( const std::string&seatId);
    bool releaseSeat(const std::string& seatId);

    bool bookSeat( const std::string&seatId);
    std::string getShowId() const;
    const Movie& getMovie() const ;
    const Screen& getScreen() const ;

    std::chrono::system_clock::time_point getStartTime()const ;



};