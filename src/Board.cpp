#include "Figure.cpp"
#include <iostream>
#include <io.h>
#include <fcntl.h>
using namespace std;

class Board
{
  public:
    Board();

    const static int BOARD_SIZE = 8;
    Field prtFig[BOARD_SIZE][BOARD_SIZE];

    void initBoard();
    void printBoard();
    void pawnMove(int row, int col, bool pawnMove);
    int *getPositionOfFigure(wchar_t figure);

    //Figure **prtFig;
    const static wchar_t PAWN_BLACK = L'\u265F';
    const static wchar_t PAWN_WHITE = L'\u2659';
    const static wchar_t QUEEN_BLACK = L'\u265B';
    const static wchar_t QUEEN_WHITE = L'\u2655';
    const static wchar_t KING_BLACK = L'\u265A';
    const static wchar_t KING_WHITE = L'\u2654';
    const static wchar_t BISHOP_BLACK = L'\u265D';
    const static wchar_t BISHOP_WHITE = L'\u2657';
    const static wchar_t ROCK_BLACK = L'\u265C';
    const static wchar_t ROCK_WHITE = L'\u2656';

    const static wchar_t UNICODE_X = L'\u0078';

};

Board::Board()
{
    /* prtFig = new Figure *[BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; ++i)
        prtFig[i] = new Figure[BOARD_SIZE];

    /*for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
           cout << board[i][j].identifier;
        }
    }
    cout << endl;*/
}

void Board::initBoard()
{
    //Pawns
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        prtFig[i][1].setIdentifier(PAWN_WHITE, 'P', true);
        prtFig[i][6].setIdentifier(PAWN_BLACK, 'P', false);
    }
    //Rocks
    prtFig[0][0].setIdentifier(ROCK_WHITE, 'R', true);
    prtFig[7][0].setIdentifier(ROCK_WHITE, 'R', true);
    prtFig[0][7].setIdentifier(ROCK_BLACK, 'R', false);
    prtFig[7][7].setIdentifier(ROCK_BLACK, 'R', false);
    //Bishop
    prtFig[2][0].setIdentifier(BISHOP_WHITE, 'B', true);
    prtFig[5][0].setIdentifier(BISHOP_WHITE, 'B', true);
    prtFig[2][7].setIdentifier(BISHOP_BLACK, 'B', false);
    prtFig[5][7].setIdentifier(BISHOP_BLACK, 'B', false);
    //Knight
    prtFig[1][0].setIdentifier(KING_WHITE, 'N', true);
    prtFig[6][0].setIdentifier(KING_WHITE, 'N', true);
    prtFig[1][7].setIdentifier(KING_BLACK, 'N', false);
    prtFig[6][7].setIdentifier(KING_BLACK, 'N', false);
    //Queen/King
    prtFig[3][0].setIdentifier(QUEEN_WHITE, 'Q', true);
    prtFig[4][0].setIdentifier(KING_WHITE, 'K', true);
    prtFig[3][7].setIdentifier(QUEEN_BLACK, 'Q', false);
    prtFig[4][7].setIdentifier(KING_BLACK, 'K', false);
}

void Board::printBoard()
{
    /*wcout << L"♔" << endl;
    wcout << "dawdawsd";
    cout << "deafas";
    wchar_t test = L'\u2658';
    wcout << test << endl;
    wcout << L"\u2658" << endl;*/

    _setmode(_fileno(stdout), _O_U16TEXT);
    bool isWhite = false;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        int ascii = i + 17;
        char asciiChar = '0' + ascii;
        wcout << asciiChar << "| ";
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (prtFig[i][j].getIdentifier() != 'x')
            {
                wcout << prtFig[i][j].getIdentifier();
            }
            else
            {
                if (isWhite)
                {
                    wcout << L'\u2589';
                }
                else
                {
                    wcout << " ";
                }
            }
            isWhite = !isWhite;
            wcout << ' ';
        }
        wcout << endl;
        isWhite = !isWhite;
    }
    wcout << "   ";
    for (int i = 1; i < BOARD_SIZE + 1; i++)
        wcout << "_ ";
    wcout << endl;
    wcout << "   ";
    for (int i = 1; i < BOARD_SIZE + 1; i++)
        wcout << i << " ";
    wcout << endl;
}

int *Board::getPositionOfFigure(wchar_t figure)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            ///TODO: delete
            Field field = prtFig[i][j];
            if (field.getIdentifier() == figure)
            {
                int *position = new int[2];
                position[0] = i;
                position[1] = j;
                return position;
            }
        }
    }
    return new int(-1);
}

void Board::pawnMove(int row, int col, bool isWhite)
{
    Field *previosField;
    if (isWhite)
        previosField = &prtFig[row][col - 1];
    else
        previosField = &prtFig[row][col + 1];

    wcout << "previous identifier " << previosField->getIdentifier() << endl;
    if (isWhite && previosField->getIdentifier() == PAWN_WHITE ||
        !isWhite && previosField->getIdentifier() == PAWN_BLACK)
    {
        wcout << &prtFig[row][col - 1] << endl;
        wcout << previosField << endl;
        previosField->removeIdentifier();
    }

    Field *movedField = &prtFig[row][col];
    if (isWhite)
        movedField->setIdentifier(PAWN_WHITE, 'P', isWhite);
    else
        movedField->setIdentifier(PAWN_BLACK, 'P', isWhite);
}