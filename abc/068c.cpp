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

    set<int> from;
    set<int> to;
    int f, t;

    for (int i=0; i<M; i++) {
      cin >> f >> t;

      if (f == 1) {
        from.insert(t);
      }
      if (t == N) {
        to.insert(f);
      }
    }

    for(auto i=from.begin(); i != from.end(); ++i) {
      if (to.find(*i) != to.end()) {
        cout << "POSSIBLE" << endl;
        return 0;
      }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
