#include <limits>


#include <iostream>



unsigned int readNumber();



unsigned int countWays(unsigned int);



int main() {
    unsigned int number = readNumber();


    std::cout << "The number of ways is: " << countWays(number) << std::endl;


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



unsigned int countWays(unsigned int number) {
    if (number == 0) { return 0; }
    if (number == 1) { return 1; }
    if (number == 2) { return 2; }

    return
        countWays(number - 1)   +
        countWays(number - 2);
}
