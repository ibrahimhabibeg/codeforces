#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--)
  {
    scanf("%d", &n);
    int b[n];
    for(int i = 0; i<n; i++) scanf("%d", &b[i]);
    int l[n], r[n];
    l[0] = b[0], r[n-1] = b[n-1]-(n-1);
    for (int i = 1; i < n; i++)
      l[i] = max(l[i-1], b[i]+i);
    for (int i = n-2; i>=0; i--)
      r[i] = max(r[i+1], b[i]-i);
    int res = 0;
    for(int i =1; i<n-1; i++)
      res = max(res, b[i] + l[i-1] + r[i+1]);
    printf("%d\n", res);
  }   
}