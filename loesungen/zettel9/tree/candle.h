#pragma once

#include "treeobject.h"

class Candle : public Treeobject
{
public:
    Candle() : Treeobject("I", "red"){};
    Candle(std::string color) : Treeobject("I", color){};
};