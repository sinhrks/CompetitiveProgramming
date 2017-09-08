#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <string>
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

    int N, M;
    cin >> N >> M;

    string name;
    cin >> name;

    string kit;
    cin >> kit;

    int narr[26] = {};
    int karr[26] = {};
    for (int i = 0; i < N; i++) {
      narr[name[i] - 'A']++;
    }
    for (int i = 0; i < M; i++) {
      karr[kit[i] - 'A']++;
    }

    int ans = 0;
    for (int i = 0; i < 26; i++) {
      if (narr[i] > 0) {
        if (karr[i] == 0) {
          cout << -1 << endl;
          return 0;
        }
        ans = max(ans, (narr[i] + karr[i] - 1) / karr[i]);
      }
    }
    cout << ans << endl;
    return 0;
}
