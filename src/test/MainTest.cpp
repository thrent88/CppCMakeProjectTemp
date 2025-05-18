#include <gtest/gtest.h>

TEST(Test1, TEST1) {
    ASSERT_EQ(1, 1);
}

TEST(Test1, TEST2) {
    ASSERT_EQ(2, 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
