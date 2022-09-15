#include <iostream>
#include "Game.cpp"

int main()
{
    cout << "ChessDec Started!..." << endl;
    Game *prtGame = new Game("WDC");
    wcout << endl;
    prtGame->initGame();
    wcout << endl;

    prtGame->startGame();
    
    return 0;
}
