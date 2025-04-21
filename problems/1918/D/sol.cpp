#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;
int a[N], n;

ll f(ll s){
  ll dp[n+1], cs = 0;
  dp[0] = 0;
  int j = 0;
  multiset<ll> st;
  st.insert(0);
  for (int i = 1; i <= n; i++){
    cs+=a[i];
    st.insert(dp[i-1]+a[i]);
    while(cs>s){
      if(j==0) st.erase(st.find(0));
      else st.erase(st.find(dp[j-1]+a[j]));
      j++;
      cs-=a[j];
    }
    dp[i] = *(st.begin());
  }
  return dp[n];
}

int main(){
  int TC;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    ll ogl = 0, ogr = 0, l, r; 
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), ogr+=a[i];
    a[0] = 0;
    l = ogl, r = ogr;
    while(l<r){
      ll s = (l+r+1)/2;
      if(s>f(s)) r = s-1;
      else l = s;
    }
    ll res = f(l);
    l = ogl, r = ogr;
    while(l<r){
      ll s = (l+r)/2;
      if(s<=f(s)) l = s+1;
      else r=s;
    }
    res = min(res, l);
    printf("%lld\n", res);
  }   
}