#include <gtest/gtest.h>

#include <string>

using std::string;

TEST(FiveTest, One) {
	ASSERT_TRUE(isNiceString("ugknbfddgicrmopn"));
}

TEST(FiveTest, Two) {
	ASSERT_TRUE(isNiceString("aaa"));
}

TEST(FiveTest, Three) {
	ASSERT_FALSE(isNiceString("jchzalrnumimnmhp"));
}

TEST(FiveTest, Four) {
	ASSERT_FALSE(isNiceString("haegwjzuvuyypxyu"));
}

TEST(FiveTest, Five) {
	ASSERT_FALSE(isNiceString("dvszwmarrgswjxmb"));
}


int main(int argc, char* argv[]) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
