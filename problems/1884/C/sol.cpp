#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, m;
  cin >> TC;
  while (TC--){
    scanf("%d%d", &n, &m);
    int l[n], r[n];
    for (int i = 0; i < n; i++) scanf("%d%d", &l[i], &r[i]);
    set<int> seen;
    vector<int> la, ra, e;
    for (int i = 0; i < n; i++){
      if(l[i]==1)ra.push_back(r[i]);
      if(r[i]==m)la.push_back(l[i]);
      if(seen.find(l[i])==seen.end())e.push_back(l[i]), seen.insert(l[i]);
      if(seen.find(r[i])==seen.end())e.push_back(r[i]), seen.insert(r[i]);
    }
    sort(e.begin(), e.end());
    sort(la.begin(), la.end());
    sort(ra.begin(), ra.end());
    int ce = e.size();
    vector<int> c(ce+1);
    for (int i = 0; i < n; i++){
      int b = lower_bound(e.begin(), e.end(), l[i]) - e.begin(), f = lower_bound(e.begin(), e.end(), r[i]) - e.begin();
      c[b]++, c[f+1]--;
    }
    for (int i = 1; i <= ce; i++) c[i]+=c[i-1];
    int res = 0;
    for (int i = 0; i < ce; i++){
      int ls = upper_bound(la.begin(), la.end(), e[i]) - la.begin(), rs = ra.size() - (lower_bound(ra.begin(),ra.end(),e[i])-ra.begin());
      res = max(res, max(c[i]-ls,c[i]-rs));
    }
    printf("%d\n", res);
  }   
}