#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, a;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    map<ll, int> mp;
    ll s = 0;
    int r = 0, mx = 1;
    bool zeroFound = false;
    for (int i = 0; i < n; i++){
      scanf("%d", &a);
      if(a==0){
        if(zeroFound) r+=mx;
        mp.clear(), s = 0, mx = 1, zeroFound = true;
      } 
      s+=a, mp[s]++, mx=max(mx, mp[s]);
      if(!zeroFound) r+=s==0;
    }
    if(zeroFound) r+=mx;
    printf("%d\n", r);
  }   
}