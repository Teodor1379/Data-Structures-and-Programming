#include <array>


#include <limits>


#include <iostream>



constexpr unsigned int MIN_SIZE = 0     ;
constexpr unsigned int MAX_SIZE = 100   ;



unsigned int readSize();



void generateDigits(std::array<char, MAX_SIZE>&, unsigned int, unsigned int);



int main() {
    unsigned int size = readSize();

    std::cout << std::endl;


    std::array<char, MAX_SIZE> array = { 0 };
    
    generateDigits(array, 0, size);


    return 0;
}



unsigned int readSize() {
    unsigned int size = 0;

    while (true) {
        std::cout << "Enter the size: ";

        std::cin >> size;

        if (std::cin.fail() || size == MIN_SIZE || size > MAX_SIZE) {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;
        } else {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;

            return size;
        }
    }
}



void generateDigits(std::array<char, MAX_SIZE>& array, unsigned int index, unsigned int size) {
    if (size == MIN_SIZE || size > MAX_SIZE) { throw std::invalid_argument("Invalid SIZE Argument!");   }

    if (index == size) {
        std::cout << "The generation is: ";

        for (unsigned int i = 0; i < size; ++i) {
            std::cout << array[i] << ' ';
        }

        std::cout << std::endl;

        return;
    }

    array[index] = '0'; generateDigits(array, index + 1, size);
    array[index] = '1'; generateDigits(array, index + 1, size);
    array[index] = '2'; generateDigits(array, index + 1, size);
}
