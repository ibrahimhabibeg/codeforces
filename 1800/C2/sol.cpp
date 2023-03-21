#include <bits/stdc++.h>
using namespace std;

int main()
{
  int TC;
  cin >> TC;
  while (TC--)
  {
    int n, val;
    long long res = 0;
    cin >> n;
    priority_queue<int> pq;
    while (n--)
    {
      cin >> val;
      if (val == 0)
      {
        res += pq.empty() ? 0 : pq.top();
        if (!pq.empty())
          pq.pop();
      }
      else
        pq.push(val);
    }
    cout << res << "\n";
  }
}