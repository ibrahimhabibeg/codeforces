#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC;
  ll n, x;
  cin >> TC;
  while (TC--)
  {
    cin >> n >> x;
    if(n==x){
      cout << x << "\n";
      continue;
    }
    bool isYes = n>=x;
    int lstN, fstX = 100, i = 0;
    ll j = 1;
    while (j<=n)
    {
      bool xZero = (x & j) == 0, nZero = (n & j) == 0;
      if(!xZero && nZero) isYes = false;
      if(!xZero) fstX = min(fstX,i);
      if(xZero && !nZero) lstN = i;
      j = j << 1;
      i++;
    }
    if(isYes && fstX>lstN+1){
      ll k = 1;
      while (lstN--)
      {
        k = k << 1;
        k++;
      }
      cout << (n|k)+1 << "\n";
    }else cout << "-1\n";
  }   
}