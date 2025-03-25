#include <ip_filter.hpp>
#include <iostream>
#include <string>
#include "version.h"

int main() {
    std::cout << "Version: " << version() << std::endl;
    std::string filename;
    std::cout << "Введите название файла с расширением tsv: "; 
    std::getline(std::cin, filename);
    ip_filter(filename);
    return 0;
}