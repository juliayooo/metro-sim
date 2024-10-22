
 /* 
 *  Julia Yoo jyoo06
 *  29/09/2023
 *
 *  CS 15 PROJECT 1 - METRO SIM
 *
 *  Implementation for the Passenger Queue Class.
 */
#include <iostream>
#include <string>
#include <list>
#include "PassengerQueue.h"
#include "Passenger.h"
/*
name:       PassengerQueue Constructor
purpose:    initialize a new passenger queue  
args:       a Passenger object
returns:    noner 
effects:    New PassengerQueue created 
*/ 
PassengerQueue::PassengerQueue(){

    std::list<Passenger> new_queue;
};
/*
name:       PassengerQueue front getter
purpose:    return first passenger in queue 
args:       none
returns:    the first passenger object in queue 
effects:    none
*/ 
    Passenger PassengerQueue::front(){
        return PassengersQueue.front();

    };
    
/*
name:       PassengerQueue dequeue function
purpose:    remove the first passenger in queue 
args:       none
returns:    none
effects:    first passenger in queue removed.
*/ 
    void PassengerQueue::dequeue(){
        return PassengersQueue.pop_front();
    };
/*
name:       PassengerQueue enqueue function
purpose:    Add a new passenger to front of queue
args:       nonr
returns:    none
effects:    new passenger added to front of queue
*/ 
    void PassengerQueue::enqueue(const Passenger &passenger){
        PassengersQueue.push_back(passenger);
    }
/*
name:       PassengerQueue size function
purpose:    return current size of queue
args:       none
returns:    current int size of queue
effects:    none
*/ 
    int PassengerQueue::size(){
        return PassengersQueue.size();
    };
/*
name:       PassengerQueue print function 
purpose:    print the Passenger Queue to output
args:       location of the output
returns:    none
effects:    full passenger queue printed to output 
*/ 
    void PassengerQueue::print(std::ostream &output){
        // use an iterator to move through nodes and call the passenger's print 
        // function on itself. 
        for(std::list<Passenger>::iterator i = PassengersQueue.begin();
         i != PassengersQueue.end(); ++i){
            i->print(output);

        }

    };
