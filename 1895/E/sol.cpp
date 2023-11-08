#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e5+5;
int adj[N][2], dp[N][2];
bool dis[N][2];

int dfs(int u, int x){
  if(dp[u][x]!=-1) return dp[u][x];
  dis[u][x]=true;
  if(adj[u][x]==-1) return dp[u][x] = x;
  if(dis[adj[u][x]][(x+1)%2]&&dp[adj[u][x]][(x+1)%2]==-1) return dp[u][x] = 2;
  return dp[u][x] = dfs(adj[u][x], (x+1)%2);
}

int main(){
  int TC, n, m;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    pair<int,int> a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i].first), dis[i][0]=false, dp[i][0]=-1;
    for (int i = 0; i < n; i++) scanf("%d", &a[i].second);
    scanf("%d", &m);
    pair<int, int> b[m];
    int la[n+1], lb[m+1];
    for (int i = 0; i < m; i++) scanf("%d", &b[i].first), dis[i][1]=false, dp[i][1]=-1;
    for (int i = 0; i < m; i++) scanf("%d", &b[i].second);
    sort(a, a+n);
    sort(b, b+m);
    la[n-1]=n-1, lb[m-1]=m-1;
    la[n]=lb[m]=-1;
    for (int i = n-2; i >=0; i--){
      if(a[i].second>a[la[i+1]].second) la[i]=i;
      else la[i]=la[i+1];
    }
    for (int i = m-2; i >=0; i--){
      if(b[i].second>b[lb[i+1]].second) lb[i]=i;
      else lb[i]=lb[i+1];
    }
    for (int i = 0; i < n; i++){
      int v = upper_bound(b,b+m, make_pair(a[i].second+1,0))-b;
      adj[i][0] = lb[v];
    }
    for (int i = 0; i < m; i++){
      int v = upper_bound(a,a+n, make_pair(b[i].second+1,0))-a;
      adj[i][1] = la[v];
    }
    int w=0, t=0, l=0;
    for (int i = 0; i < n; i++){
      int y = dfs(i, 0);
      w+=y==0,t+=y==2,l+=y==1;
    }
    printf("%d %d %d\n", w, t, l);
  }   
}