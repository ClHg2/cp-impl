#ifndef MINT_H
#define MINT_H

#include "templ/main.h"

constexpr int mod = 998244353;
namespace mint {
il int norm(int x) { return x - (x >= mod) * mod; }
il void add(int& x, int y) { x = norm(x + y); }
il int fix(int x) { return x + (x < 0) * mod; }
il void sub(int& x, int y) { x = fix(x - y); }
ll qpow(ll a, int b) {
  ll ans = 1;
  for (; b; b >>= 1) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
  }
  return ans;
}
il ll inv(ll a) { return qpow(a, mod - 2); }
}  // namespace mint

#endif
