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

template<class key, class val>
map<val, key> map_inverse(const map<key, val>& from) {
map<val, key> result;
  for (auto& kv : from) {
    result[kv.second] = kv.first;
  }
  return result;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    map<int, int> m;
    for (int i = 0; i < 10; i++) {
      int c;
      cin >> c;
      m.insert(make_pair(c, i));
    }

    int N;
    cin >> N;

    vector<int> v;
    for (int i = 0; i < N; i++) {
      string temp;
      cin >> temp;

      for (int j = 0; j < temp.size(); j++) {
        temp[j] = (char)(m[temp[j] - '0'] + '0');
      }
      v.push_back(stoi(temp));
    }
    sort(v.begin(), v.end());

    map<int, int> inv;
    inv = map_inverse(m);
    for (auto& r : v) {
      string temp = to_string(r);
      for (int j = 0; j < temp.size(); j++) {
        temp[j] = (char)(inv[temp[j] - '0'] + '0');
      }
      cout << temp << endl;
    }
    return 0;
}
