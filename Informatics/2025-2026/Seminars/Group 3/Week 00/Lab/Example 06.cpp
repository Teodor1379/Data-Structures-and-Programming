#include <limits>


#include <iostream>



unsigned int readNumber();



unsigned int countWaysH(unsigned int, unsigned int, unsigned int);
unsigned int countWaysR(unsigned int                            );



int main() {
    unsigned int number = readNumber();


    std::cout << "The number of ways is: " << countWaysR(number) << std::endl;


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



unsigned int countWaysH(unsigned int number1, unsigned int number2, unsigned int number3) {
    if (number3 == 1) { return number1; }
    if (number3 == 2) { return number2; }

    return countWaysH(number2, number1 + number2, number3 - 1);
}

unsigned int countWaysR(unsigned int number) {
    if (number == 0) {
        return 0;
    }

    return countWaysH(1, 2, number);
}
