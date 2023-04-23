#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, m;
  cin >> TC;
  while (TC--)
  {
    cin >> n >> m;
    int a[n], b[n];
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      b[i] = a[i];
    }
    sort(b, b+n);
    int sum = 0, w = 0;
    while (w<n && sum + b[w] <= m)
    {
      sum += b[w];
      w++;
    }
    if(w!=0 && w!=n && sum-b[w-1]+a[w]<=m) cout << n - w << "\n";
    else cout << n-w+1 << "\n";
  }   
}