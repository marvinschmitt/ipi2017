#include <iostream>
#include "mylist.h"
#include <string>
#include <time.h>
#include <vector>
#include <list>

using namespace std;


int main()
{
    double tstart, tstop, time;
    vector<double> my_list_time, my_list_stl_time;

for (int N = 20000; N <= 100000; N = N+20000)
{
    tstart = clock();

// Code für selbst implementierte Liste
    // Liste erstellen
    myList my_list;
    // Liste mit Daten füllen
    for (int i = 0; i < N; ++i)
    {
        my_list.push_back(i+1);
    }
    // Ueberpruefen, dass die Liste nicht leer ist
    if (my_list.isEmpty())
    {
        cerr << "Die Liste ist leer!" << endl;
    }
    // Liste durchlaufen und ausgeben
    for (myList::Iterator it = my_list.first(); it!=my_list.last(); ++it)
    {
    // cout << it.printValue() << "  ";
        cout << *it << "  ";    // spart viel Zeit im Vergleich zum Schritt über den String... Dann ist die STL gar nicht mehr schneller!
    }
    cout << "\n";
    // Liste löschen
    my_list.remove();

    tstop = clock();
    time = tstop - tstart;
    my_list_time.push_back(time);




    tstart = clock();
//  Code für STL-Liste

    std::list<double> my_stl_list;
    // Liste mit Daten füllen
    for (int i = 0; i < N; ++i)
    {
        my_stl_list.push_back(i+1);
    }
    // Ueberpruefen, dass die Liste nicht leer ist
    if (my_stl_list.empty())
    {
        cerr << "Die Liste ist leer!" << endl;
    }
    // Liste durchlaufen und ausgeben
    for (auto it = my_stl_list.begin(); it!=my_stl_list.end(); ++it)
    {
        cout << *it << "  ";
        // (*it)++;
    }
    cout << "\n";
    // Liste löschen
    my_stl_list.clear();


    tstop = clock();
    time = tstop - tstart;
    my_list_stl_time.push_back(time);
}

    cout << endl << endl;
    cout.width(10);
    cout << "SIZE";
    cout.width(10);
    cout << "MY LIST";
    cout.width(10);
    cout << "STL LIST" << endl;
    int m = 20000;

    for (unsigned int i = 0; i < my_list_time.size(); ++i)
    {
        cout.width(10);
        cout << m;
        cout.width(10);
        cout << my_list_time.at(i);
        cout.width(10);
        cout << my_list_stl_time.at(i) << endl;
        m += 20000;
    }

    return 0;

}


//  Algorithmische Komplexität liegt in f(n) - Laufzeit steigt linear mit der Datengröße.
//  die STL-Liste ist aber durchweg schneller als die selbst implementierte.
//  Anmerkung: Wenn ich einen Deferenzierungsoperator auf dem Iterator überlade, ist die selbst implementierte Liste sogar schneller als die STL-Liste!