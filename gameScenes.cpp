#include "gameFunctions.cpp"

Player *chosenHero;
//Goblin goblin;
//Witch witch;
//WereWolf wereWolf;
//Skeleton skeleton;

void tutorial(Player &player, Enemy &enemy){
    int action;
    cout << "\n\nWELLCOME TO THE TUTORIAL!!!\n\n";
    Sleep(1000);

     cout << player.art << '\n' << R"(
     __      ________ _____   _____ _    _  _____ 
    \ \    / /|  ____|  __ \ / ____| |  | |/ ____|
     \ \  / / | |__  | |__) | (___ | |  | | (___  
      \ \/ /  |  __| |  _  / \___ \| |  | |\___ \ 
      \  /   | |____| | \ \ ____) | |__| |____) |
       \/    |______|_|  \_|_____/ \____/|_____/ )"<<
    '\n' << enemy.art; 
    Sleep(1000);
    cout << "\n\nTo start, try Attacking your enemy (Enter 1)\n\n";
    Sleep(1500);

    cout << player.name << " Health: " << createHealthBar(player.getHealth(), player.getMaxHealth()) << '\n';
    cout << enemy.name << " Health: " << createHealthBar(enemy.getHealth(), enemy.getMaxHealth()) << '\n';
    cout << "______________________________________________________________________\n";
    cout << "1. Basic Attack ";
    cout << "\n____________________________________________________________________\n\n";
    cin >> action;
    performAttack(player, enemy);

    Sleep(500);
    cout << "\n\nWatch out, After attacking the enemy will attack back!\n\n";
    Sleep(1000);
    enemyAttack(enemy, player);
    Sleep(1000);

    cout << player.name << " Health: " << createHealthBar(player.getHealth(), player.getMaxHealth()) << '\n';
    cout << enemy.name << " Health: " << createHealthBar(enemy.getHealth(), enemy.getMaxHealth()) << '\n';
    cout << "\n\nPhew! now try Defending (Enter 2)\n" << "Note there is a 50'%' chance of successfully defending and may also counter-attack!\n\n";
    Sleep(1000);
    cout << "______________________________________________________________________\n";
    cout << "2. Defend ";
    cout << "\n____________________________________________________________________\n\n";
    cin >> action;
    defend(player, enemy);

    Sleep(1000);
    cout << "\nTake note that when blocking successfuly you may make lessened damage.\n\n";
    Sleep(2000);
    cout << player.name << " Health: " << createHealthBar(player.getHealth(), player.getMaxHealth()) << '\n';
    cout << enemy.name << " Health: " << createHealthBar(enemy.getHealth(), enemy.getMaxHealth()) << '\n';
    cout << "Now open your Inventory and drink some health potions! (Enter 3)\n";
    Sleep(2000);
    cout << "______________________________________________________________________\n";
    cout << "3. Inventory ";
    cout << "\n____________________________________________________________________\n\n";
    cin >> action;
    inventory(player);

    Sleep(1000);
    cout << "\n\nOne thing to note is that the amount of hp you will receive from drinking is random...\n";
    Sleep(1000);
    cout << "Also you can obtain potions and coins from killing and looting your enemies.\n";
    Sleep(1000);
    cout << "You might encounter unkillable enemies, and that's fine.\n";
    Sleep(1000);
    cout << "You can always run away (Enter 4)\n";
    Sleep(1000);
    cout << "Take note that there is only a 30'%' chance of running away!\n\n";
    Sleep(2000);
    cout << "______________________________________________________________________\n";
    cout << "4. Run Away ";
    cout << "\n____________________________________________________________________\n\n";
    cin >> action;

    cout << "Successully ran away!\n";
    Sleep(700);
   
    cout << "Well done! you've completed the tutorial!\n\n\n";
    Sleep(3000);

    player.currentHealth = player.maxHealth;
    player.hpPotion += 4;
}


void scene2(){
    char act;

    cout << "\n\n\n\n\n\n________________________________________________________________________________________________________________________\n\n";
    cout << "The " << chosenHero->name << " awakens on a soft bed of moss beneath a towering canopy of ancient trees\n" <<
        "Shafts of sunlight pierce through the leaves, casting dappled patterns on the forest floor.\n\n";
    Sleep(2000);

    cout << "The air hums with the sound of distant creatures, and a faint trail of smoke rises to the east.\n\n";
    Sleep(2000);

    cout << "A mysterious voice echoes in the hero's mind, urging them to seek the village of Elderglen.\n\n";
    Sleep(2000);

    cout << "It's the last bastion of humanity near the cursed lands of Ebon Hollow, where dark creatures emerge every night.\n\n";
    Sleep(2000);

    cout << "With no memory of how they arrived in the forest, the hero begins their journey toward destiny.\n\n";
    cout << "________________________________________________________________________________________________________________________\n";

    cout << "Enter any key to continue: ";
    cin >> act;

}

void scene3(){
    int act;
    Goblin goblin1;
    Goblin goblin2;
    Goblin goblin3;

    cout << "\n\n\n\n\n\n________________________________________________________________________________________________________________________\n\n";
    cout << "As the hero ventures through the woods, they encounter their first foes: Goblins looting a wrecked caravan.\n\n";
    Sleep(2000);

    do{
        cout << "What will the hero do?\n" << "1. Attack the Goblins  | 2. Take a detour\n:";
        cin >> act;
    } while(act > 2 || act < 1);

    switch(act){
        case 1:
            cout << "\n\n\n\n\n\n________________________________________________________________________________________________________________________\n\n";
            cout << "The " << chosenHero->name << " engages in combat with the Goblins!!";
            Sleep(1000);
            battle(*chosenHero, goblin1);
            Sleep(500);
            cout << "The " << chosenHero->name << " manages to kill one goblin, but soon many more were alerted and rushed to attack.\n\n";
            Sleep(2000);
            battle(*chosenHero, goblin2);
            Sleep(500);
            cout << "The remaining Goblins ran away in fright!\n\n";
            Sleep(1000);
            cout << "You found a note on the caravan and a map which leads to a village.\n";
            Sleep(500);
            cout << "The note contains a plead for help...\n";
            Sleep(500);
            cout << "The village seems to be under attack\n\n";
            cout << "What will the hero do?\n" << "1. Help the village  |  2. Continue on your journey\n:";
            cin >> act;
            break;

        case 2:
            cout << "\n\n\n\n\n\n________________________________________________________________________________________________________________________\n\n";
            cout << "You silently avoided the Goblins...";
            Sleep(1000);
            cout << "But you soon had a feeling...\n"; Sleep(500); cout << "Like you missed something.\n\n"; Sleep(5000);
            cout << "Enter any key: ";
            cin >> act;
            break;
    }    
}
