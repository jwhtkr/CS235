#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Fisherman.h"

using namespace std;

int main(int argc, char *argv[])
{
    if(argc != 2) 
    {
        cout << "Usage: "<<argv[0]<<" <filename>"<<endl;
    } 
    
    else 
    {
        ifstream fileHandle(argv[1]);
        
        if(!fileHandle.is_open()) 
        {
            cout << "Could not open file"<<endl;
        } 
        
        else 
        {
            string name;
            int amount;
            string type;
            vector<Fisherman *> fishermen;
            string search;
            
            while(!fileHandle.eof()) 
            {
                fileHandle >> name;
                if (name != "Search")
                {
                    fileHandle >> amount >> type;
                    Fisherman fisherman();
                    // fisherman.set_name(name);
                    // fisherman.set_amount(amount);
                    // fisherman.set_type(type);
                    //fishermen.push_back (* fisherman);
                    cout << name << "\t\t" << amount << "\t" << type << endl;
                }
                else
                {
                    fileHandle >> search;
                    cout << name << "\t\t" << search << endl;
                }
            }
        }
    }
}