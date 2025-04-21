#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, m, k, x, y;
  cin >> TC;
  while (TC--){
    scanf("%d%d%d", &n, &m, &k);
    vector<int> l[n+1], r[n+1], cnt(n+1);
    vector<vector<int>> t(n+1, vector<int>(2,-1));
    for (int i = 0; i < m; i++) scanf("%d%d", &x, &y), l[x].push_back(i), r[y].push_back(i);
    set<int> s;
    for (int i = 1; i <= n; i++){
      for (int v:l[i]) s.insert(v);
      auto it = s.begin();
      if(it!=s.end()) t[i][0] = *it, it++;
      if(it!=s.end()) t[i][1] = *it;
      cnt[i] = s.size();
      for (int v:r[i]) s.erase(v);
    }
    map<pair<int,int>, int> mp;
    for (int i = 1; i <= n; i++) if(cnt[i]<=2) mp[make_pair(min(t[i][0],t[i][1]), max(t[i][0],t[i][1]))]++;
    int res = 0, mx1 = 0;
    for (auto it = mp.begin(); it!=mp.end(); it++){
      auto p = *it;
      int rn = p.second;
      if(p.first.second!=-1){
        rn += mp[make_pair(-1,-1)];
        if(p.first.first==-1){
          int newmx1 = max(mx1, p.second);
          rn+= mx1, mx1 = newmx1;
        }
        else rn += mp[make_pair(-1,p.first.first)]+mp[make_pair(-1,p.first.second)];
      } 
      res = max(res, rn);
    } 
    printf("%d\n", res);
  }   
}