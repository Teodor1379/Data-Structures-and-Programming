#include <array>


#include <limits>


#include <iostream>



constexpr unsigned int MAX = 1'00;



unsigned int readNumb();



void generate(std::array<char, MAX>&, unsigned int, unsigned int);



int main() {
    unsigned int number = readNumb();

    std::cout << std::endl;


    std::array<char, MAX> array = { 0 };
    
    generate(array, 0, number);


    return 0;
}



unsigned int readNumb() {
    unsigned int number = 0;

    while (true) {
        std::cout << "Enter the number: ";

        std::cin >> number;

        if (std::cin.fail() || number == 0 || number > MAX) {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;
        } else {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;

            return number;
        }
    }
}



void generate(std::array<char, MAX>& array, unsigned int index, unsigned int size) {
    if (index == size) {
        std::cout << "The generation is: ";

        for (unsigned int i = 0; i < size; ++i) {
            std::cout << array[i] << ' ';
        }

        std::cout << std::endl;

        return;
    }

    array[index] = '0'; generate(array, index + 1, size);
    array[index] = '1'; generate(array, index + 1, size);
}
