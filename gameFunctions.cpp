#include "gameClasses.cpp"

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
    cout << "Enter any key to continue: ";
    cin >> act;
 
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
   `Y-.____(__}                    /   /   |      \    
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

    if(damage < 0) {damage = 0;}
    if(enemy.weakness == "TotemOfDagrash" && TotemOfDagrash == true) {damage += 20;} // Goblin weakness

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
    if(onBattle == false) {playBattleMusic();}
    int action, damage;
    onBattle = true;


    srand(time(NULL));

    cout << player.art << "      " << R"(
  __      ________ _____   _____ _    _  _____ 
 \ \    / /|  ____|  __ \ / ____| |  | |/ ____|
  \ \  / / | |__  | |__) | (___ | |  | | (___  
   \ \/ /  |  __| |  _  / \___ \| |  | |\___ \ 
    \  /   | |____| | \ \ ____) | |__| |____) |
     \/    |______|_|  \_|_____/ \____/|_____/ )"
    << "    " << enemy.art; 

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
            if(enemy.difficulty == 6) {
                cout << "Cannot run away from Boss monster!\n";
                break;
            }

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
        cin.clear();
        cin.ignore(123, '\n');
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
        cout << "Level: " << player.level << "\n";
        cout << "Coins: " << player.coins << "\n";
        cout << "Current Hp potions: " << player.hpPotion << "\n";

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
                        int hp = (rand() % 30 + 1) + 10;
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
                char ext;
                if(TotemOfDagrash == true){ cout << " | Totem of Dagrash | Provides bonus damage to Goblin type enemies.\n";}

                cout << "\n\nEnter any key to exit: ";
                cin >> ext;
                break;
            case 3:
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
                damage = 0;

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

void typeWriterEffect(const std::string& text, int delay) {
    for (char c : text) {
        cout << c << flush;  // Print each character and flush the output
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));  // Pause for the specified duration
    }
    cout << endl;  
}

void increaseDmgOfEnemies(){
    Goblin::baseDamage += 15;  // Permanently increases base damage for all future Goblin instances
    Witch::baseDamage += 13;
    WereWolf::baseDamage += 17;
    Skeleton::baseDamage += 10;
}

void setupConsoleWindow() {
    SetConsoleTitleA("RP-GAME");

    HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect);
    
    // Resize window
    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 1500, 1000, TRUE);
}

int playMusic(const std::wstring& musicFile) {

    if(onScene == true && onBattle == true) { return 1;}

    PlaySoundW(NULL, NULL, 0);
    
    if (!PlaySoundW(musicFile.c_str(), NULL, SND_FILENAME | SND_ASYNC)) {
        std::wcerr << L"Error: Could not play " << musicFile << std::endl;
    } 

    return 0;
}

void playBattleMusic(){

    PlaySoundW(NULL, NULL, 0); // stop music

    if (!PlaySoundW(L"Music/battleBGM.wav", NULL, SND_FILENAME | SND_ASYNC)) {
        std::wcerr << L"Error: Could not play " << std::endl;
    } 

}