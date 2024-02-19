#include <gtest/gtest.h>
#include <cmath>

#include "../src/math/Vector3.h"

// Demonstrate some basic assertions.

TEST(Vector3_Const, Zero)
{
    using Math::Vector3;
    auto zero{Vector3::zero};
    EXPECT_EQ(zero.x, 0);
    EXPECT_EQ(zero.y, 0);
    EXPECT_EQ(zero.z, 0);

    auto zero2{Vector3::zero};
    zero.x = 10;
    EXPECT_EQ(zero2.x, 0);
}

TEST(Vector3, Magnitude)
{
    using Math::Vector3;
    auto zero{Vector3::zero};
    EXPECT_EQ(zero.Magnitude(), 0);

    auto up{Vector3::up};
    EXPECT_EQ(up.Magnitude(), 1);

    auto custom{Vector3(1, 1, 1)};
    EXPECT_FLOAT_EQ(custom.Magnitude(), std::sqrt(3));

    auto difficult{Vector3(3, 2, 1)};
    EXPECT_FLOAT_EQ(difficult.Magnitude(), std::sqrt(14));
}

TEST(Vector3, Negate_void)
{
    using Math::Vector3;
    auto zero{Vector3::zero};
    zero.Negate();
    EXPECT_EQ(zero, Vector3::zero);

    auto up{Vector3::up};
    up.Negate();
    EXPECT_EQ(up, Vector3::down);
    auto forward{Vector3::forward};
    forward.Negate();
    EXPECT_EQ(forward, Vector3::backward);
    auto right{Vector3::right};
    right.Negate();
    EXPECT_EQ(right, Vector3::left);
}

TEST(Vector3, Negated)
{
    using Math::Vector3;
    auto zero{Vector3::zero};
    EXPECT_EQ(zero.Negated(), Vector3::zero);

    auto up{Vector3::up};
    EXPECT_EQ(up.Negated(), Vector3::down);
    auto forward{Vector3::forward};
    EXPECT_EQ(forward.Negated(), Vector3::backward);
    auto right{Vector3::right};
    EXPECT_EQ(right.Negated(), Vector3::left);
}

TEST(Vector3, Normalize)
{
    using Math::Vector3;
    auto zero{Vector3::zero};
    EXPECT_EQ(zero.Normalized(), zero);

    auto up5{Vector3(0, 5, 0)};
    EXPECT_EQ(up5.Normalized(), Vector3::up);

    auto misc{Vector3(8, 0, 0)};
    EXPECT_EQ(misc.Normalized(), Vector3(1, 0, 0));
}

TEST(Vector3, Addition)
{
    using Math::Vector3;
    EXPECT_EQ(Vector3::zero + Vector3::zero, Vector3::zero);

    EXPECT_EQ(Vector3::zero + Vector3::up, Vector3::up);

    auto oneoneone{Vector3(1, 1, 1)};
    EXPECT_EQ(Vector3::up + Vector3::right + Vector3::forward, oneoneone);
}

TEST(Vector3, Subtraction)
{
    using Math::Vector3;
    EXPECT_EQ(Vector3::zero - Vector3::zero, Vector3::zero);

    EXPECT_EQ(Vector3::zero - Vector3::up, Vector3::down);

    auto oneoneone{Vector3(1, 1, 1)};
    EXPECT_EQ(oneoneone - Vector3::up - Vector3::right - Vector3::forward, Vector3::zero);
}

TEST(Vector3, MultiplyScalar)
{
    using Math::Vector3;
    EXPECT_EQ(Vector3::zero * 99, Vector3::zero);

    auto fiveUp{Vector3(0, 5, 0)};
    EXPECT_EQ(Vector3::up * 5, fiveUp);

    auto fivefivefive{Vector3(5, 5, 5)};
    EXPECT_EQ(5 * Vector3(1, 1, 1), fivefivefive);
}

TEST(Vector3, Dot)
{
    using Math::Vector3;

    EXPECT_EQ(Vector3::zero * Vector3::zero, 0);
    EXPECT_EQ(Vector3::up.Dot(Vector3::up), 1);
    EXPECT_EQ(Vector3::down * Vector3::down, 1);

    auto oneoneone{Vector3(1, 1, 1)};
    auto neg_oneoneone{Vector3(-1, -1, -1)};
    EXPECT_EQ(oneoneone * neg_oneoneone, -3);
}