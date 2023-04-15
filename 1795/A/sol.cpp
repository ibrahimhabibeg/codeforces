#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, m, n;
  string a, b;
  cin >> TC;
  while (TC--)
  {
    cin >> m >> n >> a >> b;
    int c = 0;
    for (int i = 1; i < m; i++)
      c += a[i]==a[i-1] ;
    for (int i = 1; i < n; i++)
      c += b[i]==b[i-1] ;
    if(c == 0||(c==1 && a[m-1]!=b[n-1]))
      cout << "YES\n";
    else 
      cout << "NO\n";
  }   
}