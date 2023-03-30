#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int f(int n)
{
  int res = 0;
  while (n > 0)
  {
    res++;
    n /= 2;
  }
  return res;
}

int main()
{
  int TC, n, m;
  cin >> TC;
  while (TC--)
  {
    cin >> n >> m;
    cout << n * m << "\n";
    int a = f(m - 1);
    for (int i = 0; i < n; i++)
    {
      ll b = i << a;
      for (ll j = 0; j < m; j++)
        cout << b + j << " ";
      cout << "\n";
    }
  }
}