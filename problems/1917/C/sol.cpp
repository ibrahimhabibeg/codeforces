#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, k, d;
  cin >> TC;
  while (TC--)
  {
    scanf("%d%d%d", &n, &k, &d);
    int a[n], v[k], c = 0, res = 0;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]), c+=a[i]==i+1;
    for (int i = 0; i < k; i++) scanf("%d", &v[i]);
    for (int f = 1; f <= min(2*n+3, d); f++){
      res = max(res, c+((d-f)/2));
      for (int i = 0; i < v[(f-1)%k]; i++){
        c-=a[i]==i+1;
        a[i]++;
        c+=a[i]==i+1;
      }
    }
    printf("%d\n", res);
  }   
}