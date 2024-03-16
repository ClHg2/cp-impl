#ifndef DSU_H
#define DSU_H

#include "templ/main.h"

struct Dsu {
  vi f, s;
  explicit Dsu(int n) : f(n), s(n, 1) { iota(all(f), 0); }
  int find(int x) {
    while (x != f[x]) x = f[x] = f[f[x]];
    return x;
  }
  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    if (s[x] > s[y]) swap(x, y);
    return f[x] = y, s[y] += s[x], true;
  }
};

#endif
