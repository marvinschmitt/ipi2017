#include "tree.h"
#include <cmath>
#include <iostream>
#include <string>

std::vector<std::vector<int>> to_init_vector(std::vector<int> data);

int main()
{
    std::vector<int> tree_vector_num=
    {
        1, 1, 3, 5, 7, 9, 13, 7, 9, 13, 17, 9, 13, 17, 21, 13, 17, 19, 23, 27, 5, 5, 5
    };

    Tree my_tree(to_init_vector(tree_vector_num));
    my_tree.print();


    bool done = false;
    do {
    std::cout << "Was möchten Sie anbringen? b: Ball, c: Candle, x: Exit.";
    std::string in;
    std::cin >> in;
    switch (toupper(in[0]))            // in[0] ist der erste Buchstabe der Eingabe.
    {
        case 'B': my_tree.add("Ball", "print"); break;  // toupper() konvertiert zu einem Großbuchstaben
        case 'C': my_tree.add("Candle", "print"); break;
        default: done = true; std::cout << "Tschuess!\n"; break;
    }
    } while (!done);

}


std::vector<std::vector<int>> to_init_vector(std::vector<int> data)
{   
    int width = 0;
    int pos = 0;
    for (auto entry : data)
        width = std::max(width, entry);
    std::vector<std::vector <int>> result (data.size(), std::vector<int>(width, 0));
    for (int i = 0; i < data.size(); i++)
    {
        pos = 0;
        for (int n = 1; n <= data[i]; n++)
        {
            result[i].at((width-1)/2 + pos) = 1;
            if (n % 2 == 1) (pos<0?pos--:pos++);
            else pos = pos * -1;
        }
    }


    return result;
}




// std::vector<std::vector<int>> tree_vector(std::vector<int> data)
// {   
//     int width = 0;
//     int pos = 0;
//     for (auto entry : data)
//         width = std::max(width, entry);
//     std::cout << "width: " << width << std::endl;

//     std::vector<std::vector <int>> result (data.size(), std::vector<int>(width, 0));
//     for (int i = 0; i < data.size(); i++)
//     {
//         pos = 0;
//         for (int n = 1; n <= data[i]; n++)
//         {
//             std::cout << "i: " << i << ", pos: " << pos << ", n: " << n << std::endl;
//             result[i].at((width-1)/2 + pos) = 1;
//             if (n % 2 == 1) (pos<0?pos--:pos++);
//             else pos = pos * -1;
//         }
//     }


//     return result;
// }