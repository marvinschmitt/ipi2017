#include "simpletests.h"
#include "palindrome.h"
#include <fstream>

// Einfaches Beispiel zum Gebrauch der simpletests
int main() {
    int i = 5;
    test(i == 4);
    test(i == 5);
    test_eq(i, 3+1);
    test_eq(i, 3+2);
    test_eq(5+i, 7+1);
    
    std::string h("hallo");
    test_eq(h, "h");
    test_eq(h, "hallo");
    test_eq("hallo",h);


    std::string s = "";
    std::string file = "words.txt";
    bool result_own = false, result_given = false;
    std::ifstream in(file);
    // Geht davon aus, dass die Wörter (wie auf dem Zettel) alle lowercase sind. Ansonsten müsste man noch über den string iterieren und s[i] mit tolower(s[i]) substituieren.
    while (in >> s)
    {
        result_own = is_palindrome(s);
        result_given = (s == reverse_string(s));
//  Wie sollen wir hier sinnvoll die Testumgebung nutzen ohne sie zu verändern? Am liebsten würde ich folgenden Ausdruck evaluieren:
//  test(is_palindrome(s) == test(s, reverse_string(s)));
//  Das testet mit der Umgebung, ob meine Palindrom-Funktion dasselbe Ergebnis auswirft wie die Äquivalenztestung von string und der gegebenen Funktion auf dem Zettel.

//  Hier wird einmal ein Output gegeben (1. Test) und dann die Palindrom-Funktion getestet (2. Test)
        test_eq(s, reverse_string(s));
        test_eq(result_own, result_given);
    }
 
	simpletests::test_result();
	return 0;
}
