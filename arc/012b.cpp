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
    double va, vb, L;
    cin >> N >> va >> vb >> L;

    for (int i = 0; i < N; i++) {
      L = vb * L / va;
    }
    printf("%.7f\n", L);
    return 0;
}
