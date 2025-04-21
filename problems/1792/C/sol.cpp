#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int TC, n, x;
  cin >> TC;
  while (TC--)
  {
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
    {
      cin >> x;
      a[x] = i;
    }
    int i = n / 2 + 1, j = (n + 1) / 2;
    while (i > 1 && a[i - 1] < a[i] && a[j] < a[j + 1])
      i--, j++;
    cout << i - 1 << "\n";
  }
}