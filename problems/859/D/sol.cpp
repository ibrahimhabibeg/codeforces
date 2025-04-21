
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int TC, n, q, val, l, r, k;
  cin >> TC;
  while (TC--)
  {
    cin >> n >> q;
    int arr[n + 1];
    arr[0] = 0;
    for (int i = 1; i < n + 1; i++)
    {
      cin >> val;
      arr[i] = (arr[i - 1] + val) % 2;
    }
    while (q--)
    {
      cin >> l >> r >> k;
      int sum = (((r - l + 1) % 2) * (k % 2) + (2 + arr[l - 1] + arr[n] - arr[r]) % 2)%2;
      if (sum==1)
        cout << "YES\n";
      else  
        cout << "NO\n";
    }
  }
}
