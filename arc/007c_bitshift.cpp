#include <algorithm>
#include <numeric>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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

using namespace std;


struct Point {
  int c;
  int d;
};

Point make_next(int c, int d) {
  Point p = {c, d};
  return p;
}

template<class val>
void print_binary(val x, int width) {
  cout << x << endl;
  val bit = (1 << (width - 1));
  for (int i = 0; i < width; i++) {
    if (x & bit)
      putchar('1');
    else
      putchar('0');
    bit >>= 1;
  }
  printf("\n");
}

// width の範囲で右回転シフト
template<class val>
unsigned rrotshift(val x, int n, int width) {
  if (n == 0) {
    return x;
  }
  val mask = (~((~0) << width));
  n %= width;
  return ((x >> n) | (x << (width - n)) & mask);
}

// width の範囲で左回転シフト
template<class val>
unsigned lrotshift(val x, int n, int width) {
  if (n == 0) {
    return x;
  }
  val mask = (~((~0) << width));
  n %= width;
  return ((x >> n) | (x << (width - n)) & mask);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string c;
  cin >> c;
  int N = c.size();

  set<int> visited;

  int pattern = 0;
  for (int i = 0; i < N; i++) {
    pattern <<= 1;
    if (c[i] == 'o') {
      pattern |= 1;
    }
  }
  int goal = (~((~0) << c.size()));

  queue<Point> container;
  container.push(make_next(pattern, 1));

  visited.insert(pattern);

  while (!container.empty()) {
    Point p = container.front();
    container.pop();

    if (p.c == goal) {
      cout << p.d << endl;
      return 0;
    }
    for (int i = 1; i < N; i++) {
      int next = p.c | rrotshift(pattern, i, N);
      if (visited.find(next) == visited.end()) {
        container.push(make_next(next, p.d + 1));
        visited.insert(next);
      }
    }
  }
  return 0;
}
