#ifndef BSEARCH_H
#define BSEARCH_H

#include "templ/main.h"

ttt > il T safe_mid(T lo, T hi) { return (lo & hi) + ((lo ^ hi) >> 1); }

ttt, typename F > T find_fst(T lo, T hi, F f) {
  if (lo > hi || !f(hi)) return hi + 1;
  while (lo < hi) {
    T mid = safe_mid(lo, hi);
    f(mid) ? hi = mid : lo = mid + 1;
  }
  return lo;
}

ttt, typename F > T find_lst(T lo, T hi, F f) {
  if (lo > hi || !f(lo)) return lo - 1;
  while (lo < hi) {
    T mid = safe_mid(lo, hi + 1);
    f(mid) ? lo = mid : hi = mid - 1;
  }
  return lo;
}

#endif
