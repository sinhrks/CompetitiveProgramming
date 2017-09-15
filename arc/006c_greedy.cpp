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

    int N;
    cin >> N;

    int weights[100001] = {};
    for (int i = 0; i < N; i++) {
      int w;
      cin >> w;

      int ci = 0;
      for (int j = 0; j < N; j++) {
        if (weights[j] == 0) {
          ci = j;
          break;
        } else if (weights[j] >= w) {
          ci = j;
          break;
        }
      }
      weights[ci] = w;
    }

    int c = 0;
    for (int i = 0; i < N; i++) {
      if (weights[i] > 0) {
        c++;
      }
    }
    cout << c << endl;
    return 0;
}
