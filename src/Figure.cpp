#include <iostream>
using namespace std;

class Field
{
  public:
    Field();
    Field(wchar_t ident);
    void setIdentifier(wchar_t ident, char piece, bool isWhite);
    void removeIdentifier();

    wchar_t getIdentifier();

  private:
    wchar_t identifier;
    char piece;
    bool isWhite;
};

Field::Field()
{
    identifier = 'x';
}

Field::Field(wchar_t ident)
{
    identifier = ident;
}

void Field::setIdentifier(wchar_t ident, char piece, bool isWhite)
{
    identifier = ident;
    this->piece = piece;
    this->isWhite = isWhite;
}

void Field::removeIdentifier(){
    identifier = L'\u0078';
    piece = 'x';
    isWhite = false;
}

wchar_t Field::getIdentifier(){
    return identifier;
}