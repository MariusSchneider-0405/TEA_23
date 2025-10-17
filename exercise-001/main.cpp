#include <fmt/chrono.h>
#include <fmt/format.h>

#include "config.h"
/*--------Teil 1 ----------*/
int globalVar = 1;
int Geburtstag = 4052004;
int Alter = 21; 
static int aaa = 1212;
static int bbb = 3343;
const int ccc = 120;
const int ddd = 815;

void foo() 
    { fmt::print("\n\nHello from foo!\n"); }

int main(int argc, char **argv) {

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    /*-----Teil 2 ------*/
    const int localVar = 2; 

    /*-----Teil 3 ------*/
    int* heapVar = new int(3);

    /*-----Teil 4 ------*/



    fmt::print("Hello, {}!\n", tea::PROJECT_NAME);
    fmt::print("Wert: {}, \nAdresse: {}", globalVar, fmt::ptr(&globalVar) );
    fmt::print("\nGeburtstag: {}, \nAlter: {}, \nAdresse Geburtstag: {}, \nAdresse Alter: {}", Geburtstag, Alter, fmt::ptr(&Geburtstag), fmt::ptr(&Alter));
    fmt::print("\nWert: {}, Adresse: {}", aaa, fmt::ptr(&aaa));
    fmt::print("\nWert: {}, Adresse: {}", bbb, fmt::ptr(&bbb));
    fmt::print("\nWert: {}, Adresse: {}", ccc, fmt::ptr(&ccc));
    fmt::print("\nWert: {}, Adresse: {}", ddd, fmt::ptr(&ddd));
    fmt::print("\nWert: {}, Adresse: {}", localVar, fmt::ptr(&localVar));
    fmt::print("\nWert {}, Adresse: {}", *heapVar, fmt::ptr(&heapVar));
    /* INSERT YOUR CODE HERE */

    delete heapVar; 

    /*----Teil 4----*/
    foo();
    fmt::print("Adresse von foo: {}\n", fmt::ptr(&foo));

    return 0; /* exit gracefully*/
}
/*
------------------------------------------------------------------------------
%% ----------------- Fazit: Speichersegmente in C++ ------------------------%%
------------------------------------------------------------------------------

In C++ werden Daten je nach Art in verschiedene Speicherbereiche gelegt:

    - Globale und statische Variablen liegen im Datensegment.
    Initialisierte Werte kommen ins .data-, nicht initialisierte ins .bss-Segment.
    const-Daten befinden sich im schreibgeschützten Bereich (.rodata).

    - Lokale Variablen liegen auf dem Stack.
    Er wird automatisch verwaltet und ist sehr schnell.
    Mit static bleibt eine lokale Variable jedoch dauerhaft im Datensegment.

    - Dynamisch erzeugte Variablen (mittels new) liegen im Heap, der manuell mit delete verwaltet werden muss.

    - Funktionen liegen im Code-Segment, wo der ausführbare Programmcode gespeichert ist.

-------------
Wichtig: !!!
-------------
Stack und Heap unterscheiden sich in Lebensdauer und Verwaltung.
Zeiger sind notwendig, um auf Speicher im Heap zuzugreifen und machen sichtbar, wo Daten tatsächlich liegen.
--------------------------------------------------------------------------------------------------------------------

Skizze Arbeitsspeicher: 

+------------------------+
| Code-Segment (Text)    |  → Funktionen, ausführbarer Code
+------------------------+
| Data-Segment           |  → globale/statische Variablen
|  - .data (init)        |
|  - .bss (uninit)       |
|  - .rodata (const)     |
+------------------------+
| Heap                   |  → dynamisch angeforderter Speicher (new/delete)
|         ↑ wächst nach oben
+------------------------+
| Stack                  |  → lokale Variablen, Funktionsaufrufe
|         ↓ wächst nach unten
+------------------------+

*/