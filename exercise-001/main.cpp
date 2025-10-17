#include <fmt/chrono.h>
#include <fmt/format.h>

#include "config.h"

int globalVar = 1;
int Geburtstag = 4052004;
int Alter = 21; 

int main(int argc, char **argv) {

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", tea::PROJECT_NAME);
    fmt::print("Wert: {}, \nAdresse: {}", globalVar, fmt::ptr(&globalVar) );
    fmt::print("\nGeburtstag: {}, \nAlter: {}, \nAdresse Geburtstag: {}, \nAdresse Alter: {}", Geburtstag, Alter, fmt::ptr(&Geburtstag), fmt::ptr(&Alter));
    /* INSERT YOUR CODE HERE */

    return 0; /* exit gracefully*/
}
