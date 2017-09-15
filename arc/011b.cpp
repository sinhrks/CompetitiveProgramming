#include <algorithm>
#include <numeric>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <string>
#include <array>
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

    map<char, int> m;
    m['b'] = 1;
    m['c'] = 1;
    m['d'] = 2;
    m['w'] = 2;
    m['t'] = 3;
    m['j'] = 3;
    m['f'] = 4;
    m['q'] = 4;
    m['l'] = 5;
    m['v'] = 5;
    m['s'] = 6;
    m['x'] = 6;
    m['p'] = 7;
    m['m'] = 7;
    m['h'] = 8;
    m['k'] = 8;
    m['n'] = 9;
    m['g'] = 9;
    m['z'] = 0;
    m['r'] = 0;

    int N;
    cin >> N;

    vector<string> results;
    for (int i = 0; i < N; i++) {
      string w;
      cin >> w;

      string o("");
      for (int j = 0; j < w.size(); j++) {
        char c = tolower(w[j]);
        auto itr = m.find(c);
        if (itr != m.end()) {
            o = o + to_string(itr->second);
        }
      }
      if (o != "") {
        results.push_back(o);
      }
    }
    for (int i = 0; i < results.size(); i++) {
      cout << results[i];
      if (i < results.size() - 1) {
        cout << " ";
      }
    }
    cout << endl;
    return 0;
}
