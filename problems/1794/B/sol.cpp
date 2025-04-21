#include <bits/stdc++.h>
using namespace std;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--)
  {
    int prev, x;
    cin >> n >> prev;
    if(prev==1)
      prev = 2;
    cout << prev << " ";
    for (int i = 1; i < n; i++)
    {
      cin >> x;
      if(x==1)
        x = 2;
      if(x%prev==0)
        x++;
      cout << x << " ";
      prev = x;
    }
    cout << "\n";
  }
     
}