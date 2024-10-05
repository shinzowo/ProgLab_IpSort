#include <gtest/gtest.h>
#include <tuple>
#include <string>
#include "ip_filter.h"

// Тест функции split
TEST(SplitFunctionTest, CorrectSplitting) {
    std::string ip = "192.168.0.1";
    ip_tuple result = split(ip, '.');
    
    EXPECT_EQ(std::get<0>(result), "192");
    EXPECT_EQ(std::get<1>(result), "168");
    EXPECT_EQ(std::get<2>(result), "0");
    EXPECT_EQ(std::get<3>(result), "1");
}

TEST(SplitFunctionTest, EmptyInput) {
    std::string ip = "";
    ip_tuple result = split(ip, '.');
    
    EXPECT_EQ(std::get<0>(result), "");
    EXPECT_EQ(std::get<1>(result), "");
    EXPECT_EQ(std::get<2>(result), "");
    EXPECT_EQ(std::get<3>(result), "");
}
 
TEST(FilterIPTest, FilterFirstOctet) {
    std::vector<ip_tuple> ip_list = {
        std::make_tuple("192", "168", "0", "1"),
        std::make_tuple("1", "1", "1", "1"),
        std::make_tuple("1", "0", "0", "2")
    };

    std::vector<ip_tuple> filtered;
    for (const auto& ip : ip_list) {
        if (std::get<0>(ip) == "1") {
            filtered.push_back(ip);
        }
    }

    std::vector<ip_tuple> expected = {
        std::make_tuple("1", "1", "1", "1"),
        std::make_tuple("1", "0", "0", "2")
    };

    EXPECT_EQ(filtered, expected);
}

