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

template<class key, class val>
map<val, key> map_inverse(map<key, val> from) {
  map<val, key> result;
  for (typename map<key, val>::iterator it = from.begin();
       it != from.end(); ++it) {
    result[it->second] = it->first;
  }
  return result;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    map<int, int> disks;
    for (int i = 1; i <= N; i++) {
      disks.insert(make_pair(i, i));
    }

    int disk = 0;
    for (int i = 0; i < M; i++) {
      int current;
      cin >> current;
      int c;
      c = disks[current];

      disks[disk] = c;
      disk = current;
      disks.erase(current);
    }

    map<int, int> cases = map_inverse(disks);

    for (int i = 1; i <= N; i++) {
      cout << cases[i] << endl;
    }
    return 0;
}
