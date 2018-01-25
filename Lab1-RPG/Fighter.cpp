#include "Fighter.h"

using std::string;
using std::stringstream;
using std::cout;
using std::endl;

Fighter::Fighter(string nm, int hp, int st, int sp, int mg)
{
    name = nm;
    maxHP = hp;
    currentHP = hp;
    speed = sp;
    strength = st;
    magic = mg;
}

/*
*	getName()
*
*	Returns the name of this fighter.
*/
string Fighter::getName() const
{
    return name;
}

/*
*	getMaximumHP()
*
*	Returns the maximum hit points of this fighter.
*/
int Fighter::getMaximumHP() const
{
    return maxHP;
}

/*
*	getCurrentHP()
*
*	Returns the current hit points of this fighter.
*/
int Fighter::getCurrentHP() const
{
    return currentHP;
}

/*
*	getStrength()
*
*	Returns the strength stat of this fighter.
*/
int Fighter::getStrength() const
{
    return strength;
}

/*
*	getSpeed()
*
*	Returns the speed stat of this fighter.
*/
int Fighter::getSpeed() const
{
    return speed;
}

/*
*	getMagic()
*
*	Returns the magic stat of this fighter.
*/
int Fighter::getMagic() const
{
    return magic;
}


/*
*	takeDamage(int)
*
*	Reduces the fighter's current hit points by an amount equal to the given
*	damage minus one fourth of the fighter's speed.  This method must reduce
*	the fighter's current hit points by at least one.  It is acceptable for
*	this method to give the fighter negative current hit points.
*
*	Examples:
*		damage=10, speed=7		=> damage_taken=9
*		damage=10, speed=9		=> damage_taken=8
*		damage=10, speed=50		=> damage_taken=1
*/
void Fighter::takeDamage(int damage)
{
    if ((damage - speed / 4) < 1)
    {
        currentHP -= 1;
    }
    else
    {
        currentHP -= damage - speed/4;
    }
}

/*
*	reset()
*
*	Restores a fighter's current hit points to its maximum hit points.
*
*	Robot:
*	Also restores a Robot's current energy to its maximum value (which is 2 times its magic).
*	Also resets a Robot's bonus damage (calculated when a Robot uses its ability) to 0.
*
*	Archer:
*	Also resets an Archer's current speed to its original value.
*
*	Cleric:
*	Also restores a Cleric's current mana to its maximum value (which is 5 times its magic).
*/
void Fighter::reset()
{
    currentHP = maxHP;
}

/*
*	regenerate()
*
*	Increases the fighter's current hit points by an amount equal to one sixth of
*	the fighter's strength.  This method must increase the fighter's current hit
*	points by at least one.  Do not allow the current hit points to exceed the
*	maximum hit points.
*
*	Cleric:
*	Also increases a Cleric's current mana by an amount equal to one fifth of the
*	Cleric's magic.  This method must increase the Cleric's current mana by at
*	least one.  Do not allow the current mana to exceed the maximum mana (again, 5 times its magic).
*/
void Fighter::regenerate()
{
    if ((maxHP - currentHP) < (strength / 6) || (maxHP - currentHP) < 1)
    {
        currentHP = maxHP;
    }
    else if ((strength / 6) < 1)
    {
        currentHP++;
    }
    else
    {
        currentHP += strength / 6;
    }
}
