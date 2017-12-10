

# テンプレート

- [template.cpp](template.cpp)

# チェックリスト

- 入力フォーマットは確認したか (文字列か、空白区切か)
- 初期化
  - 配列は正しく初期化しているか
    - 全て 0 出ない場合はループを回す
    - 大きすぎる配列はグローバルに置く(スタックに置けない)
    - 配列の区切りにカンマを書く (要素が文字列で間に改行が入る場合、カンマが抜けてないか)
  - 変数は正しく初期化されているか
    - 条件付き初期化の場合のデフォルトに注意！
- 計算結果は正しいか
  - 式の途中で int / doubleの除算が混在し、意図しない結果になっていないか
  - 桁あふれしそうなところはないか
  - 負の値があり得るところに、unsignedを使っていないか
- ループの添え字は正しいか
  - 逆回しのループはできるだけ避ける。 `i--` になっているか確認する
- 更新式はシンプルか
  - 更新後の値で条件判定しなければならない場合は一時変数を使う
- 非正常処理 ("NO", "IMPOSSIBLE")は正しく考慮されているか
- 出力フォーマットは正しいか
  - 要求された精度で出力できているか
  - 末尾に改行がいるか
  - 一定の条件でフィルタして出力する際、出力の区切り(スペース、改行は正しいか)。先頭/末尾がフィルタされても正しく動くか

# 基本

- 論理演算 `and`, `or`, `not` を使う
- 三項演算 `cond ? true : false`
- `swap(a, b)`

# 数値

|型名|ビット数|範囲|下限|上限|
|:--:|:--:|:--:|:--:|:--:|
| `int` | 32 | -10^9 〜 10^9 | `INT_MIN` | `INT_MAX` |
| `int64_t` | 64 | -10^18 〜10^18 | `INT64_MIN` | `INT64_MAX` |
| `long long` | 64 | | | |
| `uint64_t` | 64 | | `UINT64_MIN` | `UINT64_MAX` |
| `double` | 64 | | | | |

- 桁が大きい場合、掛け算、割り算の順序によるオーバーフローに注意
- `min`, `max`, `abs`
- 切り上げ除算: `(a + b - 1) / b`
- 四捨五入: `(int)(a + 0.5)`
- キャスト: `(double)a / b`
- 誤差: 丸めの方向を考える
  ```
  const double EPS = 1e-10;
  a <= b + EPS
  a < b - EPS
  ```

- 円周率: `const double PI = acos(-1.0)`
- 最大公約数: `__gcd`
- 最小公倍数: `ab = gcd * lcm`
- 繰り返し2乗法 `x ^ n` [mathlib.cpp](src/mathlib.cpp)

# 入出力

呼び出しが1万回を超える場合は Cストリームを使う

## 入力

- フォーマット指定: `scanf("%d/%d/%d", &y, &m, &d)`
  - `scanf` と `cin` を混在させてはならない
  - 必ず AtCoder のコードテストで動作確認
- 空白を含む行の読み込み
```
// 直前まで cin を使っていた場合
cin.ignore();
string s;
getline(cin, s);
```

## 出力

- フォーマット指定`printf("%.10f\n", ans)`

# 実行時間の見積もり

## 目安

|実行時間($10^n$形式)|実行時間(一般形式)|実行時間制限に間に合うかどうか|
|:--:|:--:|:--:|
| O(10^6) | O(100万) |余裕で間に合う|
| O(10^7) | O(1,000万) |おそらく間に合う|
| O(10^8) | O(1億) |非常にシンプルな処理でない限り、間に合わない|

# 文字列 (`string`)

- 初期化時に値を入れる `string a("abc")`
- 文字列の長さ `str.size()`
- 検索 `str.find()`
  - `if (s.find(c) == std::string::npos) {`
- 文字列連結 `str1 + str2`
- (部分文字列) `str.substr(pos,len)``;
- 置換
  - 開始位置と長さを指定 `s.replace(9, 3, "xxx")`
  - 特定文字を置換: `std::replace(s.begin(), s.end(), 'a', 'b')`;
- (ASCIIコード)
  - ```for (char c='a'; c<='z'; c++) {```
- 変換: `to_string(i)`
- 配列を結合
  ```
  vector<string> ss; // 入力で受け取った string の配列
  string s = accumulate(ss.begin(), ss.end(), string());
  ```

# ビット演算

- 使える場合は `bitset` を使う
- シフト 左: `<<`, 右: `>>`
  - これが入るときはカッコをつけて計算順序を保証
- 立っているビットの個数を数える: `__builtin_popcount`
- Leading Zeroを数える: `__builtin_clz`
- Trailing Zeroを数える: `__builtin_ctz`
- プリントデバッグ
  ```
  template<class val>
  void print_binary(val x, int width) {
    cout << x << endl;
    val bit = (1 << (width - 1));
    for (int i = 0; i < width; i++) {
      if (x & bit)
        putchar('1');
      else
        putchar('0');
      bit >>= 1;
    }
    printf("\n");
  }
  ```

- 回転シフト [bitlib.cpp](src/bitlib.cpp)

# 配列

- 初期化
  - ゼロ初期化: `int a[3] = {}`
  - `int a[3] = {100}` はダメ。
  - 配列は必ず初期化する
- 数え上げ: `count(f, t, x)`
  - 変数名に `count`を使わないこと！
- 初期化: `fill(f, t, x)`

- `vector`
  - `vector<int> a(N, 0)` は長さ N を要素 0 で初期化 (書き換え前提)
  - `vector<int> a` なら長さ 0 で初期化 (`push_back` 前提)

- 配列の合計
  ```
  accumulate(a.begin(), a.end(), 0LL )
  ```
- 最大、最小
  ```
  int ma = *max_element(a, a + N);
  int mi = *min_element(a, a + N);
  ```
- 出力
  ```
  REP(i, a.size) {
    cout << a[i] << endl;
  }
  ```

- 逆順
  ```
  REPR(i, a.size - 1) {
    cout << a[i] << endl;
  }
  ```

- 相互変換
  ```
  // set -> vector
  vector<int> vec(s.begin(), s.end());

  // vector -> set
  set<int> s2(vec.begin(), vec.end());
  ```

# ソート、順序変更

- 昇順: `sort(arr, arr + N)`
- 降順: `sort(arr, arr + N, greater<int>())`
- `stable_sort`
- 逆転: `reverse`
- 順列生成
  ```
  sort(v.begin(), v.end());
  do {
    for(auto x : v) cout << x << " "; cout << "\n";
  } while (next_permutation(v.begin(), v.end()));
  ```

# 連想配列

- key と value を入れ替え [containerlib.cpp](src/containerlib.cpp)
- カウンター [containerlib.cpp](src/containerlib.cpp)

# アルゴリズム

- grundy数
- BFS, DFS
  ```
  // 右、下、左、上
  const int dx[4] = {1, 0, -1, 0};
  const int dy[4] = {0, 1, 0, -1};

  class Point {
   public:
    int x;
    int y;

    Point(int xx, int yy) {
      x = xx;
      y = yy;
    }
  };

  struct Searcher2D {
    int W, H;
    vector<vector<bool>> visited;
    explicit Searcher2D(int width, int height) {
      W = width;
      H = height;
      visited = vector<vector<bool>>(H, vector<bool>(W, false));
    }
    int search(int x, int y) {
      // stack<Point> container;   // DFS
      queue<Point> container;      // BFS
      container.push(Point(x, y));

      while (!container.empty()) {
        // Point p = container.top();     // DFS
        Point p = container.front();      // BFS
        container.pop();

        for (int i = 0; i < 4; i++) {
          int nx = p.x + dx[i];
          int ny = p.y + dy[i];
          if (nx >= 0 && nx < W && ny >= 0 && ny < H) {
            if (!visited[ny][nx]) {

              // 適当な処理を追加

              container.push(Point(nx, ny));
            }
          }
        }
        visited[p.y][p.x] = true;
      }
      return 0;
    }
  };
  ```
- メモ化再帰
- 動的計画法（DP）
- 累積和 [containerlib.cpp](src/containerlib.cpp)
- いもす法
  ```
  for (int i = 0; i < T; i++) table[i] = 0;
  for (int i = 0; i < C; i++) {
      table[S[i]]++;  // 入店処理: カウントを 1 増やす
      table[E[i]]--;  // 出店処理: カウントを 1 減らす
  }
  // シミュレート
  for (int i = 0; i < T; i++) {
      if (0 < i) table[i] += table[i - 1];
  }
  // 最大値を調べる
  M = 0;
  for (int i = 0; i < T; i++) {
      if (M < table[i]) M = table[i];
  }
  ```
- しゃくとり法

```
int current = 0;
int li = 0;
int ri = 0;
while (li < N && ri < N) {
  while (liが条件を満たす && li < N) {
    current に v[li] を追加する処理;
    li++;
  }
  区間が条件を満たす場合 求めたい値を更新;
  current から v[ri] を除外する処理;
  ri++;
}
```

- 二分探索 (最小値、最大値)
  - `lower_bound(a.begin(), a.end(), k)` k以上の値が初めて現れる位置へのイテレータ
  - `upper_bound(a.begin(), a.end(), k)` kより大きい値が初めて現れる位置へのイテレータ
    - 位置を取りたい場合は `it - a.begin()`
    - ある値の個数 `lower_bound(a, a + N, x) - upper_bound(a, a + N, x)`
    - x より真に小さい値の個数 `lower_bound(a, a + N, x) - a`
    - x より真に大きい値の個数 `N - (upper_bound(a, a + N, x) - a)`

  ```
  ll binary_search(ll low, ll high, std::function<bool(ll)> check){
    if(high-low==1){
      return low;
    }
    ll mid = (high+low)/2;
    if(check(mid)){
      return binary_search(mid, high, check);
    }else{
      return binary_search(low, mid, check);
    }
  }
  ```

  ```
  while (right - left > 1) {
    ll trial = (left + right) / 2;
    ...
    if (...) {
      right = trial;
    } else {
      left = trial;
    }
  }
  ```

- 三分探索
- 階乗のmod逆元
- ダブリング（数列）
- Union-Find木 [graphlib.cpp](src/graphlib.cpp)
- セグメント木（遅延評価なし）
- BIT

# STL(標準テンプレートライブラリ)

- [`array`](http://en.cppreference.com/w/cpp/container/array)
- [`vector`](http://en.cppreference.com/w/cpp/container/vector)
- [`queue`](http://en.cppreference.com/w/cpp/container/queue)
- [`stack`](http://en.cppreference.com/w/cpp/container/stack)
- [`deque`](http://en.cppreference.com/w/cpp/container/deque)
- [`priority_queue`](http://en.cppreference.com/w/cpp/container/priority_queue)
- [`list`](http://en.cppreference.com/w/cpp/container/list)
- [`set`](http://en.cppreference.com/w/cpp/container/set)
- [`map`](http://en.cppreference.com/w/cpp/container/map)
- [`string`](http://en.cppreference.com/w/cpp/string/basic_string)

# 場合の数

- 場合の数 [mathlib.cpp](src/mathlib.cpp)
- 完全順列

```
template <typename T>
T derangement(T N) {
  if (N <= 1) {
    return 0;
  } else if (N == 2) {
    return 1;
  }
  T p2 = 0, p1 = 1;
  for (T i = 3; i <= N; i++) {
    T n = (i - 1) * (p1 + p2);
    p2 = p1;
    p1 = n;
  }
  return p1;
}
```

# 日時

- [datetimelib.cpp](src/datetimelib.cpp)

# 座標平面

```
// 右、下、左、上
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

// 右、右下、下、左下、左、左上、上、右上
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
```

斜めを含む場合、横方向と縦方向を分けて管理した方が良い場合もある

# グラフ

- 最短経路(ダイクストラ法) [graphlib.cpp](src/graphlib.cpp)
- 全点対間最小路 (Floyd Warshall)  [graphlib.cpp](src/graphlib.cpp)
- 最小全域木(クラスカル法) [graphlib.cpp](src/graphlib.cpp)
- 最大流(Dinic法) [graphlib.cpp](src/graphlib.cpp)

# 平面幾何

-[geomlib.cpp](src/geomlib.cpp)


- 三角形の面積
  ```
  abs((xa - xc) * (yb - yc) - (xb - xc) * (ya - yc)) / 2.0
  ```
