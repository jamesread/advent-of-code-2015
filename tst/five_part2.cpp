#include <gtest/gtest.h>

#include "five.hpp"

#include <string>

using std::string;

TEST(FiveTest, One) {
	ASSERT_TRUE(isNiceStringPart2("ugknbfddgicrmopn"));
}

TEST(FiveTest, Two) {
	ASSERT_TRUE(isNiceStringPart2("aaa"));
}

TEST(FiveTest, Three) {
	ASSERT_FALSE(isNiceStringPart2("jchzalrnumimnmhp"));
}

TEST(FiveTest, Four) {
	ASSERT_FALSE(isNiceStringPart2("haegwjzuvuyypxyu"));
}

TEST(FiveTest, Five) {
	ASSERT_FALSE(isNiceStringPart2("dvszwmarrgswjxmb"));
}


int main(int argc, char* argv[]) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
