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

    int N, M, A, B;
    cin >> N >> M >> A >> B;
    for (int i = 1; i <= M; i++) {
      if (N <= A) {
        N += B;
      }

      int c;
      cin >> c;

      N -= c;

      if (N < 0) {
        cout << i << endl;
        return 0;
      }
    }

    cout << "complete" << endl;
    return 0;
}
