#include <fmt/chrono.h>
#include <fmt/format.h>

#include "config.h"

int globalVar = 1;
int Geburtstag = 4052004;
int Alter = 21; 
static int aaa = 1212;
static int bbb = 3343;
const int ccc = 120;
const int ddd = 815;

int main(int argc, char **argv) {

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    const int localVar = 2; 

    fmt::print("Hello, {}!\n", tea::PROJECT_NAME);
    fmt::print("Wert: {}, \nAdresse: {}", globalVar, fmt::ptr(&globalVar) );
    fmt::print("\nGeburtstag: {}, \nAlter: {}, \nAdresse Geburtstag: {}, \nAdresse Alter: {}", Geburtstag, Alter, fmt::ptr(&Geburtstag), fmt::ptr(&Alter));
    fmt::print("\nWert: {}, Adresse: {}", aaa, fmt::ptr(&aaa));
    fmt::print("\nWert: {}, Adresse: {}", bbb, fmt::ptr(&bbb));
    fmt::print("\nWert: {}, Adresse: {}", ccc, fmt::ptr(&ccc));
    fmt::print("\nWert: {}, Adresse: {}", ddd, fmt::ptr(&ddd));
    fmt::print("\nWert: {}, Adresse: {}", localVar, fmt::ptr(&localVar));
    /* INSERT YOUR CODE HERE */

    return 0; /* exit gracefully*/
}
