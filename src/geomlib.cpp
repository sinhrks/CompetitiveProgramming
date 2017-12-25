#include <assert.h>
#include <complex>
#include <iostream>

using namespace std;

const double EPS = 1e-8;

void fassert(double lhs, double rhs) {
  assert(fabs(lhs - rhs) < EPS);
}

typedef complex<double> Point;

namespace std {
  bool operator < (const Point& a, const Point& b) {
    return fabs(real(a) - real(b)) > EPS ? real(a) < real(b) : imag(a) < imag(b);
  }
}

// 内積
inline double dot(const Point& a, const Point& b) {
  return real(conj(a) * b);
}

// 外積
inline double cross(const Point& a, const Point& b) {
  return imag(conj(a) * b);
}

// 2点間の距離
inline double dist(Point a, Point b) {
  b -= a;
  return sqrt(dot(b, b));
}

// 直線
struct Line {
  Point a;
  Point b;
  explicit Line(Point a, Point b) {
    this->a = a;
    this->b = b;
  }
  inline double length() {
    return dist(a, b);
  }
};

// 点と直線の距離
double dist(Point p, Line l) {
  Point p1 = p - l.a;
  Point p2 = l.b - l.a;
  double len = l.length();
  return abs(cross(p1, p2)) / len;
}

// 線分
struct LineSegment {
  Point a;
  Point b;
  explicit LineSegment(Point a, Point b) {
    this->a = a;
    this->b = b;
  }
  inline double length() {
    return dist(a, b);
  }
};

// 点と線分の距離
double dist(Point p, LineSegment l) {
  Point p1 = p - l.a;
  Point p2 = l.b - l.a;
  double ip = dot(p1, p2);
  double len = l.length();
  if (ip / len < 0) {
    return dist(l.a, p);
  } else if (ip / len > len) {
    return dist(l.b, p);
  } else {
    return abs(cross(p1, p2)) / len;
  }
}

void test_dot() {
  fassert(dot(Point(1, 2), Point(3, 4)), 11.0);
  fassert(dot(Point(2, 3), Point(-5, 4)), 2.0);
}

void test_cross() {
  fassert(cross(Point(1, 2), Point(3, 4)), -2.0);
  fassert(cross(Point(2, 3), Point(-5, 4)), 23.0);
}

void test_dist() {
  fassert(dist(Point(0, 0), Point(2, 2)), 2.8284271247461903);
  fassert(dist(Point(0, 1), Point(2, 3)), 2.8284271247461903);

  fassert(dist(Point(0, 0), Point(1, 3)), 3.1622776601683795);
  fassert(dist(Point(1, 1), Point(2, 4)), 3.1622776601683795);
}

void test_line() {
  Line l(Point(0, 0), Point(3, 4));
}

void test_line_dist() {
  Line l(Point(2, 2), Point(5, 5));

  fassert(dist(Point(1, 1), l), 0.0);
  fassert(dist(Point(1, 2), l), sqrt(2) / 2.0);
  fassert(dist(Point(2, 3), l), sqrt(2) / 2.0);
  fassert(dist(Point(2, 4), l), sqrt(2));
  fassert(dist(Point(6, 6), l), 0.0);
  fassert(dist(Point(5, 6), l), sqrt(2) / 2.0);
}

void test_linesegment() {
  LineSegment ls(Point(0, 0), Point(3, 4));
  fassert(ls.length(), 5.0);
}

void test_linesegment_dist() {
  LineSegment ls(Point(2, 2), Point(5, 5));
  fassert(ls.length(), sqrt(18));

  fassert(dist(Point(1, 1), ls), sqrt(2));
  fassert(dist(Point(1, 2), ls), 1.0);
  fassert(dist(Point(2, 3), ls), sqrt(2) / 2.0);
  fassert(dist(Point(2, 4), ls), sqrt(2));
  fassert(dist(Point(6, 6), ls), sqrt(2));
  fassert(dist(Point(5, 6), ls), 1.0);
}

/*

// 直線、線分
struct Line : public vector<Point> {
  Line(const Point &a, const Point &b) {
    push_back(a);
    push_back(b);
  }
};

// 単純多角形 (反時計回り)
typedef vector<Point> Polygon;

// 円
struct Circle {
  Point p;
  double r;
  Circle(const Point &p, double r) : p(p), r(r) { }
};

// Counter Clockwise
int ccw(Point a, Point b, Point c) {
  b -= a;
  c -= a;
  if (cross(b, c) > 0)   return +1;       // counter clockwise
  if (cross(b, c) < 0)   return -1;       // clockwise
  if (dot(b, c) < 0)     return +2;       // c--a--b on line
  if (norm(b) < norm(c)) return -2;       // a--b--c on line
  return 0;
}

// 直線と直線が交差するか
bool intersectLL(const Line &l, const Line &m) {
  return abs(cross(l[1] - l[0], m[1] - m[0])) > EPS ||  // non-parallel
         abs(cross(l[1] - l[0], m[0] - l[0])) < EPS;    // same line
}

// 直線と線分が交差するか
bool intersectLS(const Line &l, const Line &s) {
  return cross(l[1] - l[0], s[0] - l[0]) *        // s[0] is left of l
         cross(l[1] - l[0], s[1] - l[0]) < EPS;   // s[1] is right of l
}

// 直線と点が交差するか
bool intersectLP(const Line &l, const Point &p) {
  return abs(cross(l[1] - p, l[0] - p)) < EPS;
}

// 線分と線分が交差するか
bool intersectSS(const Line &s, const Line &t) {
  return ccw(s[0], s[1], t[0]) * ccw(s[0], s[1], t[1]) <= 0 &&
         ccw(t[0], t[1], s[0]) * ccw(t[0], t[1], s[1]) <= 0;
}

// 線分と点が交差するか
bool intersectSP(const Line &s, const Point &p) {
  // triangle inequality
  return abs(s[0] - p) + abs(s[1] - p) - abs(s[1] - s[0]) < EPS;
}

// 点の直線への射影
Point projection(const Line &l, const Point &p) {
  double t = dot(p - l[0], l[0] - l[1]) / norm(l[0] - l[1]);
  return l[0] + t * (l[0] - l[1]);
}

// 点の直線に対する反射点
Point reflection(const Line &l, const Point &p) {
  return p + 2.0 * (projection(l, p) - p);
}

// 直線と点の距離
double distanceLP(const Line &l, const Point &p) {
  return abs(p - projection(l, p));
}

// 直線と直線の距離
double distanceLL(const Line &l, const Line &m) {
  return intersectLL(l, m) ? 0 : distanceLP(l, m[0]);
}

// 直線と線分の距離
double distanceLS(const Line &l, const Line &s) {
  if (intersectLS(l, s)) return 0;
  return min(distanceLP(l, s[0]), distanceLP(l, s[1]));
}

// 線分と点の距離
double distanceSP(const Line &s, const Point &p) {
  const Point r = projection(s, p);
  if (intersectSP(s, r)) return abs(r - p);
  return min(abs(s[0] - p), abs(s[1] - p));
}

// 線分と線分の距離
double distanceSS(const Line &s, const Line &t) {
  if (intersectSS(s, t)) return 0;
  return min(min(distanceSP(s, t[0]), distanceSP(s, t[1])),
             min(distanceSP(t, s[0]), distanceSP(t, s[1])));
}

Point crosspoint(const Line &l, const Line &m) {
  double A = cross(l[1] - l[0], m[1] - m[0]);
  double B = cross(l[1] - l[0], l[1] - m[0]);
  if (abs(A) < EPS && abs(B) < EPS) return m[0];  // same line
  return m[0] + B / A * (m[1] - m[0]);
}

// 平面操作法 (線分)
struct event {
  double x;
  int type;
  Line seg;
  event(double x, int type, const Line& seg) :
    x(x), type(type), seg(seg) { }
  bool operator < (const event &e) const {
    return x != e.x ? x > e.x : type > e.type;
  }
};

int segment_intersects(const vector<Line>& segs) {
  priority_queue<event> Q;
  for (int i = 0; i < segs.size(); ++i) {
    double x1 = real(segs[i][0]), x2 = real(segs[i][1]);
    Q.push(event(min(x1, x2), 0, segs[i]));
    Q.push(event(max(x1, x2), 1, segs[i]));
  }
  int count = 0;
  set<Line> T;
  while (!Q.empty()) {
    event e = Q.top(); Q.pop();
    if (e.type == 0) {
      for (set<Line>::iterator itr = T.begin();
          itr != T.end(); ++itr)
        if (intersectLS(*itr, e.seg)) {
          // *out++ = crosspoint(*itr, e.seg);
          ++count;
        }
      T.insert(e.seg);
    } else {
      T.erase(e.seg);
    }
  }
  return count;
}
*/

int main() {
  test_dot();
  test_cross();
  test_dist();

  test_line();
  test_line_dist();

  test_linesegment();
  test_linesegment_dist();

  cout << "SUCCESS!!" << endl;
  return 0;
}
