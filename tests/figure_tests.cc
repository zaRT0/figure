#include <gtest/gtest.h>
#include <figure/figure.h>
using namespace Figures;
TEST(FigureTests, CalcPerimetrTest1) {
    Point p1(4, 5);
    Point p2(6, 3);
    Figure circle(FigureType::CIRCLE, p1, p2);
    double r = circle.calc_perimetr();
    EXPECT_EQ(r, 17.7625);
}

TEST(FunctionsTests, CalcPerimetrTest2) {
    Point p1(4, 5);
    Point p2(6, 3);
    Point p3(5, 8);
    Figure triangle(FigureType::TRIANGLE, p1, p2, p3);
    double r = triangle.calc_perimetr();
    EXPECT_EQ(r, 11.0897);
}

TEST(FunctionsTests, CalcPerimetrTest3) {
    Point p1(2, 6);
    Point p2(4, 2);
    Figure rectangle(FigureType::RECTANGLE, p1, p2);
    double r = rectangle.calc_perimetr();
    EXPECT_EQ(r, 12);
}

TEST(FunctionsTests, CalcSquareTest1) {
    Point p1(1, 8);
    Point p2(3, 7);
    Figure circle(FigureType::CIRCLE, p1, p2);
    double r = circle.calc_square();
    EXPECT_EQ(r, 15.7);
}

TEST(FunctionsTests, CalcSquareTest2) {
    Point p1(3, 9);
    Point p2(4, 9);
    Figure rectangle(FigureType::RECTANGLE, p1, p2);
    double r = rectangle.calc_square();
    EXPECT_EQ(r, 0);
}

TEST(FunctionsTests, CalcSquareTest3) {
    Point p1(1, 5);
    Point p2(6, 3);
    Point p3(5, 7);
    Figure triangle(FigureType::TRIANGLE, p1, p2, p3);
    double r = triangle.calc_square();
    EXPECT_EQ(r, 9);
}

TEST(FunctionsTests, FramingRectangle1) {
    Point p1(2, 2);
    Point p2(4, 2);
    bool flag = false;
    Figure circle(FigureType::CIRCLE, p1, p2);
    circle.calc_framing_rectangle(); 
    Point* framing_arr = circle.get_points_framing_rectangle();
    if ((framing_arr[0].x == 2) && (framing_arr[0].y == 4) && (framing_arr[1].x == 4) && (framing_arr[1].y == 4) && (framing_arr[2].x == 4) && (framing_arr[2].y == 2) && (framing_arr[3].x == 2) && (framing_arr[3].y == 2)) {
        flag = true;
    }
    EXPECT_TRUE(flag);
}
