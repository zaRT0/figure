#include <gtest/gtest.h>
#include <figure/figure.h>

TEST(FigureTests, CalcPerimetrTest1) {
    // Arrange
    Figure circle(FigureType::CIRCLE);
    // Act
    double r = circle.calc_perimetr(4, 6, 0, 0, 5, 3, 0, 0);
    // Assert
    EXPECT_EQ(r, 17.7625);
}

TEST(FunctionsTests, CalcPerimetrTest2) {
    // Arrange
    Figure triangle(FigureType::TRIANGLE);
    // Act
    double r = triangle.calc_perimetr(5, 7, 3, 0, 8, 6, 4, 0);
    // Assert
    EXPECT_EQ(r, 11.7727);
}

TEST(FunctionsTests, CalcPerimetrTest3) {
    // Arrange
    Figure rectangle(FigureType::RECTANGLE);
    // Act
    double r = rectangle.calc_perimetr(2, 6, 6, 2, 7, 7, 4, 4);
    // Assert
    EXPECT_EQ(r, 14);
}

TEST(FunctionsTests, CalcSquareTest1) {
    // Arrange
    Figure circle(FigureType::CIRCLE);
    // Act
    double r = circle.calc_square(4, 6, 0, 0, 5, 3, 0, 0);
    // Assert
    EXPECT_EQ(r, 25.12);
}

TEST(FunctionsTests, CalcSquareTest2) {
    // Arrange
    Figure rectangle(FigureType::RECTANGLE);
    // Act
    double r = rectangle.calc_square(2, 6, 6, 2, 7, 7, 4, 4);
    // Assert
    EXPECT_EQ(r, 12);
}

TEST(FunctionsTests, CalcSquareTest3) {
    // Arrange
    Figure triangle(FigureType::TRIANGLE);
    // Act
    double r = triangle.calc_square(5, 7, 3, 0, 8, 6, 4, 0);
    // Assert
    EXPECT_EQ(r, 6);
}
