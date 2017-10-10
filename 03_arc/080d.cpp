#include <assert.h>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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

using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int H, W, N;
  cin >> H >> W >> N;

  int a[10001] = {};
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  int ai = 0;
  int colors[100][101] = {};
  for (int i = 0; i < H; i++) {
    if (i % 2 == 0) {
      for (int j = 0; j < W; j++) {
        if (a[ai] == 0) {
          ai++;
        }
        colors[i][j] = ai + 1;
        a[ai]--;
      }
    } else {
      for (int j = W - 1; j >= 0; j--) {
        if (a[ai] == 0) {
          ai++;
        }
        colors[i][j] = ai + 1;
        a[ai]--;
      }
    }
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cout << colors[i][j];
      if (j < W - 1) {
        cout << " ";
      }
    }
    cout << endl;
  }
  return 0;
}
