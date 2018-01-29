#pragma once

#include <iostream>
#include <vector>
#include "treeobject.h"
#include "needle.h"
#include "blank.h"
#include "ball.h"
#include "star.h"
#include "candle.h"


class Tree
{
private:
    int _height;
    int _width;
    std::vector< std::vector <Treeobject *> > _data;


public:
    
    Tree(std::vector<std::vector<int>> init_vector)
    : _height(init_vector.size())
    , _width(init_vector[0].size())
    , _data((unsigned long)_height, std::vector<Treeobject *>((unsigned long)_width))
    {
        for (int i = 0; i < init_vector.size(); i++)
        {
            for (int j = 0; j < init_vector[0].size(); j++)
            {
                if (init_vector[i][j] == 1) _data[i][j] = new Needle;
                else _data[i][j] = new Blank;
            }
        }
        delete _data[0][(_width-1)/2];
        _data[0][(_width-1)/2] = new Star;
    };

    void add(std::string object, std::string print = "")
    {
        if (object == "Ball")
        {
            delete _data[5][(_width-1)/2];
            _data[5][(_width-1)/2] = new Ball;
        }
        if (object == "Candle")
        {
            delete _data[7][(_width-1)/2];
            _data[7][(_width-1)/2] = new Candle;
        }

        if (print == "print") this->print();
    }

    // void decorate(int n_balls)
    // {
    //     bool done = false;
    //     while (!done)
    //     {
    //         try
    //         {
    //             for (int n = 1, n <= n_balls)
    //             {
    //                 // Ball an random Stelle packen
    //             }
    //         }
    //         // EXCEPT: außer wenn der Abstand der Kugeln zu klein ist; irgendwas mit done
    //     }
    // }


// print function
    void print() const
    {
        for (std::vector<Treeobject*> row : _data)
        {
            for (Treeobject* entry : row)
            {   
                entry->print();
            }
            std::cout << std::endl;
        }
    }

};

/*
//ITERATION ÜBER _data[i][j]
    for (unsigned int j = 0; j < _data[0].size(); j++)
    {
      for (unsigned int i = 0; i < _data.size(); i++)
      {

      }
    }


// ITERATION ÜBER ELEMENTE
  for (const std::vector<Treeobject>& row : data)
    for (const Treeobject& entry : row)
      //CODE ÜBER TREEOBJECT



*/