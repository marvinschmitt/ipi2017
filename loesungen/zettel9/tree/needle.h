#pragma once

#include "treeobject.h"

class Needle : public Treeobject
{
public:
    Needle() : Treeobject("*", "green"){};
    Needle(std::string color) : Treeobject("#", color){};
};