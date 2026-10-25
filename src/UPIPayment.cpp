#include "UPIPayment.h"
#include<iostream>
bool UPIPayment::pay(double amount){
    if(amount<=0){
        std::cout<<"payment failed"<<std::endl;
        return false ;
    }


    std::cout <<"Processing  UPI payment of Rs "<<amount<< std::endl;

    std::cout<<"UPI payment Sucessful";

    return true ;
}