#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Note: There is a builtin function for it starting from C++17

// O(log(min(a, b)))
int gcd(int a, int b)
{
  while (b)
  {
    a %= b;
    swap(a, b);
  }
  return a;
}