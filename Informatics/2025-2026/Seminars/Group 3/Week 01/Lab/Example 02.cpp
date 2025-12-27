#include <array>


#include <climits>


#include <limits>


#include <iostream>


#include <exception>
#include <stdexcept>



constexpr unsigned int MIN_INT = 0          ;
constexpr unsigned int MAX_INT = UINT_MAX   ;



constexpr unsigned int MAX = 100;



unsigned int readSize();



void inputArray(        std::array<unsigned int, MAX>&, unsigned int);
void printArray(const   std::array<unsigned int, MAX>&, unsigned int);



unsigned int findSum(const std::array<unsigned int, MAX>&, unsigned int);
unsigned int findPrd(const std::array<unsigned int, MAX>&, unsigned int);
unsigned int findMin(const std::array<unsigned int, MAX>&, unsigned int);
unsigned int findMax(const std::array<unsigned int, MAX>&, unsigned int);



int main() {
    unsigned int size = readSize();


    std::array<unsigned int, MAX> array = { 0 };

    inputArray(array, size);
    printArray(array, size);

    std::cout << std::endl;


    std::cout << "The SUM of the elements of the array is: " << findSum(array, size) << std::endl;
    std::cout << "The PRD of the elements of the array is: " << findPrd(array, size) << std::endl;
    std::cout << "The MIN of the elements of the array is: " << findMin(array, size) << std::endl; 
    std::cout << "The MAX of the elements of the array is: " << findMax(array, size) << std::endl;


    return 0;
}



unsigned int readSize() {
    unsigned int size = 0;

    while (true) {
        std::cout << "Enter the size of the array: ";

        std::cin >> size;

        if (std::cin.fail() || size == 0 || size > MAX) {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;
        } else {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;

            return size;
        }
    }
}



void inputArray(std::array<unsigned int, MAX>& array, unsigned int size) {
    if (size == 0) {
        throw std::invalid_argument("Invalid SIZE Argument!");
    }

    std::cout << "Enter the elements of the array: ";

    for (unsigned int i = 0; i < size; ++i) {
        std::cin >> array[i];
    }
}

void printArray(const std::array<unsigned int, MAX>& array, unsigned int size) {
    if (size == 0) {
        throw std::invalid_argument("Invalid SIZE Argument!");
    }

    std::cout << "The elements of the array are: ";

    for (unsigned int i = 0; i < size; ++i) {
        std::cout << array[i] << ' ';
    }

    std::cout << std::endl;
}



unsigned int findSum(const std::array<unsigned int, MAX>& array, unsigned int size) {
    // Time     Complexity: O(N)
    // Space    Complexity: O(1)

    if (size == 0) {
        throw std::invalid_argument("Invalid SIZE Argument!");
    }

    unsigned int result = 0;

    for (unsigned int i = 0; i < size; ++i) {
        result = result + array[i];
    }

    return result;
}

unsigned int findPrd(const std::array<unsigned int, MAX>& array, unsigned int size) {
    // Time     Complexity: O(N)
    // Space    Complexity: O(1)

    if (size == 0) {
        throw std::invalid_argument("Invalid SIZE Argument!");
    }

    unsigned int result = 1;

    for (unsigned int i = 0; i < size; ++i) {
        result = result * array[i];
    }

    return result;
}

unsigned int findMin(const std::array<unsigned int, MAX>& array, unsigned int size) {
    // Time     Complexity: O(N)
    // Space    Complexity: O(1)

    if (size == 0) {
        throw std::invalid_argument("Invalid SIZE Argument!");
    }

    unsigned int result = MAX_INT;

    for (unsigned int i = 0; i < size; ++i) {
        result = std::min(result, array[i]);
    }

    return result;
}

unsigned int findMax(const std::array<unsigned int, MAX>& array, unsigned int size) {
    // Time     Complexity: O(N)
    // Space    Complexity: O(1)

    if (size == 0) {
        throw std::invalid_argument("Invalid SIZE Argument!");
    }

    unsigned int result = MIN_INT;

    for (unsigned int i = 0; i < size; ++i) {
        result = std::max(result, array[i]);
    }

    return result;
}
