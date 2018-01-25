#include "Fisherman.h"

using std::string;

//Default Constructor
Fisherman::Fisherman ()
{
    name = "";
    amountCaught = 0;
    typeOfFish = "";
}

//Constructor
Fisherman::Fisherman (string n, int amount, string type)
{
    name = n;
    amountCaught = amount;
    typeOfFish = type;
}

//Setters
void Fisherman::set_name (string n)
{
    name = n;
}

void Fisherman::set_amount (int amount)
{
    amountCaught = amount;
}

void Fisherman::set_type (string type)
{
    typeOfFish = type;
}

//Getters
string Fisherman::get_name()
{
    return name;
}

int Fisherman::get_amount()
{
    return amountCaught;
}

string Fisherman::get_type()
{
    return typeOfFish;
}