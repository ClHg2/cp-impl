#ifndef MAIN_H
#define MAIN_H

#include <bits/stdc++.h>

#define FOR(i, l, r) for (int i = l; i < (r); ++i)
#define F0R(i, r) FOR (i, 0, r)
#define ROF(i, l, r) for (int i = r; i-- > (l);)
#define R0F(i, r) ROF (i, 0, r)
#define rep(n) F0R (_, n)
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

#define sz(x) int((x).size())
#define bg begin
#define all(x) bg(x), end(x)
#define sor(x) sort(all(x))
#define rsz resize
#define pb push_back
#define eb emplace_back
#define ft front()
#define bk back()

#define il inline
#define lb lower_bound
#define ub upper_bound
ttt > il int lwb(const vec<T>& a, const T& v) { return lb(all(a), v) - bg(a); }
ttt > il int upb(const vec<T>& a, const T& v) { return ub(all(a), v) - bg(a); }

ttt > il bool ckmin(T& x, const T& y) { return y < x ? x = y, true : false; }
ttt > il bool ckmax(T& x, const T& y) { return x < y ? x = y, true : false; }

#endif
