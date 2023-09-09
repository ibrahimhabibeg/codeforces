#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    int a[n+1], c[n+1];
    vector<int> sf(n+1);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
    for (int i = 1; i <= n; i++) sf[a[i]]++; 
    set<pair<int, int>> s, cs;
    for (int i = 1; i <= n; i++) s.insert(make_pair(sf[i], i)), cs.insert(make_pair(c[i], i));
    while (!s.empty()){
      auto p = *(s.begin());
      int u = p.second;
      if(p.first!=0){
        p = *(cs.begin());
        u = a[p.second];
      }
      s.erase(make_pair(sf[u], u)), cs.erase(make_pair(c[u], u));
      auto it = s.find(make_pair(sf[a[u]], a[u]));
      sf[a[u]]--;
      if(it!=s.end()) s.erase(it), s.insert(make_pair(sf[a[u]], a[u]));
      printf("%d ", u);
    }
    printf("\n");
  }   
}