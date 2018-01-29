#include <iostream>
#include <string>
using namespace std;


class Room {
public:
  string name;                          // Name des Raums, wird bei der Initialisierung mitgegeben
  Room *North, *South, *East, *West;    // Pointer auf die Rooms im Norden, Süden, Osten und Westen des Raums
  Room (string n) {name = n; North = this; South = this; East = this; West = this;};  // Initialisierung mit Namen, N O S W zeigen zunächst auf diesen Raum.

  void textOutput()
  {
    cout << "Sie sind im " << this->name << ". Es gibt Wege nach";
      if (this->East != this) cout << " O";
      if (this->West != this) cout << " W";
      if (this->North != this) cout << " N";
      if (this->South != this) cout << " S";
    cout << ". Wohin? (X:exit)" << endl;
  }
};

int main() 
{
  Room r1("Bad");
  Room r2("Schlafzimmer");
  Room r3("Wohnzimmer");
  Room r4("Esszimmer");
  Room r5("Flur");
  Room r6("Küche");
  Room r7("Ausgang");
  r1.North = &r2; r1.East = &r5;      // Pointer müssen mit Referenzen bestückt werden.
  r2.South = &r1; r2.East = &r3;
  r3.West = &r2;  r3.South = &r5; r3.East = &r4;
  r4.West = &r3;  r4.South = &r6;
  r5.West = &r1;  r5.North = &r3; r5.East = &r6;  r5.South = &r7;
  r6.West = &r5;  r6.North = &r4;
  r7.North = &r5;   // Eigentlich nicht nötig, aber der Vollständigkeit halber... 
  // Room * here = &r1;      // Definition des here-Pointers, der auf den aktuellen Standpunkt zeigt. Start ist also im Bad (r1).
  Room * here = &r2;    // AUFGABENTEIL (c): Start jetzt im Schlafzimmer
  bool done = false;
  do {
    here->textOutput();
    string in;
    cin >> in;
    switch (toupper(in[0]))            // in[0] ist der erste Buchstabe der Eingabe.
    {
      case 'N': here = here->North; break;  // toupper() konvertiert zu einem Großbuchstaben
      case 'S': here = here->South; break;
      case 'O': here = here->East; break;
      case 'W': here = here->West; break;
      default: done = true; cout << "Tschuess!\n"; break;
    }
    if (here->name == "Ausgang") 
    {
      done = true;
      cout << "Herzlichen Glückwunsch, Sie haben den Ausgang erreicht!" << endl;
    }
  } while (!done);
}


/*





AUFGABENTEIL (b), Start im Bad (r1)
---------------------------------------------------------
|                 |                  |                  |
|                 |                  |                  |
|       r2                 r3                 r4        |
| SCHLAFZIMMER    |    WOHNZIMMER    |    ESSZIMMER     |                                                     
|                 |                  |                  |
|______     ______|______     _______|______     _______|
|                 |                  |                  |
|       r1                r5                 r6         |
|       BAD              FLUR               KÜCHE       |
|      start      |                  |                  |
|                 |                  |                  |
-------------------------    ----------------------------
                       AUSGANG







*/