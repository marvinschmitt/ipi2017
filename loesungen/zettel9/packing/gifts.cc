#include <iostream>
#include "rectangle.h"
#include <vector>

double big_number = 1e300;

double bssf_score(Rectangle const& free, Rectangle const& obj);
std::vector<Rectangle> sas_rule (Rectangle const& free, Rectangle const& best);
void print_rect_vector(std::vector<Rectangle> vector);


int main()
{
    Rectangle              table(Point(100.0, 80.0));
    Rectangle              tree_stand(Point(30.0, 30.0));

    std::vector<Rectangle> gifts = {Rectangle(Point(20.0, 10.0)),
                                    Rectangle(Point(10.0, 11.0)),
                                    Rectangle(Point(3.0, 46.0)),
                                    Rectangle(Point(3.0, 4.0)),
                                    Rectangle(Point(6.0, 16.0)),
                                    Rectangle(Point(10.0, 20.0)),
                                    Rectangle(Point(20.0, 8.0)),
                                    Rectangle(Point(12.0, 37.0)),
                                    Rectangle(Point(11.0, 15.0)),
                                    Rectangle(Point(40.0, 63.0)),
                                    Rectangle(Point(23.0, 6.0)),
                                    Rectangle(Point(16.0, 12.0)),
                                    Rectangle(Point(25.0, 20.0)),
                                    Rectangle(Point(67.0, 3.0)),
                                    Rectangle(Point(31.0, 29.0)),
                                    Rectangle(Point(12.0, 11.0)),
                                    Rectangle(Point(8.0, 9.0)),
                                    Rectangle(Point(3.0, 8.0)),
                                    Rectangle(Point(21.0, 13.0)),
                                    Rectangle(Point(46.0, 13.0)),
                                    Rectangle(Point(11.0, 75.0)),
                                    Rectangle(Point(4.0, 3.0)),
                                    Rectangle(Point(19.0, 7.0)),
                                    Rectangle(Point(33.0, 7.0)),
                                    Rectangle(Point(6.0, 16.0)),
                                    Rectangle(Point(21.0, 4.0)),
                                    Rectangle(Point(8.0, 8.0)),
                                    Rectangle(Point(3.0, 86.0)),
                                    Rectangle(Point(20.0, 6.0)),
                                    Rectangle(Point(21.0, 3.0)),
                                    Rectangle(Point(13.0, 59.0)),
                                    Rectangle(Point(4.0, 20.0))
};

std::vector<Rectangle> to_be_placed = gifts;
to_be_placed.insert(to_be_placed.begin(), tree_stand);
std::vector<Rectangle> already_placed;
std::vector<Rectangle> free_rectangles = {Rectangle(Point(100.0, 80.0))};




// (c)
double new_bssf, best_bssf;
int best_free, best_obj;
bool must_be_transposed = false;
Rectangle object;

while (true)
{
    best_bssf = big_number;
    for (int i = 0; i != free_rectangles.size(); i++)
    {
        for (int j = 0; j != to_be_placed.size(); j++)
        {
            new_bssf = bssf_score(free_rectangles[i], to_be_placed[j]);
            if (new_bssf < best_bssf)
            {
                best_bssf = new_bssf;
                best_free = i;
                best_obj = j;
            }           
// DEBUG:
// std::cout << "i: " << i << ", j: " << j << ", new_bssf: " << new_bssf << ", best_bssf: " << best_bssf << std::endl;
        }
    }

// Repeat for transposed gifts, remember if one of them fits better
    for (int i = 0; i != free_rectangles.size(); i++)
    {
        for (int j = 0; j != to_be_placed.size(); j++)
        {
            new_bssf = bssf_score(free_rectangles[i], to_be_placed[j].transpose());
            if (new_bssf < best_bssf)
            {
                best_bssf = new_bssf;
                best_free = i;
                best_obj = j;
                must_be_transposed = true;
            }
        }
    }


// If no gift fits, break the while loop
    if (best_bssf == big_number) break;

// If any gift fits, place it
    object = to_be_placed[best_obj];
    if (must_be_transposed) object = object.transpose();
    object = object.translate(free_rectangles[best_free].getP0());
    already_placed.push_back(object);
// Debug
//    std::cerr << best_obj << std::endl;
    to_be_placed.erase(to_be_placed.begin() + best_obj);
    free_rectangles.erase(free_rectangles.begin() + best_free);

//  SAS RULE
    free_rectangles.push_back( sas_rule(free_rectangles[best_free], to_be_placed[best_obj]).at(0) ) ;
    free_rectangles.push_back( sas_rule(free_rectangles[best_free], to_be_placed[best_obj]).at(1) ) ;

}  // END OF WHILE

// print already_placed
print_rect_vector(already_placed);


}  //END OF MAIN

double bssf_score(Rectangle const& free, Rectangle const& obj)
{
    double remaining_height = free.height() - obj.height();
    double remaining_width = free.width() - obj.width();

    if (remaining_height <= 0 || remaining_width <= 0) return big_number;

    return std::min(remaining_height, remaining_width);
}

std::vector<Rectangle> sas_rule (Rectangle const& free, Rectangle const& best)
{
    std::vector<Rectangle> rectangles;
    if (free.width() < free.height())
    {
        Rectangle rect1(Point(best.getX0(), best.getY0()+best.height()), free.getP1());
        Rectangle rect2(Point(best.getX0()+best.width(), best.getY0()), Point(free.getX1(), best.getY1()));
        rectangles.push_back(rect1);
        rectangles.push_back(rect2);
 
    }
    else
    {
        Rectangle rect1(Point(best.getX0(), best.getY0()+best.height()), free.getP1());
        Rectangle rect2(Point(best.getX0()+best.width(), best.getY0()), Point(free.getX1(), best.getY1()));
        rectangles.push_back(rect1);
        rectangles.push_back(rect2);
    }

       return rectangles;
}

void print_rect_vector(std::vector<Rectangle> vector)
{
    unsigned int n = 1;
    for (auto entry : vector) 
    {
        std::cout << "Gift no. " << n << ": ";
        entry.print();
        n++;
    }
}