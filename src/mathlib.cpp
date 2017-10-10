#include <assert.h>
#include <iostream>
#include <vector>

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

template<class T>
bool is_prime(T n) {
  switch (n) {
    case 0: return false;
    case 1: return false;
    case 2: return true;
    case 3: return true;
  }
  if (n % 2 == 0) return false;
  if (n % 3 == 0) return false;

  if (n % 6 != 1 && n % 6 != 5) return false;
  for (int i = 5; i * i <= n; i += 6) {
    if (n % i == 0) return false;
    if (n % (i + 2) == 0) return false;
  }
  return true;
}

template<class T>
vector<T> eratosthenes(T n) {
  // ある数が素数でない場合に true
  vector<bool> dp(n, false);
  dp[0] = true;
  dp[1] = true;
  vector<T> prime;
  for (int i = 2; i < n; i++) {
    if (dp[i]) continue;
    prime.push_back(i);
    for (int j = i * 2; j < n; j += i) {
      dp[j] = true;
    }
  }
  return prime;
}

template<class T>
ll pow(T x, T n) {
  ll ans = 1;
  while (n > 0) {
    if ((n & 1) == 1) {
      ans = ans * x;
    }
    x = x * x;
    n >>= 1;
  }
  return ans;
}

template <typename T>
ull comb(T n, T k) {
  assert(n >= k);
  T r = 1;
  for (ull d = 1; d <= k; ++d) {
    r *= n--;
    r /= d;
  }
  return r;
}

void test_prime() {
  assert(!is_prime(0));
  assert(!is_prime(1));
  assert(is_prime(2));
  assert(is_prime(3));
  assert(!is_prime(4));
  assert(is_prime(5));
  assert(!is_prime(6));
  assert(is_prime(7));
  assert(is_prime(19));
  assert(!is_prime(20));
  assert(!is_prime(21));
  assert(!is_prime(22));
  assert(is_prime(23));

  // https://oeis.org/A000040
  vector<int> primes = eratosthenes(272);
  vector<int> expected = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43,
                          47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103,
                          107, 109, 113, 127, 131, 137, 139, 149, 151, 157,
                          163, 167, 173, 179, 181, 191, 193, 197, 199, 211,
                          223, 227, 229, 233, 239, 241, 251, 257, 263, 269,
                          271};
  assert(primes == expected);
  for (auto e : expected) {
    assert(is_prime(e));
  }
}

void test_pow() {
  assert(pow(2, 3) == 8);
  assert(pow(2, 0) == 1);
  assert(pow(3, 3) == 27);
}

void test_comb() {
  assert(comb(1, 0) == 1);
  assert(comb(1, 1) == 1);

  assert(comb(3, 0) == 1);
  assert(comb(3, 1) == 3);
  assert(comb(3, 2) == 3);

  assert(comb(5, 0) == 1);
  assert(comb(5, 2) == 10);
  assert(comb(5, 3) == 10);
  assert(comb(5, 4) == 5);

  assert(comb(10, 5) == 252);
}

int main() {
  test_prime();
  test_pow();
  test_comb();

  cout << "SUCCESS!!" << endl;
  return 0;
}
