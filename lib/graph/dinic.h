#ifndef DINIC_H
#define DINIC_H

#include "templ/main.h"

struct Dinic {
  using Flow = ll;
  struct Edge {
    int v;
    Flow c;
  };

  int n, m = 0, s, t;
  vi lv;
  vec<vi> adj;
  vec<vi::iterator> cur;
  vec<Edge> e;

  Dinic(int n_, int s_, int t_) : n{n_}, s{s_}, t{t_}, lv(n), adj(n), cur(n) {}
  explicit Dinic(int n_) : Dinic(n_ + 2, n_, n_ + 1) {}

  void link(int u, int v, Flow c, bool dir = true) {
    adj[u].pb(m++), e.pb({v, c});
    adj[v].pb(m++), e.pb({u, dir ? 0 : c});
  }
  bool bfs() {
    fill(all(lv), 0), lv[s] = 1;
    queue<int> q{{s}};
    while (!q.empty()) {
      int u = q.ft;
      q.pop();
      each (i, adj[u]) {
        int v = e[i].v;
        if (!lv[v] && e[i].c) lv[v] = lv[u] + 1, q.push(v);
      }
    }
    return lv[t];
  }
  Flow dfs(int u, Flow f) {
    if (u == t) return f;
    Flow o = f;
    for (; cur[u] < end(adj[u]); ++cur[u]) {
      int i = *cur[u], v = e[i].v;
      if (lv[v] == lv[u] + 1 && e[i].c) {
        Flow d = dfs(v, min(f, e[i].c));
        if (!d)
          lv[v] = 0;
        else {
          f -= d, e[i].c -= d, e[i ^ 1].c += d;
          if (!f) break;
        }
      }
    }
    return o - f;
  }
  Flow flow() {
    Flow f = 0;
    while (bfs()) {
      F0R (i, n) cur[i] = bg(adj[i]);
      f += dfs(s, numeric_limits<Flow>::max());
    }
    return f;
  }
};

#endif
