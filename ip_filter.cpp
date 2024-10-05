#include"ip_filter.h"

ip_tuple split(const std::string& line, char s) {
    std::string::size_type start = 0;
    std::string::size_type stop = line.find_first_of(s);
    std::string value[4] = {""};
    int i = 0;
    while (stop != std::string::npos) {
        value[i] = line.substr(start, stop - start);
        start = stop + 1;
        stop = line.find_first_of(s, start);
        i++;
    }
    value[3] = line.substr(start);
    return std::make_tuple(value[0], value[1], value[2], value[3]);
}
void print(ip_tuple ip){
    std::cout << std::get<0>(ip) << "."
              << std::get<1>(ip) << "."
              << std::get<2>(ip) << "."
              << std::get<3>(ip) << "\n";
}