# include <gtest/gtest.h>

# include "../src/math/Vector3.h"

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

TEST(HelloTest, TestVersion)
{
    EXPECT_EQ(MyVersion, 10);
    EXPECT_EQ(getVersion(), 100);
}