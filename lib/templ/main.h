#ifndef MAIN_H
#define MAIN_H

#include <bits/stdc++.h>

#define all(x) begin(x), end(x)
#define dbg(x) #x " = " << (x)
#define each(i, x) for (auto& i : x)

using namespace std;

using ll = long long;
using db = long double;
using str = string;

using pi = pair<int, int>;
#define mp make_pair
#define f first
#define s second

#define ttt template <typename T
ttt > using vec = vector<T>;
ttt, size_t n > using arr = array<T, n>;
using vi = vec<int>;
using vb = vec<bool>;
using vl = vec<ll>;
using vpi = vec<pi>;
#define rsz resize
#define pb push_back
#define eb emplace_back

#define il inline
ttt > il int sz(const T& x) { return x.size(); }
ttt > il bool ckmin(T& x, const T& y) { return y < x ? x = y, true : false; }
ttt > il bool ckmax(T& x, const T& y) { return x < y ? x = y, true : false; }

#endif
