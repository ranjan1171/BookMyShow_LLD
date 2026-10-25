#include"CreditCardPayment.h"

#include<iostream>


bool CreditCardPayment::pay(double amount ){
     if( amount<=0){
        std::cout<<"payment failed: invalid amount ";
        return false ;
     }

     std :: cout<<"Credit Card Payment successful";
     return true;
}