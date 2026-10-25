#include"Show.h"

#include <stdexcept>

Show::Show(const std::string &showId , const Movie& movie, const Screen& screen, std::chrono::system_clock::time_point startTime):showId(showId), 
movie(movie), screen(screen), startTime(startTime){

    if(this->showId.empty()){
        throw std::invalid_argument("Show ID can not be empty");

    }
}


bool  Show::isSeatAvailable(const std::string& seatId){

    const Seat* seat = screen.findSeatById(seatId);
    if(seat== nullptr){
        return  false;
    }

    return bookedSeatIds.find(seatId)==bookedSeatIds.end();


}


bool Show::bookSeat(const  std::string& seatId){
     if(!isSeatAvailable(seatId)){
        return false;
     }

     bookedSeatIds.insert(seatId);
     return true ;
}


bool Show::releaseSeat(const std::string &seatId){
    if(screen.findSeatById(seatId)== nullptr){
        return false ;
    }

    return bookedSeatIds.erase(seatId)==1;
}



std::string Show::getShowId() const {
 return showId;
}

const Movie&Show::getMovie()const {
    return movie;
}


const Screen& Show ::getScreen()const {
    return screen;

}

std::chrono::system_clock::time_point Show::getStartTime()const {
    return startTime;
}