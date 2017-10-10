#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
typedef long long ll;

using namespace std;

int H, W;
bool visited[501][501] = {};
char state[501][501];

bool reachable(int x, int y) {

  if (visited[y][x]) return false;
  visited[y][x] = true;

  if (state[y][x] == '#') return false;
  if (state[y][x] == 'g') return true;

  if ((x > 0) && reachable(x - 1, y)) {
    return true;
  } else if ((y > 0) && reachable(x, y - 1)) {
    return true;
  } else if ((x < W - 1) && reachable(x + 1, y)) {
    return true;
  } else if ((y < H - 1) && reachable(x, y + 1)) {
    return true;
  }
  return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> H >> W;

    int x, y;
    int gx, gy;

    for ( int i = 0; i < H; i++ ) {
      for ( int j = 0; j < W; j++ ) {
        char c;
        cin >> c;
        state[i][j] = c;
        if (c == 's') {
          x = j;
          y = i;
        }
      }
    }

    if (reachable(x, y)) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
    return 0;
}
