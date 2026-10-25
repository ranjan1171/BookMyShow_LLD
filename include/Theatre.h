#include "Show.h"
#include "Screen.h"

#include < string > 
#include <vector>


class Theatre{

    private :

    std:: string theatreId;

    std::string name ;
    std::vector<Screen>screens;
    std::vector<Show>shows;


    public:
    Theatre(const std::string& theatreId , const std::string& name);

    void addScreen(const Screen& screen);
    void addShow(const Show& show);

    const Screen* findScreenById(const std::string&  screenId) const ;
    const  Show* findShowById( const std::string& showId) const ;

    std::string getTheatreId() const ;
    std::string getName() const ;
    int getScreenCount() const ;
    int getShowCount() const ;

};