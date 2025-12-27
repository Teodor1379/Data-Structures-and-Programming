#include <limits>


#include <iostream>



constexpr unsigned int MAX = 100;



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

        if (std::cin.fail() || result > MAX) {
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
    unsigned int dp[MAX] = { 0 };

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for (unsigned int i = 3; i <= number; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[number];
}
