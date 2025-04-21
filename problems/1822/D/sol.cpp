#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--)
  {
    cin >> n;
    if(n!=1&&n%2==1) cout << "-1\n";
    else{
      cout << n;
      for (int i = 1; i < n; i++) cout << " " << (i%2==0?i:n-i);
      cout << "\n";
    }
  }   
}