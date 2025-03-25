#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "ip_filter.hpp"

/*
    Метод для разделения строки на отдельные составляющие с помощью указанного разделителя.

    Параметры:

    str: Разделяемая строка

    sep: Разделитель
*/
split_string split(std::string &str, std::string &sep) {
    split_string result;
    std::string new_word;
    size_t start_pos = 0;
    size_t end_pos;

    do {
        end_pos = str.find(sep, start_pos);
        new_word = str.substr(start_pos, end_pos - start_pos);
        result.push_back(new_word);
        start_pos = end_pos + sep.size();
    } while (end_pos != std::string::npos);

    return result;
}

void ip_filter(std::string filename) {
    std::ifstream in(filename);
    
    ip_pool ips;
    ip_pool ips_f1;
    ip_pool ips_f2;
    ip_pool ips_f3;
    std::string buf;
    std::string file_sep = "\t";
    std::string ip_sep = ".";

    auto print_ip = [](ip_addr &ip) {
        for (int i=0; i<ip.size()-1; i++) std::cout << ip[i] << ".";
        std::cout << ip.back() << std::endl;
    };

    auto print_ip_pool = [&](ip_pool &pool) {
        for (auto ip : pool) print_ip(ip);
    };
    
    for (
        std::string line;
        std::getline(in, line);
    ) {
        ip_addr ip_int_separated;
        split_string ip_string_separated = split(split(line, file_sep)[0], ip_sep);
        std::for_each(
            ip_string_separated.begin(), 
            ip_string_separated.end(),
            [&](std::string ip_part){
                ip_int_separated.push_back(std::stoi(ip_part));
            }
        );

        ips.push_back(ip_int_separated);
    }

    std::sort(
        ips.begin(), 
        ips.end(),
        [](ip_addr &ip1, ip_addr &ip2) {
            for (auto i=0; i<ip1.size(); i++) {
                if (ip1[i] != ip2[i]) {
                    return ip1[i] > ip2[i];
                }
                continue;
            }
            return false;
        }
    );

    std::for_each(
        ips.begin(), 
        ips.end(),
        [&](ip_addr &ip) {
            if (ip[0] == 1) ips_f1.push_back(ip);
            if (ip[0] == 46 && ip[1] == 70) ips_f2.push_back(ip);
            if (
                std::any_of(
                    ip.begin(), 
                    ip.end(),
                    [](auto ip_part) {return ip_part == 46;}
                )
            ) ips_f3.push_back(ip);
        }
    );

    print_ip_pool(ips);
    print_ip_pool(ips_f1);
    print_ip_pool(ips_f2);
    print_ip_pool(ips_f3);
}

