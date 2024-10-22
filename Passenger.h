 /* 
 *  Julia Yoo jyoo06
 *  29/09/2023
 *
 *  CS 15 PROJECT 1 - METRO SIM
 *
 *  Declaration for the Passenger Class.
 */

#ifndef __PASSENGER_H__
#define __PASSENGER_H__

#include <iostream>
#include <vector>
struct Passenger
{

        int id, from, to;
        
        Passenger()
        {
                id   = -1;
                from = -1;
                to   = -1;
        }

        Passenger(int newId, int arrivalStation, int departureStation)
        {
                id   = newId;
                from = arrivalStation;
                to   = departureStation;
        }

        void print(std::ostream &output);

};

#endif
