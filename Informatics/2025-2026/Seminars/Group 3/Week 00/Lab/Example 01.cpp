#include <limits>


#include <iostream>



unsigned int    readNumber();



unsigned int recursion1(unsigned int);
unsigned int recursion2(unsigned int);

unsigned int recursion3(unsigned int, unsigned int);
unsigned int recursion4(unsigned int, unsigned int);



void printAly(unsigned int);
void printTeo(unsigned int);



int main() {
    unsigned int number = readNumber();


    std::cout << "Recursion Result 1 is: " << recursion1(number) << std::endl;
    std::cout << "Recursion Result 2 is: " << recursion2(number) << std::endl;

    std::cout << "Recursion Result 3 is: " << recursion3(number, 0) << std::endl;
    std::cout << "Recursion Result 4 is: " << recursion4(number, 1) << std::endl;


    printAly(number);
    printTeo(number);

    return 0;
}



unsigned int readNumber() {
    unsigned int result = 0;

    while (true) {
        std::cout << "Enter the number: ";

        std::cin >> result;

        if (std::cin.fail()) {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;
        } else {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;

            return result;
        }
    }
}



unsigned int recursion1(unsigned int number) {
    if (number == 0) {
        return 0;
    }

    return 1 + recursion1(number - 1);
}

unsigned int recursion2(unsigned int number) {
    if (number < 1) {
        return 1;
    }

    return 2 * recursion2(number - 1);
}



unsigned int recursion3(unsigned int number, unsigned int result) {
    if (number == 0) {
        return result;
    }

    return recursion3(number - 1, result + 1);
}

unsigned int recursion4(unsigned int number, unsigned int result) {
    if (number < 1) {
        return result;
    }

    return recursion4(number - 1, result * 2);
}



void printAly(unsigned int number) {
    if (number == 0) {
        std::cout << std::endl;

        return;
    }

    std::cout << "A";

    printTeo(number - 1);
}

void printTeo(unsigned int number) {
    if (number == 0) {
        std::cout << std::endl;

        return;
    }

    std::cout << "T";

    printAly(number - 1);
}
