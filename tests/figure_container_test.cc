#include <gtest/gtest.h>
#include <figure/figure.h>

using namespace Figures;

TEST(SequanceContainerTests, CapacityCheck) {
    FigureContainer figures(3);
    Figure s = Figure(CIRCLE, Point(1, 2), Point(5, 9));
    figures[0] = Figure(CIRCLE, Point(4, 3), Point(5, 8));
    figures[1] = Figure(CIRCLE, Point(1, 3), Point(7, 9));
    figures[2] = Figure(CIRCLE, Point(1, 9), Point(78, 2));
    ASSERT_ANY_THROW(figures.insert(4, s));
}

TEST(MaxSumNthElemIndex, NoResult) {
    FigureContainer figures;
    const auto index = min_square(figures);
    ASSERT_EQ(index, -1);
}

TEST(IndexOfFigureWithMinValue, ForCircle) {
    FigureContainer figures;
    Figure s;
    
    s = Figure(CIRCLE, Point(1, 2), Point(5, 9));
    figures.insert(0, s);
    s = Figure(CIRCLE, Point(4, 3), Point(15, 11));
    figures.insert(1, s);
    s = Figure(CIRCLE, Point(20, 8), Point(8, 11));
    figures.insert(2, s);
    s = Figure(CIRCLE, Point(7, 12), Point(1, 5));
    figures.insert(3, s);
    
    const auto index = min_square(figures);

    ASSERT_EQ(index, 0);
}

TEST(IndexOfFigureWithMinValue, ForTriangle) {
    FigureContainer figures;
    Figure s;

    s = Figure(TRIANGLE, Point(2, 3), Point(10, 5), Point(12, 4));
    figures.insert(0, s);
    s = Figure(TRIANGLE, Point(15, 8), Point(10, 9), Point(8, 7));
    figures.insert(1, s);
    s = Figure(TRIANGLE, Point(2, 3), Point(10, 5), Point(12, 4));
    figures.insert(2, s);

    const auto index = min_square(figures);

    ASSERT_EQ(index, 2);
}

TEST(IndexOfFigureWithMinValue, ForRectangle) {
    FigureContainer figures;
    Figure s;

    s = Figure(RECTANGLE, Point(10, 4), Point(9, 1));
    figures.insert(0, s);
    s = Figure(RECTANGLE, Point(8, 6), Point(5, 10));
    figures.insert(1, s);
    s = Figure(RECTANGLE, Point(3, 8), Point(14, 1));
    figures.insert(2, s);
    s = Figure(RECTANGLE, Point(2, 7), Point(10, 19));

    const auto index = min_square(figures);

    ASSERT_EQ(index, 0);
}

TEST(IndexOfFigureWithMinValue, Mix1) {
    FigureContainer figures;
    Figure s;

    s = Figure(CIRCLE, Point(1, 2), Point(2, 3));
    figures.insert(0, s);
    s = Figure(TRIANGLE, Point(2, 3), Point(10, 5), Point(12, 4));
    figures.insert(1, s);
    s = Figure(RECTANGLE, Point(10, 4), Point(9, 1));
    figures.insert(2, s);
    s = Figure(RECTANGLE, Point(8, 6), Point(5, 10));

    const auto index = min_square(figures);

    ASSERT_EQ(index, 2);
}

TEST(IndexOfFigureWithMinValue, Mix2) {
    FigureContainer figures;
    Figure s;

    s = Figure(CIRCLE, Point(1, 2), Point(2, 3));
    figures.insert(0, s);
    s = Figure(TRIANGLE, Point(2, 3), Point(10, 5), Point(12, 4));
    figures.insert(1, s);
    s = Figure(TRIANGLE, Point(15, 8), Point(10, 9), Point(8, 7));
    figures.insert(2, s);
    s = Figure(RECTANGLE, Point(10, 4), Point(9, 1));

    const auto index = min_square(figures);

    ASSERT_EQ(index, 2);
}

TEST(IndexOfFigureWithMinValue, Mix3) { 
    FigureContainer figures;
    Figure s;

    s = Figure(CIRCLE, Point(1, 2), Point(2, 3));
    figures.insert(0, s);
    s = Figure(CIRCLE, Point(5, 1), Point(7, 10));
    figures.insert(1, s);
    s = Figure(TRIANGLE, Point(2, 3), Point(10, 5), Point(12, 4));
    figures.insert(2, s);
    s = Figure(RECTANGLE, Point(10, 4), Point(9, 1));

    const auto index = min_square(figures);

    ASSERT_EQ(index, 2);
}

TEST(IndexOfFigureWithMinValue, Mix4) {
    FigureContainer figures;
    Figure s;

    s = Figure(TRIANGLE, Point(2, 3), Point(10, 5), Point(12, 4));
    figures.insert(0, s);
    s = Figure(CIRCLE, Point(1, 2), Point(2, 3));
    figures.insert(1, s);
    s = Figure(RECTANGLE, Point(10, 4), Point(9, 1));
    figures.insert(2, s);
    s = Figure(TRIANGLE, Point(15, 8), Point(10, 9), Point(8, 7));
    figures.insert(3, s);
    s = Figure(CIRCLE, Point(5, 1), Point(7, 10));
    figures.insert(4, s);
    s = Figure(RECTANGLE, Point(8, 6), Point(5, 10));
    figures.insert(5, s);
    s = Figure(TRIANGLE, Point(15, 11), Point(6, 7), Point(9, 17));
    figures.insert(6, s);
    s = Figure(CIRCLE, Point(5, 15), Point(3, 11));
    figures.insert(7, s);
    s = Figure(RECTANGLE, Point(7, 4), Point(3, 2));
    figures.insert(8, s);
    s = Figure(TRIANGLE, Point(3, 8), Point(4, 10), Point(5, 3));
    figures.insert(9, s);

    const auto index = min_square(figures);

    ASSERT_EQ(index, 2);
}

TEST(IndexOfFigureWithMinValue, Mix5) {
    FigureContainer figures;
    Figure s;
    
    s = Figure(TRIANGLE, Point(3, 4), Point(10, 5), Point(17, 4));
    figures.insert(0, s);
    s = Figure(CIRCLE, Point(9, 4), Point(5, 3));
    figures.insert(1, s);
    s = Figure(RECTANGLE, Point(11, 4), Point(9, 9));
    figures.insert(2, s);
    s = Figure(TRIANGLE, Point(4, 8), Point(9, 10), Point(2, 3));
    figures.insert(3, s);
    s = Figure(RECTANGLE, Point(7, 4), Point(1, 2));
    figures.insert(4, s);
    s = Figure(CIRCLE, Point(5, 11), Point(3, 12));
    figures.insert(5, s);
    s = Figure(TRIANGLE, Point(3, 2), Point(4, 13), Point(9, 7));
    figures.insert(6, s);
    s = Figure(RECTANGLE, Point(7, 4), Point(3, 2));
    figures.insert(7, s);
    s = Figure(TRIANGLE, Point(3, 7), Point(4, 11), Point(8, 3));
    figures.insert(8, s);
    s = Figure(CIRCLE, Point(1, 2), Point(2, 4));
    figures.insert(9, s);

    const auto index = min_square(figures);

    ASSERT_EQ(index, 0);
}
