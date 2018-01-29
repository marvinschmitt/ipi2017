#pragma once

#include "treeobject.h"

class Star : public Treeobject
{
public:
    Star() : Treeobject("X", "yellow"){};
    Star(std::string color) : Treeobject("X", color){};
};