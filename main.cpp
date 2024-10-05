#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<tuple>
#include<algorithm>
#include "ip_filter.h"

int main(){
    std::ifstream file("../ip_filter.tsv");
    if(!file.is_open()){
        std::cout<<"File ip_filter is not open\n";
        return 1;
    }
    ip_tuple ip; 
    std::vector<ip_tuple>ip_v;
    while(!file.eof()){
        std::string line;
        file>>line;
        if(line.find('.')==std::string::npos){
            continue;
        }
        ip=split(line, '.');
        ip_v.push_back(ip);
    }
    file.close();
    std::sort(ip_v.begin(), ip_v.end(), [](const ip_tuple &a, const ip_tuple &b) {
        // Преобразуем строки в числа для корректного сравнения
        return std::make_tuple(
            std::stoi(std::get<0>(a)), std::stoi(std::get<1>(a)), 
            std::stoi(std::get<2>(a)), std::stoi(std::get<3>(a))
        ) > std::make_tuple(
            std::stoi(std::get<0>(b)), std::stoi(std::get<1>(b)), 
            std::stoi(std::get<2>(b)), std::stoi(std::get<3>(b))
        );
    });
    std::cout<<"\nfull list of ip-adresses\n";
    for(auto it:ip_v){
        print(it);
    }
    std::cout<<"\nip-adresses with 1.x.x.x\n";
    for(auto it:ip_v){
        if(std::get<0>(it)=="1"){
            print(it);
        }
    }
    std::cout<<"\nip-adresses with 46.70.x.x\n";
    for(auto it:ip_v){
        if(std::get<0>(it)=="46" && std::get<1>(it)=="70"){
            print(it);
        }
    }
    std::cout<<"\nip-adresses with 46 in x.x.x.x\n";
    for(auto it:ip_v){
        if(std::get<0>(it)=="46" || std::get<1>(it)=="46" || std::get<2>(it)=="46" || std::get<3>(it)=="46"){
            print(it);
        }
    }
    int temp;
    std::cin>>temp;
    return 0;
}