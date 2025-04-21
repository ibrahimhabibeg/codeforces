#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll getClosest(ll val1, ll val2, ll t)
{
  if (t - val1 >= val2 - t)
    return val2;
  else
    return val1;
}

ll findClosest(ll arr[], ll n, ll target)
{
  if (target <= arr[0])
    return arr[0];
  if (target >= arr[n - 1])
    return arr[n - 1];
  ll i = 0, j = n, mid = 0;
  while (i < j)
  {
    mid = (i + j) / 2;
    if (arr[mid] == target)
      return arr[mid];
    if (target < arr[mid])
    {
      if (mid > 0 && target > arr[mid - 1])
        return getClosest(arr[mid - 1], arr[mid], target);
      j = mid;
    }
    else
    {
      if (mid < n - 1 && target < arr[mid + 1])
        return getClosest(arr[mid], arr[mid + 1], target);
      i = mid + 1;
    }
  }
  return arr[mid];
}

int main()
{
  ll TC, n, m, a, b, c;
  cin >> TC;
  while (TC--)
  {
    cin >> n >> m;
    ll arr[n];
    for (ll i = 0; i < n; i++)
      cin >> arr[i];
    sort(arr, arr + n);
    while (m--)
    {
      cin >> a >> b >> c;
      ll k = findClosest(arr, n, b);
      if (4 * a * c > (b - k) * (b - k))
        cout << "YES\n"
             << k << "\n";
      else
        cout << "NO\n";
    }
    cout << "\n";
  }
}