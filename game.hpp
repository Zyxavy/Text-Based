#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <string>
#include <windows.h> 
#include <cstdlib>   
#include <ctime>
#include <thread>
#include <chrono>
#include <string>

using namespace std;

//Global Variables
    bool onBattle = false;
    bool onScene = false;
//items
    bool TotemOfDagrash = false; 

//

// Base Player class
class Player {
public:
    int maxHealth, currentHealth, damage, defense, speed, level = 1, levelPoints = 0, hpPotion = 5;
    double coins = 0.1;
    string type, name, art;

    Player() : currentHealth(100), maxHealth(100) {}

    int getHealth() const { return currentHealth; }
    int getMaxHealth() const { return maxHealth; }
};

// Base Enemy class
class Enemy {
public:
    int maxHealth, currentHealth, damage, defense, speed, exp, difficulty;
    string name, type, art, weakness;
    int *dmgPtr;

    Enemy() : currentHealth(100), maxHealth(100) {}
    //getters
    int getHealth() const { return currentHealth; }
    int getMaxHealth() const { return maxHealth; }
    //setters
    void setDamage(int damage) {this->damage += damage;}
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
    static int baseDamage;
    static int baseHealth;
    static int baseDefense;
    static int baseSpeed;
    static int baseExp;
    
    Goblin();  
};

class Witch : public Enemy {
public:
    static int baseDamage;
    static int baseHealth;
    static int baseDefense;
    static int baseSpeed;
    static int baseExp;

    Witch();  
};

class WereWolf : public Enemy {
public:
    static int baseDamage;
    static int baseHealth;
    static int baseDefense;
    static int baseSpeed;
    static int baseExp;

    WereWolf();  
};

class Skeleton : public Enemy{
public:
    static int baseDamage;
    static int baseHealth;
    static int baseDefense;
    static int baseSpeed;
    static int baseExp;

    Skeleton();
};

class Dummy : public Enemy{
    public:
        Dummy();
};

//functions
void battle(Player &player, Enemy &enemy);
void performAttack(Player &player, Enemy &enemy);
void selectHero(Player *&player);
void inventory(Player &player);
string createHealthBar(int currentHealth, int maxHP, int barLength = 10);
void defend(Player &player, Enemy &enemy);
string items(Player &player);
void getExp(Player &player, Enemy &enemy);
string expBar(int levelPoints, int barLength = 10);
void coinDrop(Player &player, Enemy enemy);
void hpDrop(Player &player, Enemy &enemy);
void tutorial(Player &player, Enemy &enemy);
void typeWriterEffect(const std::string &text, int delay);
void increaseDmgOfEnemies(Enemy &enemy);
void setupConsoleWindow();
int playMusic(const std::wstring& musicFile);
void playBattleMusic();

#endif // GAME_HPP