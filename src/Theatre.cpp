#include"Theatre.h"
#include <stdexcept>

Theatre::Theatre( const std::string& theatreId , const std::string& name ):theatreId(theatreId), name(name){
     if(this->theatreId.empty()|| this->name.empty()){
         throw std::invalid_argument("theatre ID and name can`t be  empty");

     }

}

void Theatre::addScreen(const Screen& screen){
    if (findScreenById(screen.getScreenId())!=nullptr){
        throw std::invalid_argument("Screen ID already exists in this theatre");

    }

    screens.push_back(screen);
}

void Theatre::addShow(const Show& show){
    if(findShowById(show.getShowId())!=nullptr ){
        throw std::invalid_argument("show ID already exist in this thratre");


    }

    shows.push_back(show);

}



const Screen* Theatre::findScreenById(const std::string& screenId)const {
    for( auto&screen:screens){
        if(screen.getScreenId()==screenId){
            return &screen;
        }
    }
    return nullptr;
}

const Show* Theatre::findShowById(const std::string& showId)const {
    for (auto& show :shows){
        if(show.getShowId()==showId){
            return &show;
        }
    }

    return nullptr;
    

}

std::string Theatre::getName() const{
    return name ;

}

std::string Theatre::getTheatreId() const {
    return theatreId;


}

int Theatre::getScreenCount() const{
     return static_cast<int> (screens.size());
}

int Theatre::getShowCount() const {
    return static_cast<int>(shows.size());
}