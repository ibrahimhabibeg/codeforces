#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
  int n;
  cin >> n;
  map<ll, ll> mp1, mp2;
  ll x, y;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    mp1[x]++;
    mp2[x+y]++;
  }
  ll s, t;
  for(auto p : mp1) if(p.second %2) {
    s = p.first;
    break;
  }
  for(auto p : mp2) if(p.second %2) {
    t = p.first - s;
    break;
  }
  cout << s << " " << t << endl;
}

int main(){
  int TC;
  scanf("%d", &TC);
  while(TC--){
    solve();
  }
}