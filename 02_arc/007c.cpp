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
typedef long long ll;

using namespace std;

struct Point {
  string c;
  int d;
};

Point make_next(string c, int d) {
  Point p = {c, d};
  return p;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string c;
  cin >> c;

  set<string> visited;

  int N = c.size();

  string exp("");
  for (int i = 0; i < N; i++) {
    exp += "o";
  }

  queue<Point> container;
  container.push(make_next(c, 1));

  visited.insert(c);

  while (!container.empty()) {
    Point p = container.front();
    container.pop();
    // cout << p.c << endl;

    if (p.c == exp) {
      cout << p.d << endl;
      return 0;
    }
    for (int i = 0; i < N; i++) {
      string n = p.c;
      for (int j = 0; j < N; j++) {
        if (n[j] == 'x' && c[(i + j) % N] == 'o') {
          n[j] = 'o';
        }
      }
      if (visited.find(n) == visited.end()) {
        container.push(make_next(n, p.d + 1));
        visited.insert(n);
      }
    }
  }
  return 0;
}
