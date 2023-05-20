#include <gtest/gtest.h>
#include <figure/figure.h>
using namespace Figures;
using namespace std;

TEST(FigureTests, CalcPerimetrTest1) {
    const auto tests_circle = make_shared<Circle>(Point(4, 5), Point(6, 3));
    double result = tests_circle->calc_perimetr();
    EXPECT_EQ(result, 17.7625);
}

TEST(FunctionsTests, CalcPerimetrTest2) {
    const auto tests_triangle = make_shared<Triangle>(Point(4, 5), Point(6, 3), Point(5, 8));
    double result = tests_triangle->calc_perimetr();
    EXPECT_EQ(result, 11.0897);
}

TEST(FunctionsTests, CalcPerimetrTest3) {
    const auto tests_rectangle = make_shared<Rectangle>(Point(2, 6), Point(4, 2));
    double result = tests_rectangle->calc_perimetr();
    EXPECT_EQ(result, 12);
}

TEST(FunctionsTests, CalcSquareTest1) {
    const auto tests_circle = make_shared<Circle>(Point(1, 8), Point(3, 7));
    double result = tests_circle->calc_square();
    EXPECT_EQ(result, 15.7);
}

TEST(FunctionsTests, CalcSquareTest2) {
    const auto tests_rectangle = make_shared<Rectangle>(Point(3, 9), Point(4, 9));
    double result = tests_rectangle->calc_square();
    EXPECT_EQ(result, 0);
}

TEST(FunctionsTests, CalcSquareTest3) {
    const auto tests_triangle = make_shared<Triangle>(Point(1, 5), Point(6, 3), Point(5, 7));
    double result = tests_triangle->calc_square();
    EXPECT_EQ(result, 9);
}

TEST(FunctionsTests, FramingRectangle1) {
    bool flag = false;
    const auto tests_circle = make_shared<Circle>(Point(2, 2), Point(4, 2));
    tests_circle->calc_framing_rectangle();
    Point* framing_arr = tests_circle->get_points_framing_rectangle();
    if ((framing_arr[0].x == 2) && (framing_arr[0].y == 4) && (framing_arr[1].x == 4) && (framing_arr[1].y == 4) && (framing_arr[2].x == 4) && (framing_arr[2].y == 2) && (framing_arr[3].x == 2) && (framing_arr[3].y == 2)) {
        flag = true;
    }
    EXPECT_TRUE(flag);
}