#ifndef GAME_CLASSES_HPP
#define GAME_CLASSES_HPP

#include <iostream>
#include <string>
#include <windows.h> 
#include <cstdlib>   
#include <ctime>

using namespace std;


// Base Player class
class Player {
public:
    int maxHealth, currentHealth, damage, defense, speed, level = 1, levelPoints = 0, hpPotion = 5;
    double coins = 0.1;
    string type, name, art;
    string items;

    Player() : currentHealth(100), maxHealth(100) {}

    int getHealth() const { return currentHealth; }
    int getMaxHealth() const { return maxHealth; }
};

// Base Enemy class
class Enemy {
public:
    int maxHealth, currentHealth, damage, defense, speed, exp, difficulty;
    string name, type, art;

    Enemy() : currentHealth(100), maxHealth(100) {}

    int getHealth() const { return currentHealth; }
    int getMaxHealth() const { return maxHealth; }
};

class Knight : public Player {
public:
    Knight(); 
};

class Wizard : public Player {
public:
    Wizard(); 
};

class Thief : public Player {
public:
    Thief(); 
};

class Goblin : public Enemy {
public:
    Goblin();  
};

class Witch : public Enemy {
public:
    Witch();  
};

class WereWolf : public Enemy {
public:
    WereWolf();  
};

class Skeleton : public Enemy{
    public:
        Skeleton();
};

class Dummy : public Enemy{
    public:
        Dummy();
};

#endif // GAME_CLASSES_HPP