#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int N = 5005;
vector<int> adj[N];
int s[N], n;
 
int size(int u, int p){
  s[u] = 1;
  for (int v: adj[u]) if(v!=p) s[u]+=size(v, u);
  return s[u];
}
 
int f(int u, int p){
  vector<int> sz;
  int res = 0, resDown = 0;
  for (int v: adj[u]) if(v!=p) sz.push_back(s[v]), resDown+=f(v, u);
  int m = sz.size();
  vector<int> sum(m);
  if(m==0) return 0;
  sum[0] = sz[0];
  for (int i = 1; i < m; i++) sum[i] = sum[i-1] + sz[i];
  vector<vector<int>> dp(m, vector<int>(sum[m-1]+1));
  for (int i = 0; i < m-1; i++) for (int B = 0; B<=sum[i]; B++) for(int b = 0; b<=sz[i+1]; b++) dp[i+1][B+b] = max(dp[i+1][B+b], dp[i][B] + b*(sum[i]-B)+B*(sz[i+1]-b));
  for (int B = 0; B<=sum[m-1]; B++) res = max(res, dp[m-1][B]);
  return resDown+res;
}
 
int main(){
  int a;
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) 
  scanf("%d", &a), adj[a].push_back(i), adj[i].push_back(a);
  size(1, 0);
  printf("%d", f(1, 0));
}