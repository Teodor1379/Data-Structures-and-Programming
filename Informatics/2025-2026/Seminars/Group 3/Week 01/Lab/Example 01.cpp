#include <climits>


#include <limits>


#include <iostream>



int readNumber(const std::string&);



int functionMin(int, int, int);
int functionMax(int, int, int);
int functionAvg(int, int, int);



int main() {
    int number1 = readNumber("1");
    int number2 = readNumber("2");
    int number3 = readNumber("3");

    
    std::cout << "The MIN number is: " << functionMin(number1, number2, number3) << std::endl;
    std::cout << "The MAX number is: " << functionMax(number1, number2, number3) << std::endl;
    std::cout << "The AVG number is: " << functionAvg(number1, number2, number3) << std::endl;


    return 0;
}



int readNumber(const std::string& message) {
    int result = 0;

    while (true) {
        std::cout << "Enter number " << message << ": ";

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



int functionMin(int x, int y, int z) {
    // Time     Complexity: O(1)
    // Space    Complexity: O(1)

    int result = INT_MAX;

    result = std::min(result, x);
    result = std::min(result, y);
    result = std::min(result, z);

    return result;
}

int functionMax(int x, int y, int z) {
    // Time     Complexity: O(1)
    // Space    Complexity: O(1)

    int result = INT_MIN;

    result = std::max(result, x);
    result = std::max(result, y);
    result = std::max(result, z);

    return result;
}

int functionAvg(int x, int y, int z) {
    // Time     Complexity: O(1)
    // Space    Complexity: O(1)

    int a = std::min(x, std::min(y, z));
    int b = std::max(x, std::max(y, z));

    return (x + y + z) - (a + b);
}
