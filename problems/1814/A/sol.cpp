#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll TC, n, k;
  cin >> TC;
  while (TC--)
  {
    cin >> n >> k;
    if(n%2==1 && k%2==0)
      cout << "NO\n";
    else
      cout << "YES\n";
  }   
}