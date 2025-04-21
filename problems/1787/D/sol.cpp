#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2*1e5 +5, UNDIS  = 0, SEARCH = 1, SUCC = 2, FAIL = 3;
int a[N], n, e[N], cnt[N];
bool p[N], fin;

void path(int u){
  if(u< 0 || u>=n) fin = true;
  else if(p[u]) fin = false;
  else p[u] = true, path(u+a[u]);
}

int ends(int u){
  if(u<0 || u>=n) return SUCC;
  if(e[u]== SUCC || e[u] ==FAIL) return e[u];
  if(e[u]==SEARCH) return e[u] = FAIL;
  e[u] = SEARCH;
  e[u] = ends(u+a[u]);
  if(p[u]) cnt[u] = 1;
  if(u+a[u]>=0 && u+a[u]<n) cnt[u] += cnt[u+a[u]];
  return e[u];
}

int main(){
  int TC;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) p[i] = false, e[i] = UNDIS, cnt[i] = 0;
    int p_cnt = 0, e_cnt = 0;
    path(0);
    for (int i = 0; i < n; i++) ends(i), p_cnt+=p[i], e_cnt+=e[i]==SUCC;
    if(!fin) printf("%lld\n", p_cnt*1LL*(n+1+e_cnt));
    else{
      ll res = (2*n+1)*1LL*(n-p_cnt)+p_cnt*1LL*(n+1);
      for (int i = 0; i < n; i++) if(!p[i]&&e[i]==SUCC) res+=p_cnt - cnt[i];
      for (int i = 0; i < n; i++) if(p[i]) res += cnt[i] - 1;
      printf("%lld\n", res);
    }
  }   
}