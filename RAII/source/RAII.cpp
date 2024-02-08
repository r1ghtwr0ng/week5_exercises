#include <cstdio>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include "FileManager.h"

int factorial(int n)
{
        return n == 0 ? 1 : n * factorial(n-1);
}

void printProcessedFile(std::string fileName)
{
    FILE *f = std::fopen(fileName.c_str(), "rw");
    if(!f) {
        std::string err_msg = "Failed to open file " + fileName;
        throw std::runtime_error(err_msg);
    }
    std::cout << "File opened." << std::endl;

    int n;
    while (std::fscanf(f, "%d", &n) != EOF)
    {
        std::cout << n << "! = " << factorial(n) << std::endl;
    }

    if (f)
    {
        std::fclose(f);
        std::cout << "File closed." << std::endl;
    }
}

int main()
{
    try
    {
        printProcessedFile("testFile.txt");
    }
    catch(std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
        std::cout << "We no longer have access to the file handle." << std::endl;
    }

    return 0;
}