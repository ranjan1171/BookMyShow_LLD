#include "Movie.h"
#include <stdexcept>
#include <utility>


Movie::Movie(const std::string& movieId , const std::string& title , int durationMinutes):movieId(movieId), title(title),
durationMinutes(durationMinutes)
{


    if ( this->movieId.empty()|| this->title.empty()){
        throw std::invalid_argument("Movie ID or titile cant be NULL");
        

    }

    if(this->durationMinutes<0){
        throw std::invalid_argument("Movie duration must be  greater then 0");
    }

}

std::string Movie::getMovieId() const {
    return movieId;

}

std::string Movie::getTitle() const {
    return title;
}

int Movie::getDurationMinutes() const {
    return durationMinutes;
}