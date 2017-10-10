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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int R, C, K, N;
    cin >> R >> C >> K;
    cin >> N;

    int rows[100001] = {};
    int cols[100001] = {};
    set<pair<int, int>> points;

    for (int i = 0; i < N; i++) {
      int r, c;
      cin >> r >> c;
      r--;
      c--;
      rows[r]++;
      cols[c]++;
      points.insert(make_pair(r, c));
    }

    map<int, int> rs;
    map<int, int> cs;

    for (int i = 0; i < N; i++) {
      int r = rows[i];
      if (rs.find(r) != rs.end()) {
        rs[r]++;
      } else {
        rs[r] = 1;
      }

      int c = cols[i];
      if (cs.find(c) != cs.end()) {
        cs[c]++;
      } else {
        cs[c] = 1;
      }
    }
    int count = 0;
    for (const auto& r : rs) {
      for (const auto& c : cs) {
        if (r.first + c.first == K) {
          count += r.second * c.second;
        }
      }
    }

    for (const auto& p : points) {
      int n = rows[p.first] + cols[p.second];
      if (n == K) {
        count--;
      } else if (n == K + 1) {
        count++;
      }
    }
    cout << count << endl;
    return 0;
}
