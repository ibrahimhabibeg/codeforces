#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> memo(1000005);

int getRow(int n){
  int l = 1, r = 2023;
  while (l<r)
  {
    int m = (l+r)/2;
    if(m*(m+1)/2>=n) r = m;
    else l = m+1;
  }
  return l;
}

ll dp(int n){
  ll &res = memo[n];
  if(res==0){
    res = n*1LL*n;
    int r = getRow(n);
    if(n!=(r*(r-1)/2)+1) res+=dp(n-r);
    if(n!=r*(r+1)/2) res+=dp(n-r+1);
    if(n!=r*(r+1)/2 && n!=(r*(r-1)/2)+1) res-=dp(n-2*r+2);
  } 
  return res;
}

int main(){
  int TC, n;
  cin >> TC;
  while (TC--)
  {
    scanf("%d", &n);
    printf("%lld\n", dp(n));
  }   
}