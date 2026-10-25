#pragma once 
#include <string>

class Movie{

    private:
     std::string movieId;
     std::string title;
     int durationMinutes;
    public:

    Movie(const std::string& movieId, const std::string &title , int durationMinutes);

    std::string getMovieId() const ;
    std::string getTitle() const ;
    int getDurationMinutes() const ;



};

//later we will create   object like Movie movie1("M101" , "DDLJ" , 169)
// Movie movie2("M102" , "RA.ONE" , 179)


/*flow  will be like 

 movie.h(declare headers and getter functions) ----> Movie.cpp(include this header and implements the constructors and getters )---> another class can call the public functions    for example  show.cpp ---can call the movie.h*/
             