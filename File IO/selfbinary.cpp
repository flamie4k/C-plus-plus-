#include <iostream>
#include <fstream>

int main() {
    // Open the source code file
    std::ifstream sourceFile("source.cpp", std::ios::binary);

    // Check if the source file is open
    if (!sourceFile.is_open()) {
        std::cerr << "Error opening the source file.\n";
        return 1;
    }

    // Open a binary file for writing
    std::ofstream binaryFile("binary_output.bin", std::ios::binary);

    // Check if the binary file is open
    if (!binaryFile.is_open()) {
        std::cerr << "Error opening the binary file.\n";
        return 1;
    }

    // Read and write each character from the source file to the binary file
    char ch;
    while (sourceFile.get(ch)) {
        binaryFile.put(ch);
    }

    // Close the files
    sourceFile.close();
    binaryFile.close();

    std::cout << "Program successfully stored in binary file.\n";

    return 0;
}
