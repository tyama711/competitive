#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, n) for (int i = 0; i < int(n); i++)
#define FOR1(i, m, n) for (int i = int(m); i < int(n); i++)
#define MAX(a, b) ((a) >= (b) ? (a) : (b))
#define MIN(a, b) ((a) <= (b) ? (a) : (b))

template <typename T>
class Vector {
 private:
  vector<T> vec;

 public:
  Vector<T>() {}
  
  Vector<T>(initializer_list<T> il) : vec(il) {}

  void assign(initializer_list<T> il) {
    vec.assign(il);
  }

  int degree() { return vec.size(); }

  T& operator[](const int i) {
    return vec[i];
  }

  Vector<T> operator+(const Vector<T>&& v) const {
    Vector _v(vec);

    FOR(i, vec.size()) _v[i] += v[i];

    return _v;
  }

  Vector<T> operator-(const Vector<T>&& v) const {
    Vector _v(vec);

    FOR(i, vec.size()) _v[i] -= v[i];

    return _v;
  }

  Vector<T> operator*(const T&& x) const {
    Vector _v(vec);

    FOR(i, vec.size()) _v[i] *= x;

    return _v;
  }

  friend Vector<T> operator*(const T&& x, const Vector<T>&& v);

  Vector<T> operator/(const T&& x) const {
    Vector _v(vec);

    FOR(i, vec.size()) _v[i] /= x;

    return _v;
  }

  T inner_product(const Vector<T>&& v) const {
    T ip = 0;

    FOR(i, vec.size()) ip += vec[i] * v[i];

    return ip;
  }

  Vector<T> outer_product(const Vector<T>&& v) const {
    Vector<T> op({0, 0, 0});

    op[0] = vec[1]*v[2] - vec[2]*v[1];
    op[1] = vec[2]*v[0] - vec[0]*v[2];
    op[2] = vec[0]*v[1] - vec[1]*v[0];

    return op;
  }
};

template <typename T>
Vector<T> operator*(const T&& x, const Vector<T>&& v) {
  Vector<T> _v(v);

  FOR(i, v.size()) _v[i] *= x;

  return _v;
}


int main(int argc, char *argv[])
{
  int N;

  scanf("%d", &N);

  vector<Vector<int>> input;
  FOR(i, N) {
    int x, y;
    scanf("%d%d", &x, &y);
    input[i].assign({x, y, 0});
  }

  
  return 0;
}
