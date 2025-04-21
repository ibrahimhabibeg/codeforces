#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
  int n, k;
  scanf("%d%d", &n, &k);
  int a[n];
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  map<int, int> m;
  for (int i = 0; i < n; i++) m[a[i]]++;
  int res = m.size();
  vector<int> v;
  for (auto p: m) v.push_back(p.second);
  sort(v.begin(), v.end());
  for(int s: v) {
    if(s<=k) {
      res--;
      k-=s;
    }
    else break;
  }
  printf("%d\n", max(res, 1));
}

int main(){
  int TC;
  scanf("%d", &TC);
  while(TC--){
    solve();
  }
}