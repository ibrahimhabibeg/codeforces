#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int TC, a, b;
  cin >> TC;
  while (TC--)
  {
    cin >> a >> b;
    if(b==1)
      cout << "1\n" << a << " " << b << "\n";
    else
      cout << "2\n1 " << b-1 << "\n" << a << " " << b << "\n";
  }
}

