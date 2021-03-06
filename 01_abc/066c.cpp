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
#include <list>
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

    list<int> a;
    for (int i = 0; i < N; i++) {
      int64_t c;
      cin >> c;
      if (i % 2 == 0) {
        a.push_back(c);
      } else {
        a.push_front(c);
      }
    }

    if (N % 2 == 1) {
      reverse(a.begin(), a.end());
    }

    for (auto i : a) {
      cout << i << " ";
    }
    cout << endl;
    return 0;
}
