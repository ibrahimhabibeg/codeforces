#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
  int n;
  scanf("%d", &n);
  int fl[n], fr[n];
  vector<vector<int>> a(n, vector<int>(3));
  for (int i = 0; i < n; i++) scanf("%d", &a[i][0]), scanf("%d", &a[i][1]), a[i][2] = i;
  sort(a.begin(), a.end(), [](vector<int> &x, vector<int> &y){
    if(x[0] == y[0]) return x[1] > y[1];
    return x[0] < y[0];
  });
  set<int> s;
  for (int i = 0; i < n; i++) {
    int l = a[i][0], r = a[i][1]; 
    auto it = s.lower_bound(r);
    if(it==s.end()) fr[a[i][2]] = r;
    else fr[a[i][2]] = *it;
    if(i<n-1 && a[i+1][0] == l && a[i+1][1] == r) fr[a[i][2]] = r;
    s.insert(r); 
  }
  sort(a.begin(), a.end(), [](vector<int> &x, vector<int> &y){
    if(x[1] == y[1]) return x[0] < y[0];
    return x[1] > y[1];
  });
  s.clear();
  for (int i = 0; i < n; i++) {
    int l = a[i][0], r = a[i][1]; 
    auto it = s.lower_bound(-l);
    if(it==s.end()) fl[a[i][2]] = l;
    else fl[a[i][2]] = -(*it);
    if(i<n-1 && a[i+1][0] == l && a[i+1][1] == r) fl[a[i][2]] = l;
    s.insert(-l); 
  }
  sort(a.begin(), a.end(), [](vector<int> &x, vector<int> &y){
    return x[2] < y[2];
  });
  for (int i = 0; i < n; i++) printf("%d\n", a[i][0]-a[i][1]+fr[i]-fl[i]);
}

int main(){
  int TC;
  scanf("%d", &TC);
  while(TC--){
    solve();
  }
}