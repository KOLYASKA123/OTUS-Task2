#include <gtest/gtest.h>
#include "version.h"
#include "ip_filter.hpp"

TEST(TestVersion, DemonstrateGTestMacros) {
    EXPECT_TRUE(version() == PROJECT_VERSION_PATCH);
}

TEST(TestIpFilter, DemonstrateGTestMacros) {
    std::string str = "192.168.0.1";
    std::string sep = ".";
    auto split_ip = split(str, sep);
    EXPECT_TRUE(split_ip[0] == "192");
    EXPECT_TRUE(split_ip[1] == "168");
    EXPECT_TRUE(split_ip[2] == "0");
    EXPECT_TRUE(split_ip[3] == "1");
}