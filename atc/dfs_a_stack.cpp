#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <string>
#include <vector>
typedef long long ll;

using namespace std;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int H, W;
    bool visited[501][501] = {};
    char state[501][501];

    cin >> H >> W;

    int x, y;

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

    stack<pair<int, int>> st;
    st.push(make_pair(x, y));

    while (!st.empty()) {
      pair<int, int> p = st.top();
      st.pop();

      x = p.first;
      y = p.second;

      if (!visited[y][x]) {
        if (state[y][x] == 'g') {
          cout << "Yes" << endl;
          return 0;
        }
        if (state[y][x] != '#') {
          if (x > 0) st.push(make_pair(x - 1, y));
          if (y > 0) st.push(make_pair(x, y - 1));
          if (x < W - 1) st.push(make_pair(x + 1, y));
          if (y < H - 1) st.push(make_pair(x, y + 1));
        }
      }
      visited[y][x] = true;
    }
    cout << "No" << endl;
    return 0;
}
