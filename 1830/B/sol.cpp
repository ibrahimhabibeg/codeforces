#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 200005;

int mp[640][N];
ll a[N], b[N];

int main(){
  int TC;
  ll n;
  cin >> TC;
  while (TC--){
    scanf("%lld", &n);
    ll rt = sqrt(2*n);
    for (int i = 0; i <= rt; i++) for (int j = 0; j <= n; j++) mp[i][j] = 0;
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    for (int i = 0; i < n; i++) scanf("%lld", &b[i]);
    for (int i = 0; i < n; i++) if(a[i]<=rt) mp[a[i]][b[i]]++;
    ll res = 0, res_same = 0;
    for (int i = 2; i <= rt; i+=2) res_same -= mp[i][i*i/2];
    for (int i = 0; i<n; i++){
      if(a[i]<=rt && a[i]*a[i]-b[i]>=1 && a[i]*a[i]-b[i]<=n) res_same += mp[a[i]][a[i]*a[i]-b[i]];
      for (int s = 1; s <= min(rt, a[i]-1); s++) if(s*a[i]-b[i]>= 1 && s*a[i]-b[i]<=n) res+= mp[s][s*a[i]-b[i]];
    }
    printf("%lld\n", res + res_same/2);
  }   
}