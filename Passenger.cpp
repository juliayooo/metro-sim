/* 
 *  Julia Yoo jyoo06
 *  29/09/2023
 *
 *  CS 15 PROJECT 1 - METRO SIM
 *
 *  Implementation for the Passenger Class.
 */
#include <iostream>
#include <string>
#include "Passenger.h"

/*
name:       Passenger print function
purpose:    print the contents of a passenger object   
args:       an output location
returns:    none 
effects:    Passenger contents printed to output 
*/ 
void Passenger::print(std::ostream &output)
{
        output << "[" << id << ", " << from << "->" << to << "]";

}
