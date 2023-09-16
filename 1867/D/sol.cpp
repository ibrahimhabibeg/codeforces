#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 +5;
int adj[N], c[N], L[N];

int dfs(int u){
  if(L[u]!=0) return L[u];
  if(c[u]==0) c[u] = 1;
  if(c[adj[u]]!=0){
    if(L[adj[u]]) return L[u] = L[adj[u]];
    else return L[u] = c[u] - c[adj[u]] + 1;
  } 
  else{
    c[adj[u]] = c[u] + 1;
    return L[u] = dfs(adj[u]);
  }
}

int main(){
  int TC, n, a, k;
  cin >> TC;
  while (TC--){
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a), adj[i] = a, L[i] = 0, c[i] = 0;
    bool isYes = true;
    for (int i = 1; i <= n; i++) if(dfs(i)!=k || (k==1 && adj[i]!=i)){
      isYes = false;
      break;
    }
    if(isYes) printf("YES\n");
    else printf("NO\n");
  }   
}