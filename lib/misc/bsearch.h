#ifndef BSEARCH_H
#define BSEARCH_H

#include "templ/main.h"

ttt > il T safe_mid(T l, T r) { return (l & r) + ((l ^ r) >> 1); }

ttt, typename F > T find_fst(T l, T r, F f) {
  if (l > r || !f(r)) return r + 1;
  while (l < r) {
    T mid = safe_mid(l, r);
    f(mid) ? r = mid : l = mid + 1;
  }
  return l;
}

ttt, typename F > T find_lst(T l, T r, F f) {
  if (l > r || !f(l)) return l - 1;
  while (l < r) {
    T mid = safe_mid(l, r + 1);
    f(mid) ? l = mid : r = mid - 1;
  }
  return l;
}

#endif
