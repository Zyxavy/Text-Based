#include "game.hpp"

//Global Variables
int Goblin::baseDamage = 20;
int Goblin::baseHealth = 100;
int Goblin::baseDefense = 15;
int Goblin::baseSpeed = 15;
int Goblin::baseExp = 20;

int Witch::baseDamage = 34;
int Witch::baseHealth = 100;
int Witch::baseDefense = 10;
int Witch::baseSpeed = 12;
int Witch::baseExp = 30;

int WereWolf::baseDamage = 25;
int WereWolf::baseHealth = 130;
int WereWolf::baseDefense = 35;
int WereWolf::baseSpeed = 10;
int WereWolf::baseExp = 39;

int Skeleton::baseDamage = 30;
int Skeleton::baseHealth = 125;
int Skeleton::baseDefense = 25;
int Skeleton::baseSpeed = 20;
int Skeleton::baseExp = 65;

// basic Enemy
Knight::Knight(){
  maxHealth = 170;
  currentHealth = 170;
  damage = 30;
  defense = 100;
  speed = 13;
  type = "Strength";
  name = "Knight";
  art = R"(
                               @.                        
                                   #@@@@.                        
                               -@@@######%@@+                    
                              @@#***#**#*#*#%@+                  
                            -@%#*#*######****#@@                 
               +@@.         @@%##%##%%#**#*#***%@                
              @%##@*        %@@@%@%@@@@%#*###*##%@               
            #@:.+@@=        .@@@@@@@@@@@@%***#*%%@@              
       %@@*@%=. *:=@       #@:  =+-  :@@@@%#**##%@@@             
      :@-  .+@+:*% .@:    @*:*++%%%=++:@@@@%****#@@@=            
        :@@. =-+=.#*.@-  ###%%%%%%%%%%%*@@@@@##**#@@@            
           %@@   -*:*@@@%@#@%%%%%%%%%%%%@*-=@@@#***%@@           
             @   * +. :%@@@@@@#++#++%@@@@.   @@@@##*#@@=         
             @   @ #@*-..#@@@%@@@@@@@%@@@     -@@@@@%%%@@@:      
             @   @ -@@@@@@@%@@@*-@*+%@@@@@@@@@@#-@@:+%@@@@@@@@%+.
             @   +. @ #@@@@%@@@%:@-@@@@%@@@@@@%#%@@              
             @   .. @   @#-@@@@@: =@@@%@@@@%###***#@@            
             @    : #-  @: :@@#@%%%@#@@##**#**#**#**%@           
             @    + .@  @..#%@@#=%=@@@%%%%%@@@@@%%#*##@.         
             @    %  @  @=%@##@@@@@@@@@@@@@@@%%@@@@@##@@         
             @    %  %  :@%@@@%:#@: #@@@@:        +@@%#@%        
  -@@=-@@@   @    *. =-  +@@-  .@@+%@@@%           .@@#%@.       
 @@++# :@@@  @    -. =+   @*    :@@@%@%             =@%#@@-      
@@-++.-. +@@ @     . -+   @@%*=--=+%@@+.          .==@@#@@@      
@@#: .   .-@@@     : .*    @%@@#=%@@#@@#-         +*#@%#@%@      
#@@*:.  .*@#-%     =  %    -@:#@@@:  :@@@%:     .*%%@@#%@%@      
  #@@@%%@@+ :#     +  #.    @@@-       #@@@%#**#%%@@%##@#%@-     
     -@@@@@*=%     +  =@*@@@%        .. :@@@@@@@@@##*#@%#%@+     
         :%@@@@    :  .@+@@@@%    .=:..+#@@@@@@@%###%@#*%%@@     
             .@@   .. :@.*@@@@#:-#-:#@@@@*%@@@%**#%@@#*#*#@@#    
               **  . .#* :@@@@@@%%%@@%*%@@@@#*#%@@%##*#*#%@@@    
                @: -.=@@@@@@@@@@@@@@%@@@@%##%%%%%%#**#%##@%#@    
                 @:+.@= =@@@@@@%@@@#@@%###%@@@@%###%@@#%@@##@+   
                  @%*@    *@@@@@@@@@@@@@@@@@@%@@@@@@##%@@%@@%@   
                  .@@         @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+ 
  )";
}

Wizard::Wizard() {
  maxHealth = 100;
  currentHealth = 100;
  damage = 55;
  defense = 18;
  speed = 24;
  type = "Magic";
  name = "Wizard";
  art = R"(
                                                     
               .*.                                             
               :#*:                                            
               =#                                              
              :-**                                             
          #++ :+#%+ -.  .-=-.                                  
         #%#%.*#-*##+ *@%##**##=             ..                
          .+*++#**#%=  ##**++*#%%:           ....              
               .@@@=  *###*#%%%#@-           ...:.             
                -#@* =%###*====%@-          ..:.:.             
                 %@%*####=*++*#@@%:         .-:.::..           
                 #%@%#**%%==.-%%*%%+        .:-....            
                  **%#%##*++-=*%%@%=          ... :            
                 -*+-*******#-=#%%%=         .  .-+=           
                +#-:-+#*+=-=*#=*%%%%%.      :...-*:            
              :##*:-=*%*==*#####@%%%##*     ::-+=              
              ##*=:-*%##%%*=-*%+@#*@@@%=  .--+                 
             =#*+-+@@#@@@=--=#++%#*@@@%#++=##:                 
            +##*:+@@@#%@@%#+%%%@@@%@@@#***%@%                  
            =#%**#@@@@=@@@@%@@@@@@@@@@##@@@@@@+                
             *%%#%@@@@*%@@@@@@@@@@@@@@%%@@@@@@@%+              
             ##%%@@@@%@%@@@@@@@@@@@@@@@@%%@@@@@@@*             
            .##@%#%@@%%%@@@@@@@@@@@@@@@@@@@@@@@@@@@            
            ####@#*@@@#%%@@@@@@@@@@@@@@@@@@@@@%%%%%*           
           -###*@@*#@@%@*%@@@@@@@@@@@@@@@@@@++*#@%%%*          
           +%%##@@@**%@@##@%@@@@@@@@@@@@@@@@@@#     :#.        
          .#%%##%@@*+*@@@*@@@@@@@@@@@@@@@@@@@%%@@+.            
          :%%%%##@@*++#@@*%%@@@@@@@@@@@@@@@@@@%@@@@%-          
          -%%%%##@%#*=#@@%#%%@@@@@@@@@@@@@@@@@@@@@@@@@=        
          =%%%%##@%#**#@@@*%%%%@@@@@@@@@@@@@@@@@@@@@@@@#.      
          *%%%%#%@%#**%@@@*##%%%@@@@@@@@@@@@@@@@@@@@@@@@%=     
          %%%%%%#@%#*#%@@@%#@%%%@@@@@@@%@@@@@@@@@%=     .+-    
          %%%%%%%@@####@@@@%#%#*%@@@@@@@%@@@@@@@@@             
          %%%%%%%@@%%%%%@@@%#%*+*@@@@@@@%@@@@@@@@@@:           
          %%#%%%%@@@@%%@@@@@%##+*#%@@@@%%%@@@@@@@@@@:          
          ######%%@@@%@@@@@@%#*++*#%%@@%%%@@@@@@@@@@@:         
          *%##%###@@@@@@@@@@+*%*+*##%@@@%%@@@@@@@@@@@@         
          #%#**#%%%@@@@@@@@@**%#**####@@@%%@@@@@@@@@@@*        
          #@@@@@@@@@@@@@@@@@*+#@+*####%@@@%%@@@@@@@@@*         
          #@@@@@@@@@@@@@@@@@**#%#####%%@@@@%@@@@@@+.           
          #@@@@@@@@@@@@@@@@@#**#%*##%#%@@@@%%@-                
          *@@@@@@@@@@@@@@@@@##*%%######%@@@@%%.                
          .%@@@%@@@@@@@@@@@@###%@%##%#%%%%  %*                 
          .%@@@@@@@@@  @@@@@%###%%%%%#%%%   =-                 
            #@@@@@@@%  @@@*=+*#%%@%#*=---                      
               *@@@@*  #=    +@@@%@@+                          
              :%@@@*         -@@@@%@@@@@#-                     
             =@@%@%               #*  .                        
             -*%%*                :=                        
)";
}

Thief::Thief(){
  maxHealth = 110;
  currentHealth = 110;
  damage = 43;
  defense = 30;
  speed = 50;
  type = "Phantom";
  name = "Thief";
  art = R"(
                          ......      -*                      
                         .........    +##                      
                         ..........   =##                      
                         ...-.:-:.::  +%#*      =              
                         :::=-:=--=. - #%*     ###*            
                        :-==+++++==:=  #%#    =+*#             
                         -#%%**%%#+-. +#%#   :++*              
                      .:.=%###%%%%+=.::+##-=-=+                
                   .....-%%%###%###++.-+:..:-++                
                   ...:+*##%#%%#####=-=---+=:..                
                  .-:==**#*+*+***###+=++*##-+-.:               
                  .==+:*#*==++==*##==**##%#*+==-:              
                  :#**++##+=*==+##+######%###**+=              
                  .#*=##+#+=+-=+#*#%%#*#%%%%*####..            
                  .+%#*####*#**##%%%%###%%%%%%%#*-..           
                 :+*#%#%%%%##%%#%%%%%%##%%%#%###*+-.:          
                ..+####*%%%%%%%%%%%%%%%%#%*  %%###**.:         
                .+#*#%%*%%%##%%%%%%%%%%%%%#   %#%######        
               .:***#%%*#%%#####%%%%%%%%#*     %##**###+       
              .-**##%==#%#%%**#**#%%%%%%%###   %%%%%%#%#       
              .+##%%%*%##%%#*++*+*%%#%%%%%##   @%%%##%%#       
             :*##%%%  #%%%%#+++++#%%%%%%%%%      %%%%%##*      
            =*####    %%###%#######%%%%%%%%%      %%####*      
            %%%%#    #*++#%%**%%*%%%%%%%%%%%       %%#%##      
           *##%#%%   %**%%%%%%%%%%%#%%%%#%%%        %%#+*      
     *    +%%%%#    **#%%%##%%%#*#%%%%%%%%%%*:       ####      
    ##**#%%   %     ##%%%%%%%%%%%%%%%%%%%%%%%%      =*%%##     
    ###%%          #%%%%%%%%%%%%%%%%%%%%%%%#           %##     
    #%%          +#%%%%%%%%%%%%%%%%%%%%%%%%%%%        ***%     
    +###        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%        ##      
    *#=#       .#%%@%%%%%%%%%%%%%%%%%%%%%%%%%%%                
     #%       ##%%%%%%%%%%%%%%%%%%%%%%%###%##%%%               
              #%%%%%##%%%%%%%%%%%%@%%###%%%%%%%%%              
              #%#######%%%%%%%%%%%%%%#*###%%%@%%%              
               #*##*#%%%%%%%%%%%%%%%%#######%%%%%%             
               #**##%%%%%@%%%%%%%%%%%%%%##%%%%%@%%%            
              *#*###%%%%%%%%%%%%%%%%%%%%%%%%%%%@%%%            
              *#***#%%%%%%%%%%%%%%%%%%%%#%%#%%%@@@@%           
              *****#%%%%%%%%%%%%%%%%%%#%%#%#%%%%@@@%           
              ***##%%%%%%%%%%%%%%%%%%%##%%%##%%%%%@%           
              ###%%%%%%%%%%%%%%%%%%%%%# %%%#*%#%%%%            
              ###%%%%%%%%%%%%%%%%%%%%%%#%#%%%%%%##             
               #%%%%%%## %%%%%%%%%%%%%% %%%%%%%%%#             
                %%%%%%%#       %%%%%%%% %%%#%%%%%#%            
                %%%%%%%#           %%%%#  %%%%%##%#            
                 %%%%%#*             %##   %%%%#%%%#           
                 #%%%%##                    ####%%%            
                 #%%%#**                     ####%#            
                ###%%%*+                     ***##+*           
               =*###%%#*                     +*+##%*           
             +****#%%###                      *#####*          
              ##%%%%                         +#%#**#%*         
                                              #%#*****         
                                               %%#%###         
)";
}

Goblin::Goblin(){
  difficulty = 1;
  exp = baseExp;
  maxHealth = baseHealth;
  currentHealth = maxHealth;
  damage = baseDamage;
  defense = baseDefense;
  speed = baseSpeed;
  name = "Goblin";
  type = "Phantom"; 
  weakness = "TotemOfDagrash";
  art = R"(
                         :                 :-       
     -::             +::=:-=:          ::::         
      --:::       *+=-:::-::-###   -:::==+          
       ::--::::*#+*+=::::::-=+*##+=-*=++            
          ::++-:+*+++-::::--=**#%@++=*              
           :::+*-==:::::==++***::+#-=               
            :::+*=-:-:-::::::--=#=@=                
            :::=+==:::::::::::::::=                 
               **+--=:::::::::::++# :--::::::--=    
        :::::::-+*+-:**-:-----%%=##::::::::::::-+=  
:::-++=***-=:-:-#**#*-:=**+%%=-=*+#*%%#=++*++=*+:=+=
+**+-%%#**===  -*=%%@%%*-::-=== # =:                
        =::+=--:::==%#+*%%##%*::::-::               
        *=::::::+=#-**-::::=%+::::--=               
        *+--+=-+####@%-::-:+*%+*#--:+               
          %#::    %%%==+++**#@@ -::*=               
            ::    *@%#%#%+*=##-=-:+:                
                 :-*##@+%+*@@@****                  
               *+#%%+**=:-**@@@#+                   
            +***+-*%+---:=*+**#@@#:                 
            **::+@#*+=-%+#*+++==#@@                 
           =+--**##=-=#%*##*##*+::#@                
            +#=::--%+#-:+%%#@#*::::*#-              
           - #--=-# @%*-:=*%@%#*:+++*               
            :==+=** =@#+-=+%  @*=-:=*               
            -====#*  @::-=*=  *+-==+%               
            -*==*%%     =*%   #*===+#               
            =*++**#     +*     %+===*+              
          =++==+##@      %    #*#*==++==-*#         
       #*=====+##              %@@+%#*=*#@@         
        @@@@@%%                                  
)";

}

Witch::Witch(){
  difficulty = 2;
  exp = baseExp;
  maxHealth = baseHealth;
  currentHealth = maxHealth;
  damage = baseDamage;
  defense = baseDefense;
  speed = baseSpeed;
  name = "Witch";
  type = "Magic";
  weakness = ' ';
  art = R"(
           @###@                               
            @#[[{#                           
              @#]<<]}#%@                     
                 #}<+[#%@                    
                  }{}({#@@                   
       }#         @#}{#%@@@                  
       ]}         %{#%#%@@@@  @    @@        
       }#          @@@%%%%#{}(<)(]}#@@       
       @@@ @@@@#[(>^*++=====++++++^<(}       
        @@@@{])^++++=~--...:~=++++*<]        
        #({[)<*++++++:.......=+++>(          
        #([[]<*+++**+:.......+<(             
         <-  [)<^*<}(+-:...:~+(              
         >=     ]=~-~}(++=++[{               
        }[*~  ^>+~~+=~~^}]<+~+               
        #)>]+{#](=>+}++=~=<)[[               
        #}[*+@@#{)][~#][}[<{]){              
        @%{))@%%{%%}<^[][{}<[%@              
       @}@}[[+]}]%%[{(}}){[#@@@              
         @}]@#}#@###{###%%%@%][]             
        @@%[@@@@@{}{######@@%)=~:--:     ~>(#
       @@@#}@@@@%#}]{}}{#%@@@@%##[<~~===]<(]>
      %@%{@#%@@@%%}[]{[###%@@%%#{%%{%)(%%[#{[
    ##%{{@@##@@@##}}[}}{%%#%%@ @*+-)]>)[  %  
  [}{%{{~~}##@@@{#{[#[}}@{%%%%@              
 []~:-#)(^[@{@@@#%%%{#{{%{%%@%@@             
  @%#@@ #{@@{%@@#@@#@##{#%%%@@@@             
    @@@ #@@@}@@%@@@@{@%%#@#@%@@@@            
  @@@@@{@@%@[[@%@@@@#%@@#@%@%@@@@            
  @)<@% @@#[(]}%@%@%@%@@%@%@@@@@@@           
  @@@##@@@}]]]]}@@@%@%@@@@@@@@@@@@           
 @(.[@ @@}{[[}{{}@@@@@@@@@@@@@@@@@@          
%]#@@  @**(}}}]}[@@@%@@@@@@@@@@@@@@          
        %{{{{{}}{#@@@@@@@@@@@@@@@@@          
        {{{#{{}}}{@@@@@@@@@@@@@@@@@@         
        }#{#{#{}{#@@@@@@@@@@@@@@@@@@         
        {{((}#[[%%@@@@@@@@@@@@@@@@@          
                 @@@ @@@@@@@ @@                      
)";
}

WereWolf::WereWolf(){
  difficulty = 3;
  exp = baseExp;
  maxHealth = baseHealth;
  currentHealth = maxHealth;
  damage = baseDamage;
  defense = baseDefense;
  speed = baseSpeed;
  name = "WereWolf";
  type = "Melee";
  weakness = ' ';
  art = R"(
                   @@%%               
                 @@@  @@:              
              =@ @     +               
            #@@.  -@*@@                
             +  .      @               
            @   = :*  =.               
            @#@@#=   @=@@@:            
           @@    : @+   . --           
 @@@@=    @   @.     @@  =@       @@@@ 
 #@#*@@+  @  @: *#-*+    + @    #@ @%  
 @   @   +-  @-:  +::  .:@ @      *  @ 
  @% @-  @ =@  =@  .+  * =    -:   @*  
    @  .-@  @ +: @  = :+:@@@@@@@@-     
     %@@+.@@@ ++ @=#@.+-. @=    %:     
         -.      @     *   @           
                @  : =@- @  @+         
              :#     *   .:   @@       
              @     .@@@@       @=     
         #@%@@     @@    =@       @    
         @  =     @@     @@@@=#=  @.   
        -% @:+ .@@      @@   @@@@@     
        @   .%#=         @ .+          
        @ @%             @*:.%         
        # #:              *%= @*       
       %   :#               =+  :@@@   
     +@@@@@@@+               .*@@@@     )";
}

Skeleton::Skeleton(){
  difficulty = 4;
  exp = baseExp;
  maxHealth = baseHealth;
  currentHealth = maxHealth;
  damage = baseDamage;
  defense = baseDefense;
  speed = baseSpeed;
  name = "Skeleton";
  type = "Melee";
  weakness = ' ';
  art = R"(
                              _.--""-._
  .                         ."         ".
 / \    ,^.         /(     Y             |      )\
/   `---. |--'\    (  \__..'--   -   -- -'""-.-'  )
|        :|    `>   '.     l_..-------.._l      .'
|      __l;__ .'      "-.__.||_.-'v'-._||`"----"
 \  .-' | |  `              l._       _.'
  \/    | |                   l`^^'^^'j
        | |                _   \_____/     _
        j |               l `--__)-'(__.--' |
        | |               | /`---``-----'"1 |  ,-----.
        | |               )/  `--' '---'   \'-'  ___  `-.
        | |              //  `-'  '`----'  /  ,-'   I`.  \
      _ L |_            //  `-.-.'`-----' /  /  |   |  `. \
     '._' / \         _/(   `/   )- ---' ;  /__.J   L.__.\ :
      `._;/7(-.......'  /        ) (     |  |            | |
      `._;l _'--------_/        )-'/     :  |___.    _._./ ;
        | |                 .__ )-'\  __  \  \  I   1   / /
        `-'                /   `-\-(-'   \ \  `.|   | ,' /
                           \__  `-'    __/  `-. `---'',-'
                              )-._.-- (        `-----'
                             )(  l\ o ('..-.
                       _..--' _'-' '--'.-. |
                __,,-'' _,,-''            \ \
               f'. _,,-'                   \ \
              ()--  |                       \ \
                \.  |                       /  \
                  \ \                      |._  |
                   \ \                     |  ()|
                    \ \                     \  /
                     ) `-.                   | |
                    // .__)                  | |
                 _.//7'                      | |
               '---'                         j_| `
                                            (| |
                                             |  \
                                             |lllj
                                             |||||)";
}

Dummy::Dummy(){
  exp = 0;
  maxHealth = 1000000;
  currentHealth = 1000000;
  damage = 10;
  defense = 0;
  speed = 0;
  name = "Training Dummy";
  type = "Melee";
  art = R"(
         &&&
        (+.+)
      ___\=/___
     (|_ ~~~ _|)
        |___|
        / _ \
       /_/ \_\
      /_)   (_\)";
}

// Bosses
Ogre::Ogre(){
  difficulty = 6;
  exp = 40;
  maxHealth = 250;
  currentHealth = 250;
  damage = 36;
  defense = 29;
  speed = 18;
  name = "Ogre | Boss";
  type = "Goblin"; 
  weakness = "TotemOfDagrash";
  art = R"(
                                              -**++%%#*-                            
                                            .:.%@@@%@%+=+%%@*                         
                                            -@@@@@@@@@*#%#@@%-                        
                                             @@@@@@@@@@@@**##:                        
                                             +@@@@@@@@%#@@@@*=++.                     
                                            .@@@@%%%@@@@@@@@@%*+**:                   
                                            #@@@@@@@@@@@##@@@@@@%+*@#                 
                                          .=@@@%*@@%%###%@@@@@@@@@@@@#.               
                                         :@@@@@@@@@%@@@@@@@@@@@@@@@@+-==+=            
                                       :#@@@@@@@@@%*##@@++#*+#@@@@%**=:..:+=          
                                     +@@@#=+@@@@@#***=-...:=#*=+=%###@%#+--=+.        
                                    @@@%+:  -@@@#.        *@@@=.=*%@@@@@@@*-*+        
                                   @@@@=..+%#:=%@@=     *@@@#.  .+#@@@@@@%%+=+:       
                                  +@@@%+#@@@=. .%@@@..=@@@%.   ...=@@@@%%%%#==+       
                                :@@@@@@@@@@%=    :@@@@@@@=--.    .@@@@@@@@%@%++=      
                               *@@@@=.  .%@@*-..:=%@@+*%%%*--=%@%@@**++==+#@%+-*.     
                              =@@@@=.   :@@@@%#*@@@=:%@@@@@#::=@@@#@=*+*---*%*-#:     
                             .@@@@@=.   :%@@@@@@@@@#@@+*@@@+#@@@@@*@*==+=:-+%%=+.     
                             @@@@@@#=-:=@@@@@@+. %+:@++#@@*@@@@@@@@@*=-::-*%%##:      
                           #@@@@@@@@@@@@@@#*-   :@@@@++@@@@#+#@@@@@@@@@@@@@@#=+.      
                         :@@@@@@@@@@@@@@@@*-. .  -++=::+@+%#-=+%@@@@@@@@@@@@@@-       
                        :@@@@@@@@@%-=@*@@%*:          .+@@@:  -*#@@@@@@@@@*           
                        #@@@@#%@@+::=@#@@#*=.           ..      :=+#@@@@+             
                       .%@@@@%##@#@%@@@@#**++-.    +%@=          .+@@@@-++            
                       :@@@@@*@@@@@@@@@@@@+++++=.              :*@@#:-==-+*           
                       =@@@@%@@@@@@@@@@%*@@@#+++++=-:.   ..-=+%@@@*=:-*#*+#=          
                      -@@@**@@#=%@@@@@@=:::@@@@@@@@@*++++++%@@@@@@#-::=##+*+          
                     .@@%:-@@@@*#@@@@@*:::  @@@@@@@@@@@@@@@@@@@@@@%*=::*%#**:         
                    .@@@#=@@+*#@%@@@@@--+:  +@@@@@@@@@@@@@%@@@@@@@@%+::*@%%#:         
                    @@@@#+%=#@@*@@@@@%=#%+. -@@@@@@@@@@@@@#@@@@@@@@@@#==*%@#          
                   -@@@@@==*@@@@@@@@@@#@@@#*#@@@@@@@@@@@@@%%@@@@@@@@@%*%@@#*:         
                   +@@@@@@#@@*@@@@@@@%*@@@@@@*%@@@@@@@@@@@@%#@@#@@@@@@@@#*=-=*:       
                  -@@@%@@@@@@@- :@@@@@++@@@@@@@*@@@@@@@@@@@%#*@@@@@@@@@@*##=-+*.      
             .=%@@@@@@@@@@@@@-  =@@@@@@#*@@@*-%@@@@@@@@@@@@@#***@@@@@@@#--*+:=#:      
              @@@@@@@@@@@-      #@@@@@@@%%@@#==@@@@@@@@@@@@@@@%#*@@@@@@%-:-=::+.      
            :@@@@@@@@@@@.       .@@@@@@@@@@@@@@@=*@@%@@=:@@@@@@@@@@@@@@@*::::+-       
       .+=-%@@@@@@@@@@#           @@@@@@@@@@@@@+    .       %@#@@@@@@@@@@%#*+*:       
       .*@@@@%**@@@@@+            .@@@@@@@@@@@#                ..   @@@@@@#%@@#.      
      :@@@@@@%*%@@@@.         -*##@@@@@@@@@@@@#.                   %@@@@@@@#%%@@:     
     :%@@@@@@@@@@@@-      :#@@#=::@@@@@%+--#@@@+                  *@@@--@@@@%=+%@=    
    +@@@@@@@@@@@@@@-    :##*-:-:.-@@@@@%*==+@@@%.               -@@#*=+:%@@@@@#+=%@.  
   +@@%@@@@@@@@@@#@@:   :@@@@@+=#%  @@@@*=+%@@*.               .@@@@::-*@@@@@@@*--++  
    .@#+#@@@@@@#:        .*@@@@@-    +@@@@#-                    *@@@@@@@-  :@@@@@@@   
      =**%@@@%.                                                    ..         .-:     
         :#%-                                                                               
)";

}

InjuredOgre::InjuredOgre(){
  difficulty = 6;
  exp = 240;
  maxHealth = 250;
  currentHealth = 140;
  damage = 29;
  defense = 19;
  speed = 12;
  name = "Injured Ogre | Boss";
  type = "Goblin"; 
  weakness = "TotemOfDagrash";
  art = R"(
                    .             -**=-.                              
                               :##@@@#+#+-.                           
                             .=#=**+*+=:+*: :                         
                        .:=*+*@#****+==-:*++=..                       
                      :+***%%%@*+***+=-==-*#+=:......                 
                    .=*%##%@@@@%@@%##*%@@*+*@#+==::....               
                 ..:=*##*@@@@@@%%%@@%#*++==#*##=---.....              
               :=+++****+*%%@@@##%#%%#****++***++=--::...             
              .==++**#*+==++#%@@%%%%%%*+===***##*+++=-..:.            
              =#****++=====+#%@@@@*%@@@#++#%##%%#**++=---=:.          
            :*##%**++++++=+**#%@@@@@@@@@@%@@*##+*++*+++--==-          
           -####%%%###***#*++*#%%%%#@@@@@@@#**+=+#@@#*+=---:.         
          .*%#*****+==+#@@#***####***#@#*##+##++=+@@%*+===-::.        
         :*%#%***+*=---+@@%**++*##**+=#*******+#- -#%#*+*#+=-=.       
        :%@##*+**++===+@@@@@@%#***#%#-=++*#%@@@*    .:@@#@%%%#*=.     
        *%%***++#%#*+-%@@@@@@@@@@%%#+*#**###@@@@.     %@@@@%%##*:     
       #@@@%%%#+=+.  .@@@@@@@@@@@%##*##*##@@@@@@-     *@@@@@#*##:     
      -@@@@@@%%#%#.  :@@@@@@@@%%@@%@@@@@@@@@@@%@#.     %@@@%%%%*:     
       #@@@@@@@#%%.  %@@@@@@@@@@@@@@@@@@@@@@@@@@@#:    :@@@@@##+:     
       =@@%%@@@%%*  =@@@@@@@@@@@@@@@@@@@%@@@@@@@@%+.  .+##+++===.     
       :@@%%@@%@@: -@@@@@@@@@@@@@@@@@@@@@@@@@@@@%**+. *#***+==--      
       .%@@#%%#*%-.#@@@###%%@@@@@@@@@@@@@@@@#%@@%#*+=.#*@%**+--.      
       .@@@@@%%@@*.@@@@###%#%@@%%%@@@@@@@%#@@@@@%##*#*%%%#**%*+:      
        @@@@%##*=+=*@@%#*##*%@@@@%#%%%%@#@@@@@@%%@@%%+:=%#*##+:       
        *@@@%%*++@%*#@@@%#%#@@ #@#*+**##%@@@@@@@@@@@@%:               
        .%@@%%@=+=#+*@@@@@@%*  =@%*.=+*##-= :@@@@@@@@#.               
          =@@#%%*+*#%%#%%@@+    =*= .:  :   *@@@@@@@#+                
             :##%%%%@@@@@%*.     .+          =@@@@@@#-                
                 :@@@@@@%.                     =@@@@@-                
                 -@@@@@#                        #@@@@#.               
                .%@@@@@#                        -@@@%@*:              
              :*#**##%@*                        =@@@##%@#*+:            
)";

}