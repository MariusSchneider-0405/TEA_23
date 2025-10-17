#include <fmt/chrono.h>
#include <fmt/format.h>

#include "config.h"

int main(int argc, char **argv) {

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", tea::PROJECT_NAME, tea::PROJECT_VER);

//Teil 0:
    for ( int i = 0; i < argc; i++) {
        fmt::println("argc: {}, argument: {}, (Adresse: {})", i, argv[i], fmt::ptr(argv[i]));
    }

    /* INSERT YOUR CODE HERE */
//Teil 1:
    int foo = 10;

    int* ptr = &foo;

    *ptr = 42;

    int bar = 4711;
    ptr = &bar;
    *ptr = foo;
    fmt::print("bar = {}", bar) ;

//Teil 2:
    fmt::println("\n ----------------Teil 2: Speicherreservierung --------------------");
    double* d = new double(3.1415);   // Speicher reservieren UND initialisieren
    fmt::println("\nWert: {}, Adresse: {}", *d, fmt::ptr(d) );    // Zugriff über Dereferenzierung
    delete d;                         // Speicher freigeben



    return 0; /*exit gratefully*/
}

//Teil 3:

void changeValueByParameter(int value) {
    value = 4711;
    fmt::println("Der Wert von Value in der Funktion (ChangeValuePyParameter): {}", value);
    }
void changeValueByPointer(int* ptr) {
    *ptr = 4711;
    fmt::println("Der wert von *ptr in der Funktion (changeValueByPointer): {}", *ptr);
    fmt::println("Die Adresse von ptr in der Funktion (changeValueByPointer): {}", fmt::ptr(ptr));
    }