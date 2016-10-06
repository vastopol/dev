#include "num.h"

Num::Num()
    :val(0), tag("NULL")
{}
//-------------------------------------

Num::Num(int x, std::string str)
    :val(x), tag(str)
{}
//-------------------------------------

Num::~Num()
{}
//-------------------------------------

int Num::getVal()
{
    return val;
}
//-------------------------------------

std::string Num::getTag()
{
    return tag;
}
//-------------------------------------