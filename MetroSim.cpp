
 /* 
 *  Julia Yoo jyoo06
 *  02/10/2023
 *
 *  CS 15 PROJECT 1 - METRO SIM
 *
 *  Implementation for the MetroSim Class.
 */

#include "MetroSim.h"
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
/*
name:       MetroSim constructor 
purpose:    create and initialize this MetroSim object/game.   
args:       argc, an input stream, an outputstream, and a commands stream
returns:    the fully set up and read-in MetroSim game
effects:    the MetroSim game is ready to play
*/ 
MetroSim::MetroSim(int argc, std::ifstream &input, std::ofstream &output,
 std::istream &commands){

    // initialize the stations vector, and the train list 
    std::string station_line; 
    int i = 0;
    while(getline(input, station_line)){
        //make a new station for each line
        Station new_station;
        // assign a number
        new_station.num = i;
        //assign the name 
        new_station.name = station_line;
        new_station.pplwaiting = 0;
        //add to stations vector
        Stations.push_back(new_station);
        //make a queue for each station on the train
        PassengerQueue new_aboard_queue;
        // add a queue for each station to the train list
        aboard_train.push_back(new_aboard_queue);
        i++;
        // set game over to false
        game_over = false;
    }
    //set the number of stations 
    stations_size = i;
    //set passenger amount 
    passenger_count = 0;
    // set the train
    station_at = 0;
    play_game(argc, input, output, commands);


}

/*
name:       play_game
purpose:    the main loop to play the game
args:       argc, an input stream, an outputstream, and a commands stream
returns:    none
effects:    game status is printed and queries taken until game over. results
            written to output 
*/ 
void MetroSim::play_game(int argc, std::ifstream &input, std::ofstream &output, 
std::istream &commands){
    
    //while the game is going, print board and ask for command
    if(argc == 3){
    while(not game_over){
        print_board();
        char query;
        //take the query
        cin >> query;
        //respond to the query
        if(query == 'm'){
            cin >> query; 
            if(query == 'm'){
                m(output);
            }
            if(query == 'f'){
                
                mf();
            }
        }

        if(query == 'p'){
            int from;
            int to;
            cin >> from;
            cin >> to;
            p(from, to);
        }
    }

    }
    //if given commands, take them from there
    if((argc == 4) or (argc == 5)){
    while((not game_over) and (not commands.eof())){
        print_board();
        char query;
        //take the query
       
            commands >> query;
        
        //respond to the query
        if(query == 'm'){
            commands >> query; 
            if(query == 'm'){
                m(output);
            }
            if(query == 'f'){
                
                mf();
            }
        }

        if(query == 'p'){
            int from;
            int to;
            commands >> from;
            commands >> to;
            p(from, to);
        }
        
    }


    }
    return;

}
/*
name:       m 
purpose:    resond to a move metro query 
args:       output stream
returns:    none
effects:    train is moved, passengers are appropriately picked up/dropped off  
*/
void MetroSim::m(std::ofstream &output){

    //board the passengers waiting at the station, storing them in the queue
    //that they'll get off at 
    
    for(int i = 0; i < Stations.at(station_at).pplwaiting; i++){
    list<PassengerQueue>::iterator getoff  = aboard_train.begin();
    advance(getoff, Stations.at(station_at).waiting.front().to);
    getoff->enqueue(Stations.at(station_at).waiting.front());

    //take the waiting passengers off the station queue, and decrement the 
    //count of passengers waiting. 
    Stations.at(station_at).waiting.dequeue();
    
    }

    Stations.at(station_at).pplwaiting = 0;

      station_at += 1;

    //get to the queue of people getting off TRAIN at this station
    list<PassengerQueue>::iterator it= aboard_train.begin();
    // if train is at the end, bring it back to start 
     if(station_at == stations_size){
        station_at = 0;
    }

    advance(it, station_at);

  
    //let the boarded passengers off 
    if(it->size() > 0){
        int deboarders = it->size();
    for(int i = 0; i < deboarders; i++){
        //write the de-boarder to output
        output << "Passenger " << it->front().id << " left train at station "
        << Stations.at(station_at).name << endl;
        it->dequeue();
    }
       
    }

   
    
}
/*
name:       p
purpose:    respond to a p query 
args:       provided passenger from/to ints
returns:    none
effects:    new passenger is created with provided from and to input
*/
void MetroSim::p(int from, int to){
    // create the new passenger 
    Passenger new_passenger(passenger_count + 1, from, to); 
    // make the passenger wait at its from station 
    Stations.at(from).waiting.enqueue(new_passenger);
    passenger_count+= 1;
    Stations.at(from).pplwaiting+= 1;

}
/*
name:       m f 
purpose:    respond to a m f  query 
args:       none
returns:    none
effects:    finished the game by making game_over true, and printing the 
            final message
*/
void MetroSim::mf(){
    game_over = true;
    cout << "Thanks for playing MetroSim. Have a nice day!" << endl;
    return; 
}


/*
name:       print_board  
purpose:    print the board to stdout 
args:       none
returns:    none
effects:    prints the updated game board to stdout 
*/
void MetroSim::print_board(){
//Print the passengers on the train 
    cout << "Passengers on the train: {";
    for(std::list<PassengerQueue>::iterator i = aboard_train.begin();
         i != aboard_train.end(); ++i){
            i->print(cout);
            }
            cout << "}" << endl;
            //Print the rest of the board
                for(int i = 0; i < stations_size; i++){
                    //if the train is at the station, print the train, too 
                    if(Stations.at(i).num == station_at){
                        cout << "TRAIN: " << "[" << i << "] " <<
                        Stations.at(i).name << " {";
                Stations.at(i).waiting.print(cout);
                cout << "}" << endl;
                //otherwise just print the station and the people waiting. 
                    }else{
                cout << "       [" << i << "] " << Stations.at(i).name << " {";
                Stations.at(i).waiting.print(cout);
                cout << "}" << endl;
                    }
            

        }
        cout << "Command? ";
        

}

/*
name:       destructor MetroSim
purpose:    MetroSim Destructor 
args:       none
returns:    none
effects:    Memory freed
*/
MetroSim::~MetroSim(){
    
}