#pragma once 
#include "PaymentStrategy.h"

class CreditCardPayment:public PaymentStrategy{
    public:

    bool pay(double amount) override;
};
