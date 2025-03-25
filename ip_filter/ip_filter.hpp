#pragma once
#include <string>
#include <vector>


using split_string = std::vector<std::string>;
using ip_addr = std::vector<int>;
using ip_pool = std::vector<ip_addr>;


void ip_filter(std::string filename);
split_string split(std::string &str, std::string &sep);
