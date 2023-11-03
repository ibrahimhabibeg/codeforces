#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int n;
  scanf("%d", &n);
  int a[n], x = 0, c[n];
  vector<int> cc(21), oc(21);
  a[0] = 0;
  for (int i = 1; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) x^=a[i], c[i]=x;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j<21; j++)
    {
      oc[j]+=(i>>j)%2;
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j<21; j++)
    {
      cc[j]+=(c[i]>>j)%2;
    }
  }
  int res = 0;
  for (int j = 20; j>=0; j--){
    res += (cc[j]==oc[j]?0:1)<<j;
  }
  a[0] = res, x = 0;
  for (int i = 0; i < n; i++) x^=a[i], printf("%d ", x);
}