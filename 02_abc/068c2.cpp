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

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    bool to[200000] = {};
    bool from[200000] = {};
    int f, t;

    for (int i=0; i<M; i++) {
      cin >> f >> t;

      if (f == 1) {
        to[t] = true;
      }
      if (t == N) {
        from[f] = true;
      }
    }

    if (from[1]) {
      cout << "POSSIBLE" << endl;
      return 0;
    }

    for (int i=0; i<N; i++) {
      if (to[i] and from[i]) {
        cout << "POSSIBLE" << endl;
        return 0;
      }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
