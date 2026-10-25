#pragma once 

#include"PaymentStrategy.h"

class UPIPayment:public PaymentStrategy{
    public: 
    bool pay(double amount ) override;
};