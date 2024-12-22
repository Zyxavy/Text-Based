#include "gameFunctions.cpp"

Player *chosenHero;
//Goblin goblin;
//Witch witch;
//WereWolf wereWolf;
//Skeleton skeleton;

//declarations
    void scene3A();

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
    cout << "Enter any key to cotinue: ";
    cin >> action;

    player.currentHealth = player.maxHealth;
    player.hpPotion += 4;
}

void scene2(){
    playMusic(L"Music/forestBGM.wav");
    onScene = true;
    char act;
    int delay = 10;

    cout << "\n\n\n\n\n\n________________________________________________________________________________________________________________________\n\n";
    string story = 
        "The " + chosenHero->name + " awakens on a soft bed of moss beneath a towering canopy of ancient trees\n"
        "Shafts of sunlight pierce through the leaves, casting dappled patterns on the forest floor.\n\n"
        "The air hums with the sound of distant creatures, and a faint trail of smoke rises to the east\n\n"
        "A mysterious voice echoes in the hero's mind, urging them to seek the village of Elderglen\n\n"
        "It's the last bastion of humanity near the cursed lands of Ebon Hollow, where dark creatures emerge every night.\n\n"
        "With no memory of how they arrived in the forest, the hero begins their journey toward destiny.";

    typeWriterEffect(story, delay);
    cout << "________________________________________________________________________________________________________________________\n";

    cout << "Enter any key to continue: ";
    cin >> act;

}

void scene3(){
    playMusic(L"Music/forestBGM.wav");
    onScene = true;
    int act;
    int delay = 10;
    Goblin goblin1;
    Goblin goblin2;
    Goblin goblin3;

    //stories
    string story1 = "As the hero ventures through the woods, they encounter their first foes: Goblins looting a wrecked caravan.\n\n";
    string story2 = "The " + chosenHero->name + " engages in combat with the Goblins!!\n\n";
    string story3 = "The " + chosenHero->name + " manages to kill one goblin, but soon many more were alerted and rushed to attack.\n\n";
    string story4 = "The remaining Goblins ran away in fright!\n\n";
    string story5 = "You found a note on the caravan and a map which leads to a village.\n";
    string story6 = "The note contains a plead for help...\n";
    string story7 = "The village seems to be under attack\n\n";
    string story8 = "You silently avoided the Goblins...";
    string story9 = "But you soon had a feeling... Like you missed something.";

    cout << "\n\n\n\n\n\n________________________________________________________________________________________________________________________\n\n";
    typeWriterEffect(story1, delay);
    Sleep(1000);

    do{
        cout << "What will the hero do?\n" << "1. Attack the Goblins  | 2. Take a detour\n:";
        cin >> act;
   

        switch(act){
            case 1:
                onScene = false;
                cout << "\n\n\n\n\n\n________________________________________________________________________________________________________________________\n\n";
                typeWriterEffect(story2, delay);
                Sleep(1000);
                battle(*chosenHero, goblin1);
                Sleep(500);

                typeWriterEffect(story3, delay);
                Sleep(1000);
                battle(*chosenHero, goblin2);
                battle(*chosenHero, goblin3);
                Sleep(1000);

                typeWriterEffect(story4, delay);
                Sleep(500);

                typeWriterEffect(story5, delay);
                Sleep(500);

                typeWriterEffect(story6, delay);
                Sleep(500);
                onBattle = false;
                playMusic(L"Music/forestBGM.wav");

                typeWriterEffect(story7, delay);
                cout << "What will the hero do?\n" << "1. Help the village  |  2. Continue on your journey\n:";
                cin >> act;

                if(act == 1) { scene3A(); }
                break;

            case 2:
                char key;
                cout << "\n\n\n\n\n\n________________________________________________________________________________________________________________________\n\n";
                typeWriterEffect(story8, delay);
                Sleep(1000);
                typeWriterEffect(story9, delay);
                cout << "Enter any key to continue: ";
                cin >> key;
                break;
            default:
                cout << "Invalid operation, try again!\n";
                cin.clear();
                cin.ignore(123, '\n');
            }
    } while(act > 2 || act < 1);    
}

void scene3A(){
    onScene = true;
    char act;
    int delay = 10;

    Goblin goblin1;
    Goblin goblin2;

    //stories
    string story1 = "You followed the map and later arrived at the village\n\n";
    string story2 = "You saw the villagers defending their homes from the horde of Goblins!\n\n";
    string story3 = "Right when you were about to arrive at the village, a Goblin saw you and alarmed the horde!\n\n";
    string story4 = "\nFortunately, a villager saw you and quickly rushed to help\n\n";
    string story5 = "Villager: You there! Quick, over here! We need your help! The Goblins... they're everywhere! They're burning our homes, attacking our people!\n\n";
    string story6 = "Villager: Thank the heavens you're here. I saw you coming from the woods and knew you'd be strong enough to help us. Here, " 
                    "take this healing potionand a vial of Goblin Repellent Oil. It weakens their armor!\n\n";

    onScene = false;
    cout << "\n\n\n\n\n\n________________________________________________________________________________________________________________________\n\n";
    typeWriterEffect(story1, delay);
    Sleep(1000);

    typeWriterEffect(story2, delay);
    Sleep(1000);

    typeWriterEffect(story3, delay);
    Sleep(1000);
    battle(*chosenHero, goblin1);
    onBattle = false;
    
    
    Sleep(1000);

   typeWriterEffect(story4, delay);
    Sleep(1000);

    
}

void scene4(){
    cout << "ESCSD!";
}