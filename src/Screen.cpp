#include "Screen.h"
#include<stdexcept>
Screen::Screen(const std::string & screenId):screenId(screenId){
    if(this->screenId.empty()){
        throw std::invalid_argument("Screen id  cannot be Empty");

    }
}
void Screen::addSeat(const Seat&seat){
    if(findSeatById(seat.getSeatId())!=nullptr){
        throw  std::invalid_argument("Seat ID already exist on this Screen");
    }
    seats.push_back(seat);

}
const Seat* Screen::findSeatById(const std::string&seatId)const{
    for ( const auto& seat :seats){
        if(seat.getSeatId()==seatId){
            return &seat;
        }
    }
    return nullptr;

}
std::string Screen::getScreenId()const {
    return screenId;
}
int Screen::getSeatCount() const {
    return static_cast<int>(seats.size());
}
