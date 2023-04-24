#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, s, r;
  cin >> TC;
  while (TC--)
  {
    cin >> n >> s >> r;
    cout << s - r << " ";
    int i = n-1, mx = s-r;
    while (i--)
    {
      cout << min(mx,r-i) << " ";
      r -= min(mx,r-i);
    }
    cout << "\n";
  }   
}