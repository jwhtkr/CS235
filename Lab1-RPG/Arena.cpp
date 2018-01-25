#include "Arena.h"
	
using std::string;
using std::stringstream;
using std::cout;
using std::endl;
using std::vector;

/*
*	addFighter(string)
*
*	Adds a new fighter to the collection of fighters in the arena. Do not allow
*	duplicate names.  Reject any string that does not adhere to the format
*	outlined in the lab specs.
*
*	Return true if a new fighter was added; false otherwise.
*/
bool Arena::addFighter(string info)
{
	stringstream ss(info);
	string name, type;
	int hp, strength, speed, magic;
	
	if (ss >> name >> type >> hp >> strength >> speed >> magic)
	{
		for (std::vector<Fighter*>::iterator it = fighters.begin(); it < fighters.end(); it++)
		{
			if (name == (*it)->getName())
			{
				return false;
			}
		}
		if (!ss.eof())
		{
			return false;
		}
		
		if (type == "A")
		{
			fighters.push_back(new Archer(name, hp, strength, speed, magic));
		}
		else if (type == "C")
		{
			fighters.push_back(new Cleric(name, hp, strength, speed, magic));
		}
		else if (type == "R")
		{
			fighters.push_back(new Robot(name, hp, strength, speed, magic));
		}
		else
		{
			return false;
		}
		return true;
	}
	return false;
   
}

/*
*	removeFighter(string)
*
*	Removes the fighter whose name is equal to the given name.  Does nothing if
*	no fighter is found with the given name.
*
*	Return true if a fighter is removed; false otherwise.
*/
bool Arena::removeFighter(string name)
{
    for (std::vector<Fighter*>::iterator it = fighters.begin(); it < fighters.end(); it++)
    {
    	if (name == (*it)->getName())
    	{
    		fighters.erase(it);
    		return true;
    	}
    }
    return false;
}

/*
*	getFighter(string)
*
*	Returns the memory address of a fighter whose name is equal to the given
*	name.  Returns NULL if no fighter is found with the given name.
*
*	Return a memory address if a fighter is found; NULL otherwise.
*/
FighterInterface* Arena::getFighter(string name)
{
    for (vector<Fighter*>::iterator it = fighters.begin(); it < fighters.end(); it++)
    {
    	if (name == (*it)->getName())
    	{
    		return *it;
    	}
    }
    return NULL;
}

/*
*	getSize()
*
*	Returns the number of fighters in the arena.
*
*	Return a non-negative integer.
*/
int Arena::getSize() const
{
    return fighters.size();
}