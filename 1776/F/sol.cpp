#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void completeGraph(int n, int m){
  int u, v;
  printf("3\n");
  while (m--)
  {
    scanf("%d %d", &u, &v);
    if(u>v) swap(u, v);
    if(u==1 && v==2) printf("1 ");
    else if(u==1) printf("2 ");
    else printf("3 ");
  }
  printf("\n");
}

void nonCompleteGraph(int n, int m){
  printf("2\n");
  vector<pair<int, int>> edges(m);
  vector<vector<int>> adj(n+1);
  for (int i = 0; i < m; i++)
  {
    int u, v;
    scanf("%d %d", &u, &v);
    edges[i] = make_pair(u, v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int s;
  for (int i = 1; i <= n; i++)
    if(adj[i].size()<n-1){
      s = i;
      break;
    }
  for (auto [u, v]: edges)
  {
    if(u==s || v==s) printf("1 ");
    else printf("2 ");
  }
  printf("\n");
}

int main(){
  int TC, n, m;
  cin >> TC;
  while (TC--)
  {
    scanf("%d %d", &n, &m);
    if(m==n*(n-1)/2) completeGraph(n, m);
    else nonCompleteGraph(n, m);
  }   
}