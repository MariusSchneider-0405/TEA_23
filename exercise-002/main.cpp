#include <fmt/chrono.h>
#include <fmt/format.h>

/*Aufgabe 2*/
/*Beispiel 1 */
#include <cstdlib>
#include <cstring>

// #define SOULS 100

// void cursed() {
//      char *soul = (char*)malloc(8);
//      strcpy(soul, "boo!");
//      fmt::println("{}", soul);
//      free(soul);
//  }

//  int main() {
//      for(int i=0; i < SOULS; i++) {
//          cursed();
//      }
//  }

// /*Beispiel 2*/
//  int main() {
//      char *ghost = (char*)malloc(8);
//      strcpy(ghost, "evil");
//      free(ghost);
//      fmt::println("{}", ghost);
//      ghost = NULL;
//  }

/*Beispiel 3*/
int main() {
    while (1) {
        malloc(1024);
    }
}


/*Aufgabe 1*/
/* 1. Es entsteht ein (zombie-)Pointer
2. Undefined behaviour 
3. Stack Overflow
4. Memory Leak */

/* Welche Fehler sind in echten Mikrocontrollersystemen besonders Kritisch?
Memory Leaks und Stack Overflows, da meist kein Betriebssystem und nur begrenzter Speicher vorhanden ist 
--> Fehler können zu Systemabstürzen der seltsamen Verhalten*/

/*Aufgabe 4*/
/*1. Wann tritt ein Stack Overflow auf?

Ein Stack Overflow passiert, wenn der Aufrufstapel (Stack) überläuft – also mehr Speicher benutzt wird, als für den Stack reserviert ist.
Typische Ursachen:

Zu tiefe Rekursion (eine Funktion ruft sich selbst zu oft auf)

Sehr große lokale Variablen (z. B. große Arrays auf dem Stack)

Endlosschleifen mit Funktionsaufrufen

2. Warum entstehen Memory Leaks?

Ein Memory Leak (Speicherleck) entsteht, wenn dynamisch (z. B. mit malloc() oder new) Speicher angefordert, aber nicht wieder freigegeben wird (free() bzw. delete fehlt).
Dadurch bleibt der Speicher belegt, bis das Programm endet — auf Mikrocontrollern mit wenig RAM kann das schnell kritisch werden.

3. Was ist gefährlicher: Ein Zombie-Pointer oder ein Leak?

Ein Zombie-Pointer (Dangling Pointer) ist gefährlicher, weil er auf Speicher zeigt, der nicht mehr gültig ist – jede Nutzung kann zu unvorhersehbarem Verhalten oder Abstürzen führen.
Ein Leak verschwendet zwar Speicher, verursacht aber nicht sofort falsches Verhalten.

4. Wie kann man solche Fehler frühzeitig erkennen?

Möglichkeiten:

- Statische Analyse-Tools (z. B. clang-tidy, cppcheck)
- Dynamische Debugging-Tools (z. B. valgrind, AddressSanitizer)
- Stack-Guards und Watchdogs auf Mikrocontrollern
- Saubere Programmierdisziplin (Initialisierung, Freigabe, NULL setzen)
- Unit Tests und Code Reviews

Diagramm des Speichers:
-------------------------------------------------------------------
+-------------------------+  ← hohe Speicheradresse
|      Stack              |  (lokale Variablen, Funktionsaufrufe)
|      ↓ wächst nach unten|
+-------------------------+
|      Heap               |  (malloc/new - dynamische Daten)
|      ↑ wächst nach oben |
+-------------------------+
|   Daten-Segment (.data) |  (globale & statische Variablen)
+-------------------------+
|   Code-Segment (.text)  |  (Programmcode, Funktionen)
+-------------------------+  ← niedrige Speicheradresse

*/
