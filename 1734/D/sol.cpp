#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, k;
  cin >> TC;
  while (TC--){
    scanf("%d%d", &n, &k);
    ll a[n+1], b[n+1], c[n+1], v[n+1];
    for (int i = 1; i <= n; i++) scanf("%lld", &v[i]);
    a[k] = b[k] = c[k] = 0;
    for (int i = k+1; i <= n; i++){
      if(a[i-1]>0) a[i] = v[i];
      else a[i] = a[i-1] + v[i];
      if(a[i-1]>0 || c[i-1]>0) c[i] = v[i];
      else c[i] = c[i-1] + v[i];
      if(a[i-1]>0) b[i] = v[i];
      else b[i] = min(b[i-1], c[i]);
    }
    for (int i = k-1; i >= 1; i--){
      if(a[i+1]>0) a[i] = v[i];
      else a[i] = a[i+1] + v[i];
      if(a[i+1]>0 || c[i+1]>0) c[i] = v[i];
      else c[i] = c[i+1] + v[i];
      if(a[i+1]>0) b[i] = v[i];
      else b[i] = min(b[i+1], c[i]);
    }
    vector<pair<ll, ll>> la, ra;
    ll s = v[k];
    for (int i = k+1; i <= n; i++) if(a[i]>0) ra.push_back(make_pair(a[i], b[i]));
    for (int i = k-1; i >= 1; i--) if(a[i]>0) la.push_back(make_pair(a[i], b[i]));
    la.push_back(make_pair(0, b[1])), ra.push_back(make_pair(0, b[n]));
    int l = 0, r = 0;
    while (l<la.size() && r<ra.size()){
      if(s>=-ra[r].second) s+=ra[r].first, r++;
      else if(s>=-la[l].second) s+=la[l].first, l++;
      else break;
    }
    if(l==la.size()||r==ra.size()) printf("YES\n");
    else printf("NO\n");
  }   
}