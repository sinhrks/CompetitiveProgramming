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

const int N_MAX = 101 * 101 + 1;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    array<bool, N_MAX> scores = {};
    scores[0] = true;
    for (int i = 0; i < N; i++) {
      int p;
      cin >> p;
      // 二重に加算されないよう逆方向にループを回す
      for (int j = N_MAX - 1; j >= 0; j--) {
        if (scores[j]) {
          // arrayのindexを超えるのを防ぐ
          scores[p + j] = scores[j];
        }
      }
    }
    int total = accumulate(scores.begin(), scores.end(), 0);
    cout << total << endl;
    return 0;
}
