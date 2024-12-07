#ifndef GAME_FUNCTIONS_HPP
#define GAME_FUNCTIONS_HPP

#include <iostream>

//Function Declarations
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

#endif // GAME_FUNCTIONS_HPP