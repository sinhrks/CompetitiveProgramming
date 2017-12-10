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

    int H, W, A, B;
    cin >> H >> W >> A >> B;

    string garden[201] = {};
    for (int i = 0; i < H; i++) {
      cin >> garden[i];
    }
    int stones = 0;
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        if (garden[i][j] == 'S') {
          stones++;
        }
      }
    }

    int h, w;
    h = H / 2;
    w = W / 2;

    int ab = 0;
    int a = 0;
    int b = 0;

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        int pat = 0;
        if (garden[i][j] == 'S') pat |= 1;
        if (garden[H - i - 1][j] == 'S') pat |= 2;
        if (garden[i][W - j - 1] == 'S') pat |= 4;
        if (garden[H - i - 1][W - j - 1] == 'S') pat |= 8;
        if (pat == 15) {
          ab++;
        } else {
          if ((pat & 3) == 3 || (pat & 12) == 12) a++;
          if ((pat & 5) == 5 || (pat & 10) == 10) b++;
        }
      }
    }

    int total1 = 0;
    if (ab * 4 + 2 * a != stones) total1 += A;
    total1 += a * A;
    if (ab * 4 != stones) total1 += B;
    total1 += ab * (max(A, B) + A + B);

    int total2 = 0;
    if (ab * 4 + 2 * b != stones) total2 += B;
    total2 += b * B;
    if (ab * 4 != stones) total2 += A;
    total2 += ab * (max(A, B) + A + B);

    cout << max(total1, total2) << endl;
    return 0;
}
