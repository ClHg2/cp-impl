#ifndef BIT_H
#define BIT_H

#include "templ/main.h"

il int p2(int k) { return 1 << k; }
il int msk2(int k) { return p2(k) - 1; }

il int pct(int n) { return __builtin_popcount(n); }
il int pct(ll n) { return __builtin_popcountll(n); }
il int pct2(int n) { return __builtin_parity(n); }
il int pct2(ll n) { return __builtin_parityll(n); }
il int lsb(int n) { return __builtin_clz(n); }
il int lsb(ll n) { return __builtin_clzll(n); }
il int msb(int n) { return n == 0 ? -1 : 31 ^ __builtin_clz(n); }
il int msb(ll n) { return n == 0 ? -1 : 63 ^ __builtin_clzll(n); }

#endif
