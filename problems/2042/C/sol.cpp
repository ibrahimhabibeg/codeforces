#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
  ll n, k, v = 0, res = 1, sum = 0;
  string s;
  scanf("%lld%lld", &n, &k);
  cin >> s;
  vector<ll> a;
  for (int i = n-1; i > 0; i--) v+= s[i]=='1'?1:-1, a.push_back(v);
  sort(a.begin(), a.end());
  int j = n-2;
  while (j>=0 && sum<k) sum+=a[j], j--, res++;
  if(sum<k) printf("-1\n");
  else printf("%lld\n", res);
}

int main(){
  int TC;
  scanf("%d", &TC);
  while(TC--){
    solve();
  }
}