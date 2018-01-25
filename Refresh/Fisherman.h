#ifndef _FISHERMAN_H
#define _FISHERMAN_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using std::string;

class Fisherman
{
    private:
    string name;
    int amountCaught;
    string typeOfFish;
    
    public:
    //Default Constructor
    Fisherman();
    //Constructor
    Fisherman(string, int, string);
    //Setters
    void set_name (string name);
    void set_amount (int amount);
    void set_type (string type);
    //Getters
    string get_name ();
    int get_amount();
    string get_type();
};

#endif