#include <iostream>
#include <fstream>
#include <string>

int main() {
   
    const std::string filename = "example.txt";
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Error opening file for writing." << std::endl;
        return 1;
    }

  
    outFile << "Hello, World!" << std::endl;
    outFile << "This is a simple file I/O example." << std::endl;
    outFile << "C++ file handling is straightforward!" << std::endl;

    outFile.close();

    std::ifstream inFile(filename);

    if (!inFile) {
        std::cerr << "Error opening file for reading." << std::endl;
        return 1;
    }

    std::string line;
    std::cout << "Contents of the file:" << std::endl;
    while (std::getline(inFile, line)) {
        std::cout << line << std::endl;
    }

    inFile.close();

    return 0;
}
