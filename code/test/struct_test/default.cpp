#include <iostream>
#include <vector>
using namespace std;

// struct Point
// {
//     int x;
//     int y;
// };

typedef struct tagPoint
{
    int x;
    int y;
} Point;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // struct Point MyPoint = {30, 40};
    // printf("x: %d, y: %d\n", MyPoint.x, MyPoint.y);

    Point MyPoint = {30, 40};
    Point* ptr = &MyPoint;
    return 0;
}