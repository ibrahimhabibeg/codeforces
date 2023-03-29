#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int A[60][60];
int main()
{
  int TC, m, n, x;
  cin >> TC;
  while (TC--)
  {
    cin >> n >> m;
    vector<int> A[m];
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        cin >> x;
        A[j].push_back(x);
      }
    }
    for (int i = 0; i < m; i++)
      sort(A[i].begin(), A[i].end());
    ll res = 0;
    for (int j = 0; j < m; j++)
      for (int i = 0; i < n; i++)
        res += A[j][i] * 1LL * i - A[j][i] * 1LL * (n - 1 - i);
    cout << res << "\n";
  }
}