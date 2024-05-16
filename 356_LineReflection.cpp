#include<iostream>
#include<set>
#include<limits>

int main() {
    float min_x = std::numeric_limits<float>::max();
    float max_x = std::numeric_limits<float>::min();

    int n;
    float x, y;
    std::set<std::pair<float, float> > points;

    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> x >> y;
        if (x < min_x) {
            min_x = x;
        }
        if (x > max_x) {
            max_x = x;
        }
        points.insert(std::make_pair(x, y));
    }
    int countOfPoints = points.size();
    float line_x = (min_x + max_x) / 2;
    for (auto point : points) {
        float length = line_x - point.first;
        float new_x = line_x + length;
        points.insert(std::make_pair(new_x, point.second));
    }
    int newCount = points.size();
    if (newCount == countOfPoints) {
        std::cout << "true\n";
    } else {
        std::cout << "false\n";
    }
    return 0;
}