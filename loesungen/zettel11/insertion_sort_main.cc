#include <iostream>
#include <vector>
#include <string>

template < class T>
void insertion_sort(std::vector<T>& A)
{
    T key;
    int i = 0;
    for (int j = 1; j < A.size(); j++)  // Indizierung fängt hier ja bei 0 an
    {
        key = A[j];

        i = j-1;
        while (i >= 0 && A[i] > key)    // >= 0, weil Indizierung bei 0 anfängt.
        {
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
    }
}


template <class T>
void print(std::vector<T> vec)
{
    std::cout << "{";
    for (auto i = 0; i < vec.size()-1; i++)
        std::cout << vec.at(i) << ", ";      // print all elements but the last, so commas look nice
    std::cout << vec.at(vec.size()-1);    // print last element
    std::cout << "}" << std::endl;
}


int main()
{
    // std::vector<int> v0 = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    std::vector<double> v1 = {12., -5., 8., 0., -1., 20., 9.};
    std::vector<std::string> v2 = {"h", "a", "l", "l", "o"};
    std::vector<int> v3 = {2, 5, 4, -7, 12, 1};
    std::vector<bool> v4 = {false, true, false};
    std::vector<char> v5 = {'h', 'a', 'l', 'l', 'o'};

    // print(v0);
    // insertion_sort(v0);
    // print(v0);
    // std::cout << std::endl;

    print(v1);
    insertion_sort(v1);   
    print(v1); 
    std::cout << std::endl;

    print(v2); 
    insertion_sort(v2); 
    print(v2); 
    std::cout << std::endl;

    print(v3); 
    insertion_sort(v3); 
    print(v3); 
    std::cout << std::endl;

    print(v4); 
    insertion_sort(v4); 
    print(v4); 
    std::cout << std::endl;

    print(v5);
    insertion_sort(v5);
    print(v5);
  
}

// AUFGABENTEIL (d)
// Um Insertion Sort auf einer Liste zu implementieren, muss man entsprechend die Pointer verschieben.
// In der while-Schleife steht dann nicht  "A[i+1] = A[i];i--;"  , sondern der next-pointer bzw. previous-pointer
// der Elemente wird geändert, sodass die Struktur der Liste (Reihenfolge durch Pointer) sich ranggereiht ändert.



