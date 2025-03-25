#include <ip_filter.hpp>
#include <iostream>
#include "version.h"

int main() {
    std::cout << "Version: " << version() << std::endl;
    ip_filter("../ip_filter.tsv");
    return 0;
}