#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC;
  string p = "31415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095";
  string s;
  cin >> TC;
  while (TC--)
  {
    cin >>  s;
    int i = 0;
    while (i<(int)s.size() && s[i]==p[i]) i++;
    cout << i << "\n";
  }   
}