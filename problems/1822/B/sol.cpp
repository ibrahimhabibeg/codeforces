#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--)
  {
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a,a+n);
    cout << max(a[n-1]*1LL*a[n-2], a[0]*1LL*a[1]) << "\n";
  }   
}