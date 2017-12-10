#include <assert.h>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <complex>
#include <bitset>
typedef long long ll;
typedef unsigned long long ull;

# define INF 0x3f3f3f3f

#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define DEBUG(vec) for (auto v : vec) { cout << v << " "; } cout << endl;

using namespace std;

const double EPS = 1e-8;
typedef complex<double> Point;

namespace std {
  bool operator < (const Point& a, const Point& b) {
    return fabs(real(a) - real(b)) > EPS ? real(a) < real(b) : imag(a) < imag(b);
  }
}

// 内積
double dot(const Point& a, const Point& b) {
  return real(conj(a) * b);
}

// 外積
double cross(const Point& a, const Point& b) {
  return imag(conj(a) * b);
}

// 2点間の距離
double dist(Point a, Point b) {
  b -= a;
  return sqrt(dot(b, b));
}

// 線分
struct LineSegment {
  Point a;
  Point b;
  explicit LineSegment(Point a, Point b) {
    this->a = a;
    this->b = b;
  }
  double length() {
    return dist(a, b);
  }
};

// 点と線分の距離
double dist(Point p, LineSegment b) {
  Point p1 = p - b.a;
  Point p2 = b.b - b.a;
  return abs(cross(p1, p2)) / b.length();
}

Point points[11] = {};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  double x, y;
  cin >> x >> y;
  int N;
  cin >> N;
  REP(i, N) {
    double xx, yy;
    cin >> xx >> yy;
    points[i] = Point(xx, yy);
  }

  Point p(x, y);
  double ans = dist(p, LineSegment(points[0], points[N - 1]));
  REP(i, N - 1) {
    double d = dist(p, LineSegment(points[i], points[i + 1]));
    ans = min(ans, d);
  }

  printf("%.10f\n", ans);
  return 0;
}
