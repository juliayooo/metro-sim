
 /* 
 *  Julia Yoo jyoo06
 *  02/10/2023
 *
 *  CS 15 PROJECT 1 - METRO SIM
 *
 *  Declaration for the MetroSim Class.
 */
#ifndef _METROSIM_H_
#define _METROSIM_H_

#include "Passenger.h"
#include "PassengerQueue.h"
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;


class MetroSim
{

public:
   //Constructors 
    MetroSim(int argc, std::ifstream &input, std::ofstream &output,  
    std::istream &commands);

    //Destructors 
    ~MetroSim();

    void play_game(int argc, std::ifstream &input, std::ofstream &output, 
    std::istream &commands); 
    void p(int from, int to);
    void m(std::ofstream &output);
    void mf();
    void print_board();
    void print_PQ_out(std::list<PassengerQueue>::iterator it_PQ);

    private:
        struct Station{
        int num;
        std::string name;
        PassengerQueue waiting;
        int pplwaiting = 0;
        };
        
        void print_to_output(std::ofstream &output);
        int stations_size;
        bool game_over;
        int passenger_count;

        std::list<PassengerQueue> aboard_train;
        int station_at;
    
        std::vector<Station> Stations;
    

};

#endif
