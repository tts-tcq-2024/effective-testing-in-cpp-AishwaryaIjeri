#include <iostream>
#include <sstream>
#include <assert.h>

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            std::cout << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[i] << "\n";
        }
    }
    return i * j;
}

std::string captureOutput() {
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
    printColorMap();
    std::cout.rdbuf(old);
    return buffer.str();
}

void testPrintColorMap() {
    std::string output = captureOutput();
    std::string expectedOutput = "0 | White | Blue\n1 | White | Blue\n2 | White | Blue\n3 | White | Blue\n4 | White | Blue\n"
                                 "5 | Red | Red\n6 | Red | Red\n7 | Red | Red\n8 | Red | Red\n9 | Red | Red\n"
                                 "10 | Black | Black\n11 | Black | Black\n12 | Black | Black\n13 | Black | Black\n14 | Black | Black\n"
                                 "15 | Yellow | Yellow\n16 | Yellow | Yellow\n17 | Yellow | Yellow\n18 | Yellow | Yellow\n19 | Yellow | Yellow\n"
                                 "20 | Violet | Violet\n21 | Violet | Violet\n22 | Violet | Violet\n23 | Violet | Violet\n24 | Violet | Violet\n";
    assert(output == expectedOutput);  // This test is meant to fail
}

int main() {
    testPrintColorMap();
    std::cout << "All tests passed!\n";
    return 0;
}
