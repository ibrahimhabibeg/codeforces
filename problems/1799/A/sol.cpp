#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, m, p;
  cin >> TC;
  while (TC--)
  {
    cin >> n >> m;
    bool seen[m];
    for (int i = 0; i < m; i++)
      seen[i] = false;
    int ans[n], added = 0;
    for (int i = 0; i < n; i++)
      ans[i] = -1;
    for (int i = 0; i < m; i++)
    {
      cin >> p;
      if(!seen[p-n-1] && added<n)
        ans[n-(++added)] = i+1, seen[p-n-1] = true;
    }
    for (int i = 0; i < n; i++)
      cout << ans[i] << " ";
    cout << "\n";
  }   
}