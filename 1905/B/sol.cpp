#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, a, b;
  cin >> TC;
  while (TC--)
  {
    scanf("%d", &n);
    vector<int> adj(n+1);
    for (int i = 0; i < n-1; i++){
      scanf("%d%d", &a, &b);
      adj[a]++, adj[b]++;
    }
    int c = 0;
    for (int i = 1; i <= n; i++) c+=adj[i]==1;
    printf("%d\n", (c+1)/2);
  }   
}