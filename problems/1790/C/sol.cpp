#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--)
  {
    cin >> n;
    int a[n][n-1];
    for (int i = 0; i < n; i++) for (int j = 0; j < n-1; j++) cin >> a[i][j];
    int r = a[0][0] == a[1][0] || a[0][0] == a[2][0] ? a[0][0] : a[1][0], i = 0;
    while (a[i][0]==r) i++;
    cout << r  << " ";
    for (int j = 0; j < n-1; j++) cout << a[i][j]  << " ";
    cout << "\n";
  }   
}