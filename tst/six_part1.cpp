#include <gtest/gtest.h>

#include <string>

using std::string;

TEST(SixPart1Test, One) {
	ASSERT_TRUE(true);
}

int main(int argc, char* argv[]) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
