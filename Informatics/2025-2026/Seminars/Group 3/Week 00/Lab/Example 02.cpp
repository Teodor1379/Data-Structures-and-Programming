#include <array>

#include <string>


#include <limits>

#include <iostream>



const unsigned int MAX_ROWS = 1'00;
const unsigned int MAX_COLS = 1'00;



unsigned int    readNumb(                   );
unsigned int    readSize(const std::string& );



void inputMatrix(       std::array<std::array<int, MAX_COLS>, MAX_ROWS>&, unsigned int, unsigned int);
void printMatrix(const  std::array<std::array<int, MAX_COLS>, MAX_ROWS>&, unsigned int, unsigned int);



void            traverseMatrix(std::array<std::array<int, MAX_COLS>, MAX_ROWS>&, unsigned int, unsigned int, unsigned int, unsigned int );
unsigned int    traverseIsland(std::array<std::array<int, MAX_COLS>, MAX_ROWS>&, unsigned int, unsigned int                             );



int main(void) {
    unsigned int number = readNumb();



    unsigned int rows = readSize("ROWS");
    unsigned int cols = readSize("COLS");

    std::array<std::array<int, MAX_COLS>, MAX_ROWS> matrix;


    inputMatrix(matrix, rows, cols);
    printMatrix(matrix, rows, cols);



    if (traverseIsland(matrix, rows, cols) == number) {
        std::cout << "You are       right!" << std::endl;
    } else {
        std::cout << "You are not   right!" << std::endl;
    }



    return 0;
}



unsigned int readNumb() {
    unsigned int number = 0;

    while (true) {
        std::cout << "Enter the number: ";

        std::cin >> number;

        if (std::cin.fail()) {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;
        } else {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;

            return number;
        }
    }
}

unsigned int readSize(const std::string& string) {
    unsigned int size = 0;

    while (true) {
        std::cout << "Enter the " << string << " size: ";

        std::cin >> size;

        if (std::cin.fail() || size == 0) {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;
        } else {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;

            return size;
        }
    }
}



void inputMatrix(std::array<std::array<int, MAX_COLS>, MAX_ROWS>& matrix, unsigned int rows, unsigned int cols) {
    if (rows > MAX_ROWS) { throw std::invalid_argument("Invalid ROWS Argument!");   }
    if (cols > MAX_COLS) { throw std::invalid_argument("Invalid COLS Argument!");   }

    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < cols; ++j) {
            std::cin >> matrix[i][j];
        }
    }
}

void printMatrix(const std::array<std::array<int, MAX_COLS>, MAX_ROWS>& matrix, unsigned int rows, unsigned int cols) {
    if (rows > MAX_ROWS) { throw std::invalid_argument("Invalid ROWS Argument!");   }
    if (cols > MAX_COLS) { throw std::invalid_argument("Invalid COLS Argument!");   }

    std::cout << "The matrix is: " << std::endl;

    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << ' ';
        }

        std::cout << '\n';
    }
}



void traverseMatrix(std::array<std::array<int, MAX_COLS>, MAX_ROWS>& matrix, unsigned int rows, unsigned int cols, unsigned int row, unsigned int col) {
    if (rows > MAX_ROWS) { throw std::invalid_argument("Invalid ROWS Argument!");   }
    if (cols > MAX_COLS) { throw std::invalid_argument("Invalid COLS Argument!");   }

    if (row >= rows || col >= cols) {
        return;
    }

    if (matrix[row][col] == 0) {
        return;
    }

    matrix[row][col] = 0;

    traverseMatrix(matrix, rows, cols, row - 1, col);
    traverseMatrix(matrix, rows, cols, row + 1, col);
    traverseMatrix(matrix, rows, cols, row, col - 1);
    traverseMatrix(matrix, rows, cols, row, col + 1);
}

unsigned int traverseIsland(std::array<std::array<int, MAX_COLS>, MAX_ROWS>& matrix, unsigned int rows, unsigned int cols) {
    if (rows > MAX_ROWS) { throw std::invalid_argument("Invalid ROWS Argument!");   }
    if (cols > MAX_COLS) { throw std::invalid_argument("Invalid COLS Argument!");   }

    unsigned int result = 0;

    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < cols; ++j) {
            if (matrix[i][j]) {
                traverseMatrix(matrix, rows, cols, i, j);

                result = result + 1;
            }
        }
    }

    return result;
}
