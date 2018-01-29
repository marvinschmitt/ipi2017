#pragma once

#include <string>
#include <iostream>

class Treeobject
{
protected:
    std::string _icon;
    std::string _color;

public:
    Treeobject(std::string icon, std::string color) : _icon(icon), _color(color){};
    virtual ~Treeobject(){};

    void print()
    {
        std::string output;
        std::string color_code;

    //  Farbe setzen    
        if (this->_color == "black") color_code = "30";
        else if (this->_color == "red") color_code = "31";
        else if (this->_color == "green") color_code = "32";
        else if (this->_color == "yellow") color_code = "33";
        else if (this->_color == "blue") color_code = "34";
        else if (this->_color == "violet") color_code = "35";
        else if (this->_color == "cyan") color_code = "36";
        else color_code = "37";


        output =    "\033["  
                    + color_code + ";1m" 
                    + this->_icon + "\033[m";
        std::cout << output;
    }
};