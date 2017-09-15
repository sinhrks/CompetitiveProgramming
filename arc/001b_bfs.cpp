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

    int A, B;
    bool visited[41] = {};
    cin >> A >> B;

    visited[A] = true;

    int choice[6] = {1, -1, 5, -5, 10, -10};

    queue<pair<int, int>> container;
    container.push(make_pair(A, 0));

    while (!container.empty()) {
      pair<int, int> tmp = container.front();
      container.pop();

      int current = tmp.first;
      int depth = tmp.second;

      if (current == B) {
        cout << depth << endl;
        return 0;
      }

      for (int i = 0; i < 6; i++) {
        int changed = current + choice[i];
        if (changed < 0 || changed > 40) {
          continue;
        } else if (!visited[changed]) {
          container.push(make_pair(changed, depth + 1));
        }
      }
      visited[current] = true;
    }
    cout << "No" << endl;
    return 0;
}
