#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int TC, n;
  cin >> TC;
  while (TC--)
  {
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < n; i++)
      cin >> b[i];
    bool isYes = true;
    for (int i = 0; i < n - 1; i++)
    {
      if (max(a[i], b[i]) > max(a[n - 1], b[n - 1]) || min(a[i], b[i]) > min(a[n - 1], b[n - 1]))
      {
        isYes = false;
        break;
      }
    }
    if(isYes) cout << "Yes\n";
    else cout << "No\n";
  }
}