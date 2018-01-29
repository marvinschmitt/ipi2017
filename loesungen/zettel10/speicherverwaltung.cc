
// Funktion 1
int pp () {
    int *a = new int;
    *a = 5;
    a = new int;    // das geht nicht. was sollte damit auch gemacht werden!? 
    return *a;
}

// Funktion 2
// Problem: ret kann nie false werden. Kann behoben werden, indem es mit false initialisiert wird.
bool is_large_number ( int z) 
{
    bool ret ; // bool ret = false;
    if (z > 1000)
        ret = true;
    return ret ;
}

// Funktion 3
int quad_array (int n) 
{
    int *z = new int[n];
    for (int i = 0; i < n; i++) 
    {
        z[i] = i*i;
    }
    int ret = z[n];     // z[n] ist nicht initialisiert, da die for-SChleife nur bis z[n-1] geht. Lösung: for-Abbruchbedingung auf i<=n ändern.) Aber auch dann wird nur der letzte Wert des Arrays zurück gegeben.
    delete [] z;
    return ret ;
}


// Funktion 5
int* set_variable (int z) 
{
    int *n = new int;
    *n = z;
    delete n;
    return n;   // n wird deleted und dann erst returned. Lösung: neuen Pointer ret anlegen, mit n initialisieren, dann n deleten und ret zurückgeben
}

// Funktion 6
float * lv( float f) 
{
    f *= 2.0;
    return &f; //wieso wird hier die Adresse von f zurückgegeben!? Lösung: return f und Funktion vom Typ float und nicht float* machen.
}