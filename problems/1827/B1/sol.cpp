#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--)
  {
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i<n; i++) scanf("%d", &a[i]);
    ll res = 0;
    for (int i = 0; i < n; i++) for (int j = i; j < n; j++) res += j-i; 
    for (int i = 0; i < n; i++){
      int y = i, k = i;
      while (y<n && a[y]>=a[i]) y++;
      while (k>=0 && a[k]>=a[i]) k--;
      int x = k;
      while (x>=0 && a[x]<=a[i]) x--;
      res -= (k-x)*(y-i);
    }
    printf("%lld\n", res);
  }   
}