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

  int H, W;
  cin >> H >> W;
  string S[55];

  for (int i = 0; i < H; i++) {
    cin >> S[i];
  }

  int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
  int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {

      if (S[i][j] == '#') continue;

      int count = 0;
      for (int k = 0; k < 8; k++) {
        if (i + dy[k] >= 0 && i + dy[k] < H &&
          j + dx[k] >= 0 && j + dx[k] < W) {
          if (S[i + dy[k]][j + dx[k]] == '#') {
            count++;
          }
        }
      }
      S[i][j] = '0' + count;
    }
  }
  for (int i = 0; i < H; i++) {
    cout << S[i] << endl;
  }

  return 0;
}
