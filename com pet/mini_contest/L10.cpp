#include <bits/stdc++.h>
using namespace std;

struct Rectangle {
    long x, y, width, height;
};

long overlap(Rectangle rect1, Rectangle rect2) {
    // find x and width of overlap
    long x1 = max(rect1.x, rect2.x);
    long x2 = min(rect1.x + rect1.width, rect2.x + rect2.width);
    long width = x2 - x1;

    // find y and height of overlap
    long y1 = max(rect1.y, rect2.y);
    long y2 = min(rect1.y + rect1.height, rect2.y + rect2.height);
    long height = y2 - y1;

    // if there is no overlap, return 0
    if (width <= 0 || height <= 0) {
        return 0;
    }

    // calculate and return the overlap area
    return width * height;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<Rectangle> rects;

    long n, all_area = 0, max_overlap = 0;

    cin >> n;

    for (long i = 0; i < n; i++) {
        long x_min, x_max, y_min, y_max;
        cin >> x_min >> x_max >> y_min >> y_max;
        Rectangle r = {x_min, y_min, x_max - x_min, y_max - y_min};
        rects.push_back(r);
        all_area += r.width * r.height;
    }

    // iterate through all pairs of rectangles
    for (long i = 0; i < n - 1; i++) {
        for (long j = i + 1; j < n; j++) {
            // find the overlap area between the two rectangles
            long curr_overlap = overlap(rects[i], rects[j]);
            max_overlap = max(max_overlap, curr_overlap);
        }
    }

    cout << all_area - max_overlap << endl;
    return 0;
}
