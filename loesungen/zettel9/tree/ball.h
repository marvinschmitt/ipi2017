#pragma once

#include "treeobject.h"

class Ball : public Treeobject
{
public:
    Ball() : Treeobject("O", "blue"){};
    Ball(std::string color) : Treeobject("#", color){};
};