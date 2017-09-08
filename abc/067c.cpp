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
#include <numeric>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> a(N, 0);
    int64_t total = 0;
    for (int i = 0; i < N; i++) {
      int64_t c;
      cin >> c;
      a[i] = c;
      total += c;
    }

    int64_t current = 0;
    int64_t diff = INT64_MAX;

    for (int i=0; i<a.size()-1; i++) {
      current += a[i];
      diff = min(diff, abs(total - 2 * current));
    }

    cout << diff << endl;
    return 0;
}
