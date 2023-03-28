#include <gtest/gtest.h>
#include <figure/figure.h>
using namespace Figures;
TEST(FigureTests, CalcPerimetrTest1) {
    // Arrange
    Point p1(4, 5);
    Point p2(6, 3);
    Figure circle(FigureType::CIRCLE, p1, p2);
    // Act
    double r = circle.calc_perimetr();
    // Assert
    EXPECT_EQ(r, 17.7625);
}

TEST(FunctionsTests, CalcPerimetrTest2) {
    // Arrange
    Point p1(4, 5);
    Point p2(6, 3);
    Point p3(5, 8);
    Figure triangle(FigureType::TRIANGLE, p1, p2, p3);
    // Act
    double r = triangle.calc_perimetr();
    // Assert
    EXPECT_EQ(r, 11.0897);
}

TEST(FunctionsTests, CalcPerimetrTest3) {
    // Arrange
    Point p1(4, 5);
    Point p2(6, 5);
    Point p3(1, 8);
    Point p4(1, 4);
    Figure rectangle(FigureType::RECTANGLE, p1, p2, p3,p4);
    // Act
    double r = rectangle.calc_perimetr();
    // Assert
    EXPECT_EQ(r, 0);
}

TEST(FunctionsTests, CalcSquareTest1) {
    // Arrange
    Point p1(1, 8);
    Point p2(3, 7);
    Figure circle(FigureType::CIRCLE, p1, p2);
    // Act
    double r = circle.calc_square();
    // Assert
    EXPECT_EQ(r, 15.7);
}

TEST(FunctionsTests, CalcSquareTest2) {
    // Arrange
    Point p1(3, 9);
    Point p2(4, 9);
    Point p3(4, 7);
    Point p4(3, 7);
    Figure rectangle(FigureType::RECTANGLE, p1, p2, p3, p4);
    // Act
    double r = rectangle.calc_square();
    // Assert
    EXPECT_EQ(r, 2);
}

TEST(FunctionsTests, CalcSquareTest3) {
    // Arrange
    Point p1(1, 5);
    Point p2(6, 3);
    Point p3(5, 7);
    Figure triangle(FigureType::TRIANGLE, p1, p2, p3);
    // Act
    double r = triangle.calc_square();
    // Assert
    EXPECT_EQ(r, 9);
}

TEST(FunctionsTests, FramingRectangle1) {
    // Arrange
    Point p1(1, 4);
    Point p2(7, 3);
    Figure circle(FigureType::CIRCLE, p1, p2);
    // Act
    double r = circle.calc_framing_rectangle();
    // Assert
    EXPECT_EQ(r, 148);
}

TEST(FunctionsTests, FramingRectangle2) {
    // Arrange
    Point p1(1, 5);
    Point p2(4, 3);
    Point p3(5, 7);
    Point p4(1, 3);
    Figure rectangle(FigureType::RECTANGLE, p1, p2, p3, p4);
    // Act
    double r = rectangle.calc_framing_rectangle();
    // Assert
    EXPECT_EQ(r, 14);
}

TEST(FunctionsTests, FramingRectangle3) {
    // Arrange
    Point p1(1, 5);
    Point p2(4, 3);
    Point p3(2, 6);
    Figure triangle(FigureType::TRIANGLE, p1, p2, p3);
    // Act
    double r = triangle.calc_framing_rectangle();
    // Assert
    EXPECT_EQ(r, 5);
}
