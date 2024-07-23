#include <gtest/gtest.h>

// Testi yapılacak basit bir fonksiyon
int Sum(int a, int b) {
    return a + b;
}

// Test case: Sum fonksiyonunu test eder
TEST(SumTest, HandlesPositiveInput) {
    EXPECT_EQ(Sum(1, 2), 3);
    EXPECT_EQ(Sum(10, 20), 30);
}

// Test case: Sum fonksiyonunu test eder
TEST(SumTest, HandlesNegativeInput) {
    EXPECT_EQ(Sum(-1, -1), -2);
    EXPECT_EQ(Sum(-1, 1), 0);
}

// Ana fonksiyon: Google Test'i çalıştırır
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}