
 /* 
 *  Julia Yoo jyoo06
 *  29/09/2023
 *
 *  CS 15 PROJECT 1 - METRO SIM
 *
 *  Definition for the Passenger Queue Class.
 */

#ifndef __PASSENGERQUEUE_H__
#define __PASSENGERQUEUE_H__

#include <list>
#include <iostream>
#include "Passenger.h"


class PassengerQueue{
   
    public:
    //CONSTRUCTOR
    PassengerQueue();

    Passenger front();
    void dequeue();
    void enqueue(const Passenger &passenger);
    int size();
    void print(std::ostream &output);

    private:
    std::list<Passenger> PassengersQueue;
    void recursive_recyclepassenger();


};

#endif