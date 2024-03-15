#ifndef MCMF_H
#define MCMF_H

#include "templ/main.h"

struct Mcmf {
  using Flow = int;
  using Cost = int;
  struct Edge {
    int v;
    Flow c;
    Cost w;
  };

  int n, m = 0, s, t;
  vi pre;
  V<vi> adj;
  vb vis;
  V<Cost> dis, p;
  V<Edge> e;

  Mcmf(int n_, int s_, int t_)
      : n{n_}, s{s_}, t{t_}, pre(n), adj(n), vis(n), dis(n), p(n) {}
  Mcmf(int n_) : Mcmf(n_ + 2, n_, n_ + 1) {}

  void link(int u, int v, Flow c, Cost w) {
    adj[u].pb(m++), e.pb({v, c, w});
    adj[v].pb(m++), e.pb({u, 0, -w});
  }
  bool dijkstra() {
    fill(all(vis), false);
    constexpr Cost inf = numeric_limits<Cost>::max();
    fill(all(dis), inf), dis[s] = 0;
    pqg<pair<Cost, int>> q;
    q.emplace(0, s);
    while (!q.empty()) {
      auto [d, u] = q.top();
      q.pop();
      if (vis[u]) continue;
      vis[u] = true;
      each (i, adj[u]) {
        int v = e[i].v;
        if (e[i].c && ckmin(dis[v], d + e[i].w + p[u] - p[v]))
          pre[v] = i, q.emplace(dis[v], v);
      }
    }
    return dis[t] < inf;
  }
  pair<Flow, Cost> flow() {
    rep (n)
      F0R (i, m)
        if (e[i].c) ckmin(p[e[i].v], p[e[i ^ 1].v] + e[i].w);
    Flow f = 0;
    Cost c = 0;
    while (dijkstra()) {
      Flow d = numeric_limits<Flow>::max();
      for (int u = t; u != s; u = e[pre[u] ^ 1].v) ckmin(d, e[pre[u]].c);
      f += d, c += d * (dis[t] + p[t]);
      for (int u = t; u != s; u = e[pre[u] ^ 1].v)
        e[pre[u]].c -= d, e[pre[u] ^ 1].c += d;
      F0R (i, n) p[i] += dis[i];
    }
    return {f, c};
  }
};

#endif
