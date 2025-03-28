#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isPerfectSquare(ll x) {
  ll rt = sqrt(x);
  return rt*rt == x;
}

void solve(){
  int n;
  scanf("%d", &n);
  vector<int> res;
  ll s = 0;
  for (int i = 1; i <= n; i++) {
    if(isPerfectSquare(s+i)) {
      if(i==n) {
        printf("-1\n");
        return;
      }
      res.push_back(i+1);
      res.push_back(i);
      s+=i+i+1;
      i++;
    } else {
      res.push_back(i);
      s+=i;
    }
  }
  for (auto v: res) printf("%d ", v);
  printf("\n");
}

int main(){
  int TC;
  scanf("%d", &TC);
  while(TC--){
    solve();
  }
}