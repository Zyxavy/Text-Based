#include "gameScenes.cpp"

using namespace std;
Dummy test1;

int main(){

    setupConsoleWindow();
    playMusic(L"Music/retroBGM.wav");

    //Scene1
    int scene1 = 2;
    int tutor;


    do{
        scene1 = 2;
        selectHero(chosenHero);
        cout << "\n\nContinue?: 1: yes | 2. no: ";
        cin >> scene1;
        if(!scene1) scene1 = 2;

    } while(scene1 != 1);

    cout << "\n\nEnter the tutorial?\n" << "1.YES!  |  2. NO!\n:";
    cin >> tutor;

    if(tutor == 1) {tutorial(*chosenHero, test1);}
   
    Sleep(1000);
    scene2();
    scene3();

    system("pause");

    delete chosenHero;
    return 0;
} 


