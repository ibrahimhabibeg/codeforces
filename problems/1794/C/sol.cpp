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
    int a[n], j = 0;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      while (a[j] < i - j + 1)
        j++;
      cout << i - j + 1 << " ";
    }
    cout << "\n";
  }
}