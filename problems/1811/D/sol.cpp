#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int memo[50];

int fib(int n)
{
  if (!memo[n])
    memo[n] = fib(n - 1) + fib(n - 2);
  return memo[n];
}

bool isPossible(int n, int x, int y)
{
  if (n == 1)
    return true;
  int fs = fib(n - 1), fb = fib(n);
  if (y <= fb && y > fs)
    return false;
  if (y > fb)
    y -= fb;
  return isPossible(n - 1, y, x);
}

int main()
{
  int TC, n, x, y;
  for (int i = 2; i < 50; i++)
    memo[i] = 0;
  memo[0] = memo[1] = 1;
  cin >> TC;
  while (TC--)
  {
    cin >> n >> x >> y;
    if (isPossible(n, x, y))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}