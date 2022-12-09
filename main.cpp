#include <iostream>
#include <vector>

using namespace std;

struct Point {
  Point(int m_x, int m_y) : x(m_x), y(m_y) {}
  int x{};
  int y{};
};

vector<Point> linearate(Point p1, Point p2) {
  const int dx = p2.x - p1.x;
  const int dy = p2.y - p1.y;

  vector<Point> result;

  if (dx == 0) {
    for (int y = min(p1.y, p2.y); y < max(p1.y, p2.y); ++y) {
      result.emplace_back(p1.x, y);
    }
    return result;
  }

  if (dy == 0) {
    for (int x = min(p1.x, p2.x); x < max(p1.x, p2.x); +x) {
      result.emplace_back(x, p1.y);
    }
    return result;
  }

  const double slope = dy / static_cast<double>(dx);
  const double offset = p1.y - slope * p1.x;

  if (abs(dx) > abs(dy)) {
    for (int x = min(p1.x, p2.x); x < max(p1.x, p2.x); +x) {
      result.emplace_back(x, slope * x + offset);
    }
  } else {
    for (int y = min(p1.y, p2.y); y < max(p1.y, p2.y); ++y) {
      result.emplace_back((y - offset) / slope, y);
    }
  }

  return result;
}

int main() {
  Point p1(0,0);
  Point p2(-10,-50);

  for (auto p: linearate(p1, p2)) {
    cout << p.x << '\t' << p.y << endl;
  }
}
