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

#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define DEBUG(vec) for (auto v : vec) { cout << v << " "; } cout << endl;

using namespace std;

int inp[110][110] = {};
int orig[110][110] = {};
int conv[110][110] = {};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int H, W;
  cin >> H >> W;

  REP(i, H) {
    string s;
    cin >> s;
    REP(j, s.size()) {
      if (s[j] == '#') {
        inp[i][j] = 1;
      }
    }
  }

  int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
  int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

  REP(i, H) {
    REP(j, W) {
      orig[i][j] = 1;
    }
  }

  REP(i, H) {
    REP(j, W) {
      if (inp[i][j] == 0) {
        orig[i][j] = 0;
        REP(k, 8) {
          if (0 <= i + dy[k] && i + dy[k] < H &&
              0 <= j + dx[k] && j + dx[k] < W) {
            orig[i + dy[k]][j + dx[k]] = 0;
          }
        }
      }
    }
  }
  
  REP(i, H) {
    REP(j, W) {
      if (orig[i][j] == 1) {
        conv[i][j] = 1;
        // cout << i << " " << j << endl;
        REP(k, 8) {
          if (0 <= i + dy[k] && i + dy[k] < H &&
              0 <= j + dx[k] && j + dx[k] < W) {
            // cout << " " << i + dy[k] << " " << j + dx[k] << endl;
            conv[i + dy[k]][j + dx[k]] = 1;
          }
        }
      }
    }
  }
  REP(i, H) {
    REP(j, W) {
      if (inp[i][j] != conv[i][j]) {
        cout << "impossible" << endl;
        return 0;
      }
    }
  }

  cout << "possible" << endl;
  REP(i, H) {
    REP(j, W) {
      if (orig[i][j] == 1) {
        cout << "#";
      } else {
        cout << ".";
      }
    }
    cout << endl;
  }
  return 0;
}
