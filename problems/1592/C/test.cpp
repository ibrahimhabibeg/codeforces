#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5+5;
int a[N], xr[N];
vector<int> adj[N];
bool isOddYes;

int dfs(int u, int p){
  xr[u] = a[u];
  for (int v: adj[u]) if(v!=p) xr[u]^=dfs(v,u);
  return xr[u];
}

bool dfs2(int u, int p){
  bool res = xr[u]==xr[1];
  int cnt = 0;
  for (int v: adj[u]) if(v!=p) {
    bool d = dfs2(v,u);
    cnt+=d, res|=d;
  }
  if(cnt>1) isOddYes = true;
  return res;
}

int main(){
  int a[] = {377804615, 522874068, 101778092, 409548873, 334317788, 230030759, 377804615, 295237531, 404145046};
  int res = 0;
  for (int i = 0; i < 9; i++) res^=a[i];
  printf("%d", res);
}