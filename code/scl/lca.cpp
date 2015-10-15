int LCA(int u, int v) {
  if (d1[u]<d1[v]) swap(u,v);
  for (int i=maxl-1; i>=0; --i)
    if (d1[ath[u][i]]>=d1[v]) u=ath[u][i];
  if (u == v) return u;
  for (int i=maxl-1; i>=0; --i)
    if (ath[u][i]^ath[v][i]) u=ath[u][i],v=ath[v][i];
  return ath[u][0];
} 
