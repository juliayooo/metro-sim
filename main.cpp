 /* 
 *  Julia Yoo jyoo06
 *  02/10/2023
 *
 *  CS 15 PROJECT 1 - METRO SIM
 *
 *  The Main.cpp implementation for MetroSim.
 */

#include <iostream>
#include <fstream>
#include <string>

#include "MetroSim.h"

using namespace std;
/*
name:       open_or_die
purpose:    Open the provided stream file and return error if necessary  
args:       A stream and a filename
returns:    none
effects:    provided stream is open
*/ 
template<typename streamtype>
void open_or_die(streamtype &stream, string file_name){
        stream.open(file_name);
        if (not stream.is_open()){
                cerr << "Error: could not open file " << file_name << endl;
                exit(EXIT_FAILURE);
        }

}
int main(int argc, char *argv[])
{
     if(argc == 4){
        ifstream instream;
        ofstream outstream;
        ifstream commands; 
        open_or_die(instream, argv[1]);
        open_or_die(outstream, argv[2]);
        open_or_die(commands, argv[3]);
         MetroSim MetroSim(argc, instream, outstream, commands);
        outstream.close();
        instream.close();
        commands.close();
     }   
     if((argc == 3) or (argc == 5)){
        ifstream instream;
        ofstream outstream;
        open_or_die(instream, argv[1]);
        open_or_die(outstream, argv[2]);
        MetroSim MetroSim(argc, instream, outstream, cin);
        outstream.close();
        instream.close();
        
       
     }
     
        

        return 0;
}

