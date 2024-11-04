#include <iostream>
#include "game_classes.h"
#include "gameClasses.cpp"
#include <windows.h> 
#include <cstdlib>   
#include <ctime>

using std::cout;
using std::cin;
using std::string;
using std::endl;


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


int main(){
    Player *chosenHero;
    Goblin goblin;
    Witch witch;
    WereWolf wereWolf;
    Skeleton skeleton;

        //Scene1
        int scene1 = 2;
    do{
        scene1 = 2;
        selectHero(chosenHero);
        cout << "Continue?: 1: yes | 2. no: ";
        cin >> scene1;
        if(!scene1) scene1 = 2;
    } while(scene1 != 1);


    battle(*chosenHero, goblin);
    battle(*chosenHero, witch);
    chosenHero->levelPoints += 100;
    battle(*chosenHero, wereWolf);
    battle(*chosenHero, skeleton);

    delete chosenHero;
    return 0;
} 

void hpDrop(Player &player, Enemy &enemy){
    srand(time(0));
    if(rand() % 2 == 0){
        int potions = rand() % 3;
        player.hpPotion += potions;
        cout << "Obtained " << potions << " hp Potions!\n";
        Sleep(400);
    }
}

void coinDrop(Player &player, Enemy enemy){
    int act;
    srand(time(NULL));
    double coins = (rand() % 20 + 1) * enemy.difficulty + 1.0;
    player.coins += coins;
        
    cout << enemy.name << " dropped " << coins << " coins!\n";
    do{
        cout << "Continue? 1.Yes: ";
        cin >> act;
    } while(act != 1);
 
}

string expBar(int levelPoints, int barLength){
    int expUnits = (levelPoints * barLength) / 100;
    string levelBar = "{";

    for(int i = 0; i < expUnits; i++){
        levelBar += "[]";
    }

    for(int i = expUnits; i < barLength; i++){
        levelBar += "--";
    }

    levelBar += "} " + to_string(levelPoints) + "/" + to_string(100);
    return levelBar;
}

void getExp(Player &player, Enemy &enemy){
    srand(time(NULL));

        int expPoints = (rand() % enemy.exp + 1) + (rand() % 20 + 1);
        player.levelPoints += expPoints;

        cout << "Got " << expPoints << " experience points from killing " << enemy.name << '\n';
        Sleep(700);

        if(player.levelPoints > 100){
            player.level++;
            player.levelPoints = 0;
            player.damage += player.level;
            player.defense += player.level;
            player.maxHealth += player.level;
            player.speed += player.level;

            cout << player.name << " leveled up!\n";
            Sleep(500);
            cout << player.name << " is now level " << player.level << '\n';
            Sleep(350);
            cout << "Damage has been increased to -> " << player.damage << '\n';
            Sleep(350);
            cout << "Defense has been increased to -> " << player.defense << '\n';
            Sleep(350);
            cout << "Health has been increased to -> " << player.maxHealth << '\n';
            Sleep(350);
            cout << "Speed has been increased to -> " << player.speed << '\n';
            }

}

void selectHero(Player *&player){
    int heroSelect = 0;
    cout << "\tWelcome!!!!\n\tChoose your Hero:\n";
    Sleep(1400);
    do{
    cout << R"(
         Knight                              Wizard                           Thief
      _,.                                    ____                           .--._
    ,` -.)                                 .'* *.'                       ((/---._)
   ( _/-\\-._                           __/_*_*(_                         (_/Q Q )
  /,|`--._,-^|            ,            / _______ \                        / |c  /
  \_| |`-._/||          ,'|          _\_)/___\(_/_                     /- \.-,-'-,.__
    |  `-, / |         /  /         / _((\- -/))_ \                    \--   o---o --\
    |     || |        /  /          \ \())(-)(()/ /                     \__, H---H( --\
     `r-._||/   __   /  /            ' \(((()))/ '                          \\--\-\__-\
 __,-<_     )`-/  `./  /            / ' \)).))/ ' \                         \\--\ -/\_/)
'  \   `---'   \   /  /            / _ \ - | - /_  \                        \o-o--\ ((\
    |           |./  /            (   ( .;''';. .'  )                       /       '._
    /           //  /             _\"__ /    )\ __"/_                     /    _/_    '-.
\_/' \         |/  /                \/  \   ' /  \/                       |   /   '-._   |_
 |    |   _,^-'/  /                  .'  '...' ' )                         |___|       \__[)|
 |    , ``  (\/  /_                   / /  |  \ \                           |_|          /  |
  \,.->._    \X-=/^                  / .   .   . \                         /  )          '-'
  (  /   `-._//^`                   /   .     .   \                       (__/"
   `Y-.____(__}                    /   /   |   \   \    
    )" << endl;

        cout <<  " 1. Knight  |  2. Wizard  |  3. Thief :";
        cin >> heroSelect;
        Sleep(1000);
        
        switch (heroSelect)
        {
        case 1:{
            player = new Knight();
            cout << player->art;
            cout << "\nA valiant Knight stands ready for battle!" << endl;
            Sleep(500);
            break;
        }
        case 2:{
            player = new Wizard();
            cout << player->art;
            cout << "\nA mystical Wizard emerges from the arcane realm!" << endl;
            Sleep(500);
            break;
        }
        case 3:{
            player = new Thief();
            cout << player->art;
            cout << "\nA cunning Thief emerges from the shadows!" << endl;
            Sleep(500);
            break;
        }
        default:
            cout << "Invalid Selection, try again!\n";
            cin.clear();
            cin.ignore(123, '\n');

            Sleep(500);
            continue;
        }
        break;
    }while(heroSelect > 3 || heroSelect < 1);

    cout << "\tYou have chosen the " << player->name << "!" << endl;
}

void performAttack(Player &player, Enemy &enemy){
    int damage = player.damage - enemy.defense/10;
    if(damage < 0){
        damage = 0;
    }
    enemy.currentHealth -= damage;
    cout << player.name << " attacks the " << enemy.name << "!\n";
    Sleep(500);
    cout << enemy.name << " took " << damage << " damage!\n\n";
    Sleep(500);
}

void enemyAttack(Enemy &enemy, Player &player){
    int damage = enemy.damage - player.defense/10;
    if(damage < 0){
        damage = 0;
    }
    player.currentHealth -= damage;
    cout << enemy.name << " attacks the " << player.name << "!\n";
    Sleep(500);
    cout << player.name << " took " << damage << " damage!\n\n";   
    Sleep(500);
}

void battle(Player &player, Enemy &enemy) {
    int action, damage;
    srand(time(NULL));
    cout << player.art << '\n' << R"(
  __      ________ _____   _____ _    _  _____ 
 \ \    / /|  ____|  __ \ / ____| |  | |/ ____|
  \ \  / / | |__  | |__) | (___ | |  | | (___  
   \ \/ /  |  __| |  _  / \___ \| |  | |\___ \ 
    \  /   | |____| | \ \ ____) | |__| |____) |
     \/    |______|_|  \_|_____/ \____/|_____/ )"
    << '\n' << enemy.art; 

    Sleep(500);
    cout << player.name << " Encountered a " << enemy.name << endl;
    while(player.currentHealth > 0 && enemy.currentHealth > 0)
    {
        cout << player.name << " Health: " << createHealthBar(player.getHealth(), player.getMaxHealth()) << '\n';
        cout << enemy.name << " Health: " << createHealthBar(enemy.getHealth(), enemy.getMaxHealth()) << '\n';
        cout << "______________________________________________________________________\n";
        cout << "1. Basic Attack |  2. Defend  |  3. Inventory  | 4. Run away: | 5.Quit ";
        cout << "\n____________________________________________________________________\n\n";
        cin >> action;

        switch (action)
        {
        case 1:
            if(player.speed > enemy.speed){
                performAttack(player, enemy);
                
                if (enemy.currentHealth <= 0) {
                    cout << enemy.name << " has been defeated!" << endl;
                    getExp(player, enemy);
                    hpDrop(player, enemy);
                    coinDrop(player, enemy);
                    break;
                }

                enemyAttack(enemy, player);

                if(player.currentHealth <= 0){
                    cout << player.name << " Died!!\n";
                    exit(0);
                }
                break;
            }

            else{
                Sleep(500);
                enemyAttack(enemy, player);

                if(player.currentHealth <= 0){
                    cout << player.name << " Died!!\n";
                    exit(0);
                }

                performAttack(player, enemy);
                
                if (enemy.currentHealth <= 0) {
                    cout << enemy.name << " has been defeated!" << '\n';
                    getExp(player, enemy);
                    hpDrop(player, enemy);
                    coinDrop(player, enemy);
                    break;
                }
                break;
            }
        case 2:
            defend(player, enemy);
            break;
        case 3:
                inventory(player);
            break;
        case 4:
            if(rand() % 100 < 30 == 0){ // 30% chance of running away
                cout << "Successully ran away!\n";
                Sleep(700);
                return;
            }
            cout << "Failed to run away!\n";
            Sleep(500);
            damage = enemy.damage - player.defense/10;
            player.currentHealth -= damage;
            cout << enemy.name << " inflicted " << damage << " damage!\n\n";

             if(player.currentHealth < 0 ){
                cout << player.name << " Died attempting to flee!\n";
                exit(0);
            }

            Sleep(500);
            break;
        case 5:
            exit(0);
        default:
            cout << "Invalid operation, try again!\n";
            cin.clear();
            cin.ignore(123, '\n');
            break;
        }
    }
}

string createHealthBar(int currentHealth, int maxHP, int barLength){
    int hpUnits = (currentHealth * barLength) / maxHP;
    string healthBar = "{";

    for(int i = 0; i < hpUnits; i++){
        healthBar += "[]";
    }

    for(int i = hpUnits; i < barLength; i++){
        healthBar += "--";
    }

    healthBar += "} " + to_string(currentHealth) + "/" + to_string(maxHP);
    return healthBar;
}

void inventory(Player &player){
    srand(time(NULL));

    int action;
   
    cout << "\n\n" << R"( 
    ___ _   ___     _______ _   _ _____ ___  ______   __
    |_ _| \ | \ \   / | ____| \ | |_   _/ _ \|  _ \ \ / /
    | ||  \| |\ \ / /|  _| |  \| | | || | | | |_) \ V / 
    | || |\  | \ V / | |___| |\  | | || |_| |  _ < | |  
    |___|_| \_|  \_/  |_____|_| \_| |_| \___/|_| \_\|_|  )" << "\t" << player.art << endl;

    do{
        cout << "Health: " << "\t\t" << createHealthBar(player.getHealth(), player.getMaxHealth()) << "\n";
        cout << "Experience: " << "\t\t" << expBar(player.levelPoints) << '\n';
        cout << "Coins: " << player.coins << "\n";

        cout << "1.HEAl  | 2. ITEMS  | 3.Exit| \n";
        cin >> action;

        switch(action){
            case 1:
                cout << "Health potions: " << player.hpPotion << '\n';
                Sleep(500);
                    if(player.currentHealth > player.maxHealth){
                        cout << "Already at max health!\n";
                        break;
                    }

                    if(player.hpPotion > 0) {
                        int hp = rand() % 30 + 1;
                        player.currentHealth += hp;
                        player.hpPotion --;
                        cout << "Drinking...\n";
                        Sleep(500);
                        cout << "Restored " << hp << " Health points.\n\n";
                        Sleep(500);
                    } else{
                        cout << "No HP Potion available!\n\n";
                        Sleep(500);
                    }
                break;
            case 2:
                // inventory
                break;
            default:
                cout << "Invalid!\n";
                cin.clear();
                cin.ignore(123, '\n');
                break;
        }

    } while (action != 3);

}

void defend(Player &player, Enemy &enemy){

    int damage;
    srand(time(NULL));

     if(rand() % 100 < 50 == 0){ // check if defended
                cout << "Defended Successfully!\n";
                Sleep(500);
                damage = rand() % enemy.damage - player.defense/10;

                if(damage < 0){
                    damage = 0;
                }

                player.currentHealth -= damage;
                cout << enemy.name << " Inflicted " << damage << " damage!\n\n";
                Sleep(500);

                if(rand() % 100 > 50 == 0){ // check if countered
                    cout << "Countered Successfully!!\n";
                    damage = rand() % player.damage - enemy.defense/10;

                    if(damage < 0){
                    damage = 0;
                    }

                    cout << enemy.name << " took " << damage << " damage!\n\n";
                    enemy.currentHealth -= damage;
                    Sleep(500);
                }
            } else{
                cout << "Failed to defend!\n";
                Sleep(500);
                damage = enemy.damage - player.defense/10;
                player.currentHealth -= damage;
                cout << enemy.name << " inflicted " << damage << " damage!\n\n";
                Sleep(500);
            }

            if(player.currentHealth < 0 ){
                cout << player.name << " Died a horrible death!\n";
                exit(0);
            }
            else if(enemy.currentHealth < 0){
                cout << enemy.name << " Succumbed to it's injuries!\n";
            }
}

string items(Player &player){
    return 0;
}
