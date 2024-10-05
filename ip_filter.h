#ifndef IP_FILTER_H
#define IP_FILTER_H

#include <tuple>
#include <string>
#include <iostream>

// Тип для хранения IP-адреса
using ip_tuple = std::tuple<std::string, std::string, std::string, std::string>;

// Объявляем функцию split
ip_tuple split(const std::string& line, char s);
void print(ip_tuple ip);

#endif  // IP_FILTER_H