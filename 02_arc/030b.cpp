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

int n, x;
int h[100] = {};
bool conn[100][100] = {};
bool visited[100] = {};

int search(int idx) {
  visited[idx] = true;

  int res = 0;
  for (int i = 0; i < n; i++) {
    if (conn[idx][i] & !visited[i]) {
      res += search(i);
    }
  }
  if (res == 0 && h[idx] == 0) {
    return 0;
  } else {
    if (idx == x) {
      return res;
    } else {
      return 2 + res;
    }
  }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> x;
    x--;

    for (int i = 0; i < n; i++) {
      cin >> h[i];
    }

    for (int i = 0; i < n - 1; i++) {
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      conn[a][b] = true;
      conn[b][a] = true;
    }

    cout << search(x) << endl;
    return 0;
}
