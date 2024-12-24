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
    cout << "Take note that there is only a 30'%' chance of running away and you can't run away from boss monsters!\n\n";
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

      string story = 
        "The " + chosenHero->name + " awakens on a soft bed of moss beneath a towering canopy of ancient trees\n"
        "Shafts of sunlight pierce through the leaves, casting dappled patterns on the forest floor.\n\n"
        "The air hums with the sound of distant creatures, and a faint trail of smoke rises to the east\n\n"
        "A mysterious voice echoes in the hero's mind, urging them to seek the village of Elderglen\n\n"
        "It's the last bastion of humanity near the cursed lands of Ebon Hollow, where dark creatures emerge every night.\n\n"
        "With no memory of how they arrived in the forest, the hero begins their journey toward destiny.";

    string art1 = R"(
&Xx+.:; ;:  ++$$$;;;: ;   .                                            .     ..:  ;$+:    :.X&&$x&$++.  Xxx    X&
&$ x      :+XX+$X$Xx;.       .;;::::                                        . .+$$&x    ;+X&$+$&$&&$xx+x;.    .+$
&X;++:;::++$$+$xX+$+;:x.: +X&$+    :                                       . ;;$&X +XX&XX  .;+;$$&&&&&&$&X+x  &X&
&$$$XxX&+::    :;:;&&&&&&&&$x:;    ::                                       :+X&+X    ::     :+;X$&&&&&$$$X++x$+X
&&&+&&&$;:       .;x&&&&&&&&+X+x+X:; ;.+                                    :+:     . .:+     x+X&&&$&&$$&&&$x:+;
$$;:xx&XX::x;+;:   :$&&$&$$:      :;:++                                           :  ;;      +;x$X&&&&&&$&+     X
&+      ;X&&&$&&XX:.x&&Xxx.     ::;;                                             ; :x+;::+++$$X&$&&&&+x&$+   .+ X
XX ;+ ...;;X&&&&&&$X&&&$&XX++;XX$;:.                                               ;;  .;xXXX++$&&&&XX&&X:::  .X&
&&&x&&;x::$$&&&&&$+$X$&$X&$x&x+:.:                                                             &&&$&$$&;X;$&x+&&&
++: x&&&&&&&&&$;$+Xx+;$X+;+;                                                               .:+xX&$&&$+.: :+&$&&&&
; : +&$;.x++X$x;$;:x;;$x+$X++  .                                                     ;    ;:;;$$XX&&&&&;x&&&+;$&&
 :+ +&XX:.+ X$++x.+X: $xx+;Xx;;  :                                                  :+      : +xXX$&&;+&X:; x+ xX
  ; X&xX    &&++;;;  ;$+;  :    .                                                   +x:      ;X;x$$&+ +&: .;.x;x&
    &$X+    XX;+:;    $x;.:             :                                           XX::        +$&&$ ;$   :     
    X$;;    $X;+      $X+              .X.                                         +x$+:        :;$&+ ;;         
    $$++    $+ ;      $X;               XX                           :             x+&x+        :+$&$ ;+         
    XX;;   :&; ;      $+;      ;:     ::&x;                         ;&            :X+X$&:       ;:+$$:;+         
    +$+;. :+$;.;    . X;:      ;;     :+&x+:  :                     +$:           .:Xxx$x:      ; xX&;;x  ;..    
:   xX+;;: X$: x:. ;x:$.:     :+x     ;X$X    +                    ;x$X:          :$X&$$      ..; x$X++X.:;  : : 
::  X&+ ++ X$; x.;;;X+& :     ;$+:   ;+X+$x: ;&;                    +&X:         .+&&$&&X; : :;;;.;$x++X$:+;. ;;+
 ; .X&x;+&+&$; ++$xX&X$.   : +&&$;;+ +&x&+:  ;&+                    :&x:    .    :;:XX&&$ :;;;:++ ;$$x++&+;: ;$ :
;::;&&+;x&&&X;.;X$xX+X$+.;:.:+x&$$+ .:+;$&x:;x&x                  :x$&+     ; :::;X&&&&X$++;;::+; :$&&+;&:+:+:X&X
&&&$&&x;x&$&X+ X&&XX&XX::+::;;+;&+X .+;&X&&X+x&+;                :XXX&$&x. ::+X++X$x&&$$&&&x;.:++.:X&&x:$:XX&$&$X
+XXX&&X:;&&&X;:;&$xXX&$:.X:;XxX&&$+++X$&+&$$+X&x;.            .  ;XX&$&X$:::+x+$x+$$&&&&&X;++;:;;.+$&&X;$$: &&Xx$
&$&+&&$+xx+&&;: &&X$&&&+:$&&+;&&&Xx;++x$&&$X$$&X.  ;.        +::.;+X$X&X;:+;X+x&;;&&+&&&&+X;X&;$X.:$$&$:$;X;:;$&:
XX+:+  : ++$&+:.X&&&&&&+:x&X;    ;+$$&X&x&$&XX&&++: ..  : . .+;;;$X&$&&&Xx:+x$X&$$X$&&&+;&&+  ;$x :X&&X;$$&&$+$X.
&$Xx;;  .x+&&$x+X&&&&&&.:+&&x: : .;&X  X&&X $&&&Xx+;:.;+;: :+X  +$&$&&&&X$;$&&&&&&&+:&X   ;; :X+; +&&&+x&:$x&&&X:
&$$;x +:;Xx&&&&+X&&: +X;$+&&$x++; ++:   +++XX&&$&X$X+::;X   X.;+x&&&&&+.XX:;; :+&X  ;X$; .;X X$& ++&$&$&&&&x:;&+$
$x;.X+:;;x x&$X&X;:xX$+;:+X&&$X$&x+&X;;:..;X+X++; ;X&&&&;;+xX$:;&$&&&X+x+X$.. ++$X   ;x;.;$&&:;X:+$&&&&+&&.$+ X&&
X+ .;x&& :&x&  :x+;+.;;&::; &&&$X;X&X$&&x$&&X.+X;$xx&$$&:;&&X.+:+X+X$+;$&x  .;: $$XX  $&&&&; +$&.x$. +XX&&x+ ;.&&
&X;;$::$x $:+++$;::;xX+:;:;$:+;+.::++x$X+;X;&$;x$xx+;$++;+;+X&&X&X+Xx$+++;x$&&X+$&&; ::.$x +;;x&$+x++ X ;;++;;&&&
&&&X;x;x&&$$; .X;.&XX&x+Xx$$&$;;; :+..;$XX$$X&X$X&&&;xXX+&&$xXX$xX+$X+&&&$+x+++X+ + x;;:;+++&+ ;++;;XX;x:::$;+$&&
+X&:++: :+;x:.; :;&;&+:$:+::+X&$X&x+:  .                                   :. ; .+.:;; .x$x $;;;+.:: xX++ :::X;:;
$+&&&;&&$&x$$.:$x+&XX++$&$X$: + ;x;:+:;.                                   ;:;; $;;++xX:  ++$X;   +$++:xxX:+:+:;.
$$$&&+;::.&;x&+.+:xXX&X$+;+X . .; X&+:.X   ::                           . :;++:;+$ ;.;&; +$;&:+   ;+++X;xX+ $+:;X
X++XX+X; x+:;X$+;X+X:X$;..:;$; X;X$x$$xx.+;;;                           ;xxX$;xX+$XxXxx x& ;xx+x +XX:::++:X&:XX+x
.;.+x&xxX+;&x;  X$X&&&+;X&:  X$&$:Xx:+&X$::++..::;:                . ..:;+$X;++ &X&:+$x$:X ;;+xx$$XXxX$&X+;$:.+::
Xx;;+Xx::+X+;+xXxXxX++$&+X&X$X+XX&$$X:x:;:.     :.                  : ::;x&&$x+&X;+X+X$X.:X;;++.X$X&XXx;; :x;; &x
 :$$Xx:+;;+x:xx:;XX++x  .;+   .::.    .                          .        .  +x&X&$x$;&$Xx+X+X++$&$x&;+$:xXX;+ &;
$xxxX;XX+:                                                                   .                  .:;;;+&X;::x$$x$+
                                                                                                      .: : ;:;+: )";

    cout << "\n\n\n\n\n\n________________________________________________________________________________________________________________________\n\n";
    cout << art1 << "\n\n";
    Sleep(1000);
    typeWriterEffect(story, delay);
    cout << "________________________________________________________________________________________________________________________\n";

    cout << "Enter any key to continue: ";
    cin >> act;

}

void scene3(){
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

    string art1 = R"(
     .................................................................................................................................................. 
 .................................................................................................................................................. 
 .............::...........................................................+********............................................................... 
 .............::........................................................-*#%@@@@@#**#*............................................................. 
 .............-.......+-:...................................-*+#%.....+*%@@@@@@@@@@#*#@%......*.................................................... 
 .............::....-+=:..................................-:-%@%=%*=:*%@@@@@@@@@@@@@@*%@#.......@-................................................. 
 ........-.........:::.:.....................................*.%@*..-=@@@@@@..@@@@@@@@*@@@.......@*-............................................... 
 ..:.::-+-..==:....===--:%*.....................................::...+@@@@@@@@@@@@@@@@%@@@#.......@%.......++:..................................... 
 :-=+*++=:.:++-....==.--.*:.....=+...............................#@.:.....@%%@@@@@@@@@%%@@*%......@@#..........@@@@#=.............................. 
 ....::..==-==-.::......:-+.....=##.......+..........................--=%+*@@@@@@@@@@@%%@@.:@%.....@%+...........@%..@*:........................... 
 .........::.:.:...-%+:...:+#....@#.......#:................-.=@@#+*@@%%#-.:=+@@@@@@@@#@@#...-%@%*#@@@............@%...##.......................... 
 ..............:.....#....%:......:......#..@............:-#*..*##-@@::+%...:.:@@@@@@@#@@=........@@@@-...........%@%....%*=....................... 
 .......................++...............@*....................*@@@@@@@...*#:#+:#@@@@%@@%:.::::::#@@@@%...........=@%-....@@@@..................... 
 ......................#..................@....................*@@@@*::.-@@@@@+:..*%#%%@%*-:::::#@@@@-:@*.........=@@%....*%....................... 
 ..............:#=.....-......................-=.................:-=+=..@@@@@@@@@@@%%@@@@@%*++*@@@@@:.-:-@@#-.....%@@@....@%:...................... 
 .............#:...........................:+###.....#*....=++....+*.:.@@@@@@@%#@@%@%@@@@@@@@@%%**#=...:.:.:#@@@%@@@@#::::@%%=-:................... 
 .........##*:%....:##+-...................**@@@@@.:........:..=+#....*@@@@%%%%@@@%%@@@@@@@@@@@@@@@#-**@%=-..:+--%@@@@+::+@@@***-.................. 
 .......-+##@@@@%%=.....................#@@@*@@#................+=+...@@%%%%%@%@@%%%@@@@@@@@%%%@@@@*-*@@@@@%@#=:#@@@+:=#@@@@#+-..:....:...:........ 
 ....+*#@@@@%%%+-.......................#@@@@@:...................-##@#%%#%%##%@@@%@%@@@@@@@%%@@@@@#-*@@#:..@@=#%@@+.....*@@@+=+==-:.-%%........... 
 ...-%%%%%+--..........................=*@@@@@*:................@%#%@@%%%%%##%@@@@%%#%@@@@@@@@@@@@@%%%+@@*+#@@+@@@@@@@***@@@@@@#**+++=#............ 
 ..#@@@%+-:.............................%+:@@@@@@::..:.........%@%%%@#%%%%@@%%@@@@%%##@%%@@@@@@%%%######%@@@@@*@@@@*%@@@@@%@%%%%@..+*#............. 
 ..@%%%+=-..................................+@%@*..............%@@%%%@@@%%##%%@@@@@@@@@@@@@@@@%#%@%*####%%@##%@@@@*%@@@#*+++#@@@@@#::=+-........... 
 ..%%%%**.....::-+#*:........................:#%..:-...........@@@@@%%%%%@@@@@@@@@@@@@@@@@@@@@%####%%###%%%@@@@%@%**%@@@@@@@@@@@%@@@@@%--+......... 
 ..#@%%%:...-=%%*.#%%%%=......................................#@@%%@@@@@@@@@@@@@@@@@@@@@@@@@@@@####@@@%%@%%%@@%%@@#%%%@@@%%*#@@@@%@@%*...-##%%*=... 
 ....=@@%%#*#%:........%@@+...................................@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%%##@@@%%@@%@@@@%@@@@%#%%#*#@@@@@@@@@%+.#%@@@@@%%%## 
 :..........-...............:...................................+..@@@@@@@@@@@@@@@@@@@@@@@@@@@%####%*#@@%%%@@@@@@@@@@@@@@%%@%%%@@@@%@.@@@%#@@@@@%%# 
 =-....-::.....................................................+++##%@@@@.......=@@@@@@@@%@@@@@%%##%#%###%@@@@@@@@@@@@@%%%@@@@@@%%@%#.@@@@@@@@@@%%% 
 +===+=---:-:...................................................:--===++###*#%@@@@@@%@%@%%=-*%@@@@@-......-+@@@@@@@@@@@@@%%@@@@@%%%%@.%@@@@@@@@@%@@ 
 *+****+++++=-::=#+.....=#%#=:-=+=-+###-..............................:-=++++***#@@@%##**#*-..:*+=-...:...:.:-:=@@@@@@@%%%%@@@@@%%@@...%%@@@%%@%%%% 
 **#*+=*+***+++%@%%%@@@@@@@@@%#*=*#+-++==++#@@@##..=...................::--====++***%%*......:+#***=-:--+=::=+*=*#%#%@@@%%%@@@@@%%%....=%=...@%+..- 
 #+*#*+==*==+==@@@@@@@+++#%%@%##%##******##*++==#@@@...............:---:-=======++====*+=::.....+#%##%##***====..:+*@@@@@@@@@@@@%#%.....#+.....%:.. 
 **++**+=====--%*--++----=%@%%@@#*#%%%#%@%%##*#*#%@@%.........:=-=-===+---+====+--+*+####%#*=::-:..=+###***-:.-...---:#@@@@@@@@@@@......=*.....**:. 
 *#**+####**==++--:...:.=@++%%@@#%%%@@@@@%%#*##%%@@@#-.....-=+==+++=--=-=+==+==+=++*+*%#**###***++++--++##+-===-+*#+:..:-#*#%%%%#..........-+.+++.. 
 #*****###*+++=+++:...:*@@@@@%%%@@@@@@@@@%%%#@@@@@@@%*=--====-:-:------:----=====-=++**+#=+*#%%#%#@****++*###+*+::=+-.:-+=#%##****#*=-.......==+... 
 ##*++++***##*-==:::.*@@@@@@@@@@@@@@@@@@@@@%*#@+@@@@+-.=-:-==.......-=---:..::::--:::=++*=-*+*#%###@*#@#*#%**%%**+==*#*==+**%%#*##+*%#%%%.......... 
 ###**++==+**+=----:#@@*+**#%%%%@@@@@*:.#@%%%##....-................::--::::........:=++##**#**+*##@@**@%#*+*@%#####+=**+==+#%%%#%@@%@%%%%%*==-.... 
 @%#*+++++=++==---::@%***==*##****%%@@*.+@@%%%#.....................:::::--:::...........-++**+=+*##@@+=@@+%%#%%@@@@*####****@@@@%%%@@@@%%%%%%%%%%# 
 %###*+**++*+===--=####**##%@%%%**#%@@@@+-@@@@%#+*-..............----=-----:::.......:*.#--.=+++++++*%@%@@@@##@@@@@%%%#####***%@@@@@%@@@%%%%%%@@@@% 
 @@%%%%#***+====+%%@@@@@@@@@@@@@%@@%%%%@@@@@@@@%#%##:...........-****+++=--:.........*@@@@..:::=++=+**@@@@@%#@@@@@@@@%%@@@%%%#%@%%@@@@@@@@%@@@@@@@% 
 @@@@@%%%****++*@@@@@@@@@@@@@@@@@@@@@%%%%@%:-@@@@@@@@@@@@@@@%%#*@@@@@@*%@@*@%:........#@@@@..:.::::-*@@@%@@@@@%###--=*%##%@@%%%@@#*#%@@@@@@@@@%@@@@ 
 @@@@@%#*####%##%#%@@@@@%+++#@@@@@@@@@@@@@#...:-+:-..........:-*%@@@@@@@@@@@@%%%%#....*@@@#..:-:..:--=@@@@%%%#*#%%#%%%%@@@@@@@@@@@@@@#%%@@@@@@@@@%% 
 @@@@@@@@@@@@@%###%@@@@#*##@@@@@@@+@@@@@@*-::-::..............::#@%=-=+#@@@@=-=#@@=...=@@@-.:.::.:.-=:@@###@@@@#***#%@@@*.+=#-+@@@@@@@###%@@@@@@@@@ 
 @@@@@@@@@@@@@%%%@@@@%%%%%@@@@@#===-----=::----::............::-%@+--*+*@@@%++==---::::@@@@=-:-:-====#@%%@%%@@@@@@%@%+*-=++.=%=+@@@@@@#######%@@@@@ 
 @@@@@@@@@@@@@@@@@@@@@@@@@@@@*+*++=====-=-------::.............*#-++=+#@@@%@*++**+-:-:.@@-@@=:---=*@#%%@@@@@@@@@@@@@@*=::=+@:%@@-%@@#***#**#%@@@@%% 
 @@@@@@@@@@%@@@@@@@@@@@@@%##*%%%**%###*#**==-==--+:.:..:...:::..-+++**%@%%@@**###*++--:@+=-@@%=-%@@%%@@@@@@%@@@@@@@@%%%%%%%@@+@@@@@@@*+****##%%@@@@ 
 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#*%#**###=======+=##+==+===:=-*=*#####%@@@%#*#%%%#*+===*=--+@@@@@@@@@@@@@@##*#@@@@@@@@@@@@@@@@@@@@@@@@@%####%@@@@@@ 
 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%#++===+*++######***%****##%@%%%###***%%##%###**+=+*++=+@@@@@@@@@@@%#****%@@@@@@@@@@@@@@@@@@@@@@@@@%%%@@@@@@@@ 
 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@%@@%%%#*+*+*****%%%##%%*###%#%%###*@@##%*##%%##%%%@%%###***#++*@@@@@@*******####%@@@@%%%@@@@@@@@@@@@@@@@@@@@%#@@@@@@@ 
 @@@@@@@@@@@@@@@@@@@@@@@@@@%@@@@@@#*######%%%%%*-:-++=++#%#%%@@@@%%@##%##*#####%%%%%%##%####*@@@@@@##%%####%%@@@@@@@@%@@@@@@@@@@@@@@@@@@@@%#%%@@@@@ 
 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%%%@#*=::::.......:-*+-:--+#%@@@@@@%#@%%%%###%#%%#%%@@%%%%##%@@@@@%%@@@@%@%%@@@@@@@@@@@@#######%%@@@@@%@@#@@@@@@@ 
 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%#*+..................:-=...:=*+*%@@@@%%@@%%%#*#%%%%%####%@@@@%%@@@@@@@@@@@@%@@@@@@@@@@@@@%%#%%%##%@@@@@@@@@@@@@@% 
 @@@@@@@@@@@@@@@@@@@@@@@@@@@%*+==-..................::=:.:--:::--=+**#@@@%@@@%%@@%%%@%###%%%%@@@@@@@@@@@@@@@@@@@@@@@@%@@@@@@%###%@%%%#@@@@@@@@@@@@@ 
 @@@@@@@@@@@@@@@@@@@@@@@%+--*+=..............-=--:............:-=--=**+%@@@@@@@@@@%@%%%###%%%%%@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%%#%%%%%%%##@@@@@@@@@@@ 
    )";

    cout << "\n\n\n\n\n\n________________________________________________________________________________________________________________________\n\n";
    cout << art1 << "\n\n";
    Sleep(1000);
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
    Goblin goblin3;

    //stories
    string story1 = "You followed the map and later arrived at the village\n\n";
    string story2 = "You saw the villagers defending their homes from the horde of Goblins!\n\n";
    string story3 = "Right when you were about to arrive at the village, a Goblin saw you and alarmed the horde!\n\n";
    string story4 = "\nFortunately, a villager saw you and quickly rushed to help\n\n";
    string story5 = "Villager: You there! Quick, over here! We need your help! The Goblins... they're everywhere! They're burning our homes, attacking our people!\n\n";
    string story6 = "Villager: Thank the heavens you're here. I saw you coming from the woods and knew you'd be strong enough to help us.\n Here, " 
                    "take this healing potion and a totem. It weakens their armor!\n\n";
    string story7 = "You recieved 5 healing potions and Totem of Dagrash!\n\n";
    string story8 = "Villager: Please follow me and help us defend the village.\n\n";
    string story9 = "You followed the villager to the western front of the village...\n\n";
    string story10 = "You saw a Giant Goblin, most likely an Ogre, commanding the horde of Goblins to attack the village.\n\n";
    string story11 = "Villager: leave the Goblins to us, please defeat the Ogre!!\n\n";
    string story12 = "Blood spilled, swords clatter, you witness Goblins chopping up villagers, and villagers killing Goblins...\n"
                     "As you charge towards the Ogre, you can't help but feel a sense of deep pity for the villagers.\n\n";
    string story13 = "You managed to injure the Ogre, but the Ogre quickly retreated behind the horde of Goblins.\n\n";
    string story14 = "Villager: Despicable!, quick, take the rest of my potions and leave the Goblins to us! you must defeat the Ogre!\n\n\n..."
                     "Obtained 7 healing potions.\n\n";
    string story15 = "You finally killed the Ogre, as the huge lifeless body falls, you see the horror in the eyes of the Goblins as they fled...\n\n";
    string story16 = "Villager: Thank you kind " + chosenHero->name + ", please accept this as a token of our gratitude, it may not be much, but it will aid you in your journey...\n\n";
    string story17a = "Knight recieved:\n\t Sturdy Iron Armor | +5 defense\n\t Sharp LongSword | +7 damage\n\t";
    string story17b = "Wizard recieved:\n\t Enchanted Robe | +5 defense\n\t Sturdy Magic Wand | +7 damage\n\t";
    string story17c = "Thief recieved:\n\t Cloak of deciet | +5 defense\b\t Sharp Dagger | +7 damage\n\t";
    string story18 = "Villager: You may rest here until you depart from your journey.....\n\n";
    string story19 = "After recuperating for a few days, you quickly set off towards the sunrise...\n\n";

    string art1 = R"(
                                             ..     ..                             .                
                                    .   .;.    .::..                          ;x$x+++.          
                                      . :.;;;;::+;+;:..:.                   .;&&&&&&$&$$x.      
                                   .  ;+:.:;++++x$$XXxXxx;                 x&&&&&&&&&&&&&&&&&:  
          ..:                    ..;+;;;;;;++x+::+X&$$$$Xx+.                ;&&&&&&&&x$&&&&&&X  
  +XX++XXX+&+          .        .+++;;;::;+xx:  ..x&&&&&&$$$x;:.             ;&&&&&&&+X&&&&&&x  
  +Xx++xxX&&X           .     .::;;++;;+XXX&X+::;X$&&&&&$$&&&&$x+.            .X&&&&&&xx$&&&&x  
  xx+++++&&&&:            ...:::::;xxXX$XX$&&x+;x$$&&&&&&&&$$XXXX;.   .         &&&&&&$x$$&&&x  
  XXx+xx&&&&&X             .Xx;;++X$$&&&&&&&$X&&&&&&&&&&&&&&&&&&$$   .           &&&&&&$X$Xx$x  
  ++;++&&&&&&&             ;X++;++x$&&&&&&&&&&&&$X&&&&&&&&&&&&&&&&+              &&&&$$&&x+xX+  
  &+::X&$&&&&&;            x++;;++X$&&&&&&&&&&&xx&&&&&&&&&&&&&&&&&&+            :&&&&;;++&&X$+  
  &&&&&&&$$&&&&+         .x$xx$$&&&&&&&&&&&&&X&&&&&&&&&&&&&&&&&&&&&X:    .      +&&&x$&&&&&&X;  
  &&&&&&&&&&&xx;        .XX$X$$XXXXX$$$X$&&&&&$$&&&&&&&&&&&&&&&&&&&.            $&&&&X+;;;X&&x  
  $&&&&&&&&&&       . .XxX$&&$&&&&&&&&$$&&$&&&&&&&&&&&&&&&&&&&&&&&&&X.         X&&&&;;:;;xx+x$  
  x&&&&&&&&&&&       xX+x$&&&&&&&&&&&&&&$$$$&&&&&&&&&&&&&&&&&&&&&&&&&&:       &&&&&XXx++x+++x+  
  +X$&&&&&&&&x ....x&x;+;x&&&&&&X $ +&&&&$$&&&&&&&&&&&&&&&&&X&&&&&&&&&&&X   .&&&&XXx+:;++;x&&x  
  ++x&&&&&&&X..;::+;x;;++&&&&&X.   + &&&&&&&&&&&&&&&&&&&&..   ;&&&&&&&&&&$. . ;x+;:+;::;+&&&&X  
  xxxxX$&&X$$+:;xx..Xx+x$&&&&+.       x&&&&&&&&&&&&&&&&&X.     &&&&&&&&&&&&Xxx+;;;;+:;X&&&&$&X  
  +x++;+X$$$$X+x$&:.xxxx&&&&&+   ..    x&&&&&&&&&&&&&&&&$...     +X&&&&&&&&x+xxX+;;&&&&&&&$&$x  
  $$X+xxxx+Xx:::;x;+++xXX&&&+;  .....+&&&&&&&&&&&&&&&&&&&&;...       ;.&&&++xX$&&&&&&&&&$&X++;  
  &&&&&&&XXXXx;;xXxxx++X$&X;.......:x$$$&&&&&&&&&&&&&&&&&&&$xx+.  .:::;+x$&&;x&&&&&&&$&$$XxxX+  
  &&&&&&&&&&&&&$$Xx&XxXXXX..:::...+Xx+x&&&&&&&&&&&&&&&&&&&&&&x;;...:+$$x:++XX&&&&&$xx;:;;+xx+;  
  &&&&&&&&&&&&&&&&&&x$&$xXx:;....+XXxX&&&&&&&&&&&&&&&&&&&&&&&&$x;::;x;+;::;;X&;:::::;;+++x;;+:  
  +x+X&&&&&&&&&&&X$X$&&+::x.....+x;;+X&&&&&&&&&&&&&&&&&&&&&$$&$X+:;+:;::x$x:+X:;+++X;;++:+xxX+  
  .+::x:;&&&&&&&:+$x&xX:.... .:+x++xxx$&&&&&&&+&&&&&&&&&&&$$$XXXx;++;:xXXXXXx+;;+X+;;;+xx++xx:  
  :+:;;:;$$$&&$X:X&$$;&x;:.....+xxXXXX&&&&&&;..;;&XxX$$$$&$$XxxX;:;;x$XXxxX+;+x++;+xXXXxX$&&&$  
  :;;+++:x$$$&$&$$&$x.:;&+.....xxXx&&$&&&$X;.....+xx;;XXX$XXX++++:;XXxxx+xx&&&&&&&&&&&&&&&&&&$  
  xxx$x$++X$$$$$$$&&X;:::;::.:+XXXX&&&&&X.:....  ...x..+xxxxx++++XXx;;;;::;;;;$&&&&&&&&&&&&&&$  
  &&&&&&&&XxX$&&&&&&&&+..:.;x$;.$$&&&&&&X......   ..;....:+x++++:;;:;;:.:xxxXXX&&&&$&&$$&&&&&$  
  &&&&&$&&&&&&&&$X$$$&&$;...;;..;$&&&$$&;......   ..  ....:;+;+;;:.::.:;+;;+;:Xx&$xXx+:+&&&&&x  
  &&&&&XX&&&&xx&$XxxXX$$&X::::...:x$$$$;. ..::. .         ..::;;:::;;x$;+XXX..:;++&&$+:;&&&&&+  
  &&&&&;:&&&&x+&&$$xx&$X$+;.:;+x+.:+XX+...;$&$$x. ....  .....;++;;:x$&$XX+:;:..:;+X$&+:;&&&&&X  
  &&&&&;:&$&&x::$$XX&&&&&;x+XX$X+;::;;:..;+X$$&x:.:x$x:;+..:.:;;x;+x$+$$:;;:;:+;;+;;;;;;&&$$x:  
  &&&&&++&$$Xx;;:x&&&&&&:;xxxx+++Xx:.....X;XXX$+;:x&&..x+..;:++xX++x&XX+::xx+X&x;++;;;++&&X:;:  
  &&&&&+x&$x;;$&$++X&&&&&XXxX$$$+++.:.....$XX$$&&+;XXx.:;.:;+++xXx+XX$X$x++xX$$+;;+x+:;;;XX&$:  
  &&&&&+x&Xxx&&&&$XXX$&&&&XxxXxXxx$;+::....;&+;;;XXXx+;::.:::;++xX$X$$X$$XX$&&XXx;::+xxxx$&X;;  
  $$$X&Xx$&&&&&&&&&&&&&&xX$&$&XX$X$&X++;;;+$$XXXXXxxxx+:...:..:++x++xxXXXxxxx$&+x&$$&&$&$&&xxx  
  xX;::::;;++x&&&&&$&X$&$xxxxXX$Xxxxx+:....:::........:...... .:;;;+;;;;;+XX$$X&&$&&&&$+;+X$&$  
  &&$$$XxXxX$$&&XxX&&&&&&&Xxxx+++X+:.................;.....   ...::++;;;;xXX$&$$&&x$x;;:+xX&&$  
  &&&&&x+xXxX$&&&&+$&&&$$$Xx++:............:..........:..:.....;+xXX;+xxxX&&&&&&&&&&&&&$&&&&&$  
  &&&$&&&+&&&$$X&&&$$X+++:.............:::.....:::::..::.......:;+xXX$$XxxxxXXXXXXxxxxxXXXxXx+  
  &&&&&X&$X$$&$X+:...............:...;+:...:.:++x;..:.....:.:::;x$&$Xxx+xXx+;;++X++++;;;+++xx:  
  $&$$$$$Xx+;......:................:::;++;;;:......::;+;:::;xx+xxx+;+xX++x+;+++++;;+++++xXXX+  
  XXX&X++:............+:....:....::.:;;+;;:..:.::..:.;;;;;++x++x++++x+;;;;;++;;;x++xXXX$XXX$$+  
)"; 

    onScene = false;
    cout << "\n\n\n\n\n\n________________________________________________________________________________________________________________________\n\n";
    typeWriterEffect(story1, delay);
    Sleep(1000);

    typeWriterEffect(story2, delay);
    Sleep(1000);

    typeWriterEffect(story3, delay);
    Sleep(1000);
    battle(*chosenHero, goblin1);
    
    
    Sleep(1000);
    onScene = true;
    typeWriterEffect(story4, delay);
    Sleep(1000);
    typeWriterEffect(story5, delay);
    Sleep(1000);
    typeWriterEffect(story6, delay);
    Sleep(2000);
    typeWriterEffect(story7, delay);
    chosenHero->hpPotion += 5;
    TotemOfDagrash = true;
    Sleep(1000);
    typeWriterEffect(story8, delay);
    Sleep(1000);
    typeWriterEffect(story9, delay);
    Sleep(1500);
    cout << art1 << "\n\n";
    Sleep(1000);
    typeWriterEffect(story10, delay);
    Sleep(1500);
    typeWriterEffect(story11, delay);
    Sleep(1500);
    typeWriterEffect(story12, delay);
    Sleep(2000);

    Ogre ogre1;
    InjuredOgre ogre2;

    battle(*chosenHero, ogre1);
    Sleep(1000);
    typeWriterEffect(story13, delay);
    Sleep(1700);
    typeWriterEffect(story14, delay);
    chosenHero->hpPotion += 7;
    Sleep(1700);

    battle(*chosenHero, ogre2);
    onBattle = false;

    typeWriterEffect(story15, delay);
    Sleep(1700);
    typeWriterEffect(story16, delay);
    Sleep(1700);

    if(chosenHero->name == "Knight") {typeWriterEffect(story17a, delay);}
    else if(chosenHero->name == "Wizard") {typeWriterEffect(story17b, delay);}
    else{typeWriterEffect(story17a, delay);}
    Sleep(2000);

    onScene = true;
    playMusic(L"Music/forestBGM.wav");
    typeWriterEffect(story18, delay);
    Sleep(1000);
    typeWriterEffect(story19, delay);
    Sleep(2500);
    
}

void scene4(){
    cout << "ESCSD!";
}