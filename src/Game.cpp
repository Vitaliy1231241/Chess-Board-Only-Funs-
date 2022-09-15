#include "Board.cpp"
#include <iostream>
#include <string>
using namespace std;

class Game
{
  public:
    Game(string name);
    void initGame();
    void startGame();

  private:
    Board *prtBoard;
    string name;
    bool isWhite;
    int moveCounter;

    string getUserInput();
    void analyzeInput(string input);
    void analyzePawnMove(string input);
    void analyzeQueenMove(string input);
    //TODO: Timer (Thread)
};

Game::Game(string name)
{
    prtBoard = new Board();
    name = name;
    isWhite = true;
    moveCounter = 1;
}

void Game::initGame()
{
    prtBoard->initBoard();
    prtBoard->printBoard();
}

void Game::startGame()
{
    wcout << "Game is Running..." << endl;
    bool gameRuns = true;
    while (gameRuns)
    {
        string input = getUserInput();
        wcout << "Input was " << input.c_str() << endl;
        analyzeInput(input);
        wcout << endl;
        prtBoard->printBoard();
        isWhite = !isWhite;
    }
}

string Game::getUserInput()
{
    if (isWhite)
    {
        wcout << "White move " << moveCounter << endl;
    }
    else
    {
        wcout << "Black move " << moveCounter << endl;
        moveCounter++;
    }

    string x;
    cin >> x;
    return x;
}

void Game::analyzeInput(string input)
{
    int inputLength = input.size();
    if (inputLength == 2)
    {
        analyzePawnMove(input);
    }
    else if (inputLength == 3)
    {
        char figure = input.at(0);
        switch (figure)
        {
        case 'P':
            input.erase(0, 1);
            analyzePawnMove(input);
            break;

        case 'Q':
            input.erase(0, 1);
            analyzeQueenMove(input);
            break;

        default:
            break;
        }
    }
}

void Game::analyzePawnMove(string input)
{
    char row = input.at(0);
    char col = input.at(1) - 1;
    int arrayPosRow = row - 97;
    int arrayPosCol = (int)col - '0';
    wcout << "Field at " << arrayPosRow << " / " << col << endl;
    if (arrayPosRow < prtBoard->BOARD_SIZE && arrayPosRow >= 0)
    {
        prtBoard->pawnMove(arrayPosRow, arrayPosCol, isWhite);
    }
}

void Game::analyzeQueenMove(string input)
{
    int* prtCrrentPosition;
    //TODO: A function in board, returning the wchar_t code for each figure with the knowledge of the figure and isWhite
    //It could also make sense to save the Figure Q and isWhite in Field to get an easy mapping!!
    if (isWhite)
        prtCrrentPosition = prtBoard->getPositionOfFigure(prtBoard->QUEEN_WHITE);
    wcout << prtCrrentPosition[0] << prtCrrentPosition[1] << endl;
}