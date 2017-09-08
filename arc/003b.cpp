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

    int N;
    cin >> N;

    string v[100];

    for (int i = 0; i < N; i++) {
      string tmp;
      cin >> tmp;
      reverse(tmp.begin(), tmp.end());
      v[i] = tmp;
    }
    sort(v, v + N);

    for (int i = 0; i < N; i++) {
      string tmp;
      tmp = v[i];
      reverse(tmp.begin(), tmp.end());
      cout << tmp << endl;
    }
    return 0;
}
