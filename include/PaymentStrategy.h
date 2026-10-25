#pragma once 

class PaymentStrategy{
  public :
  virtual ~PaymentStrategy()= default;

  virtual bool pay( double amount)=0;
  

};