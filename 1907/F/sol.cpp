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
    for (int i = 0; i <n; i++) scanf("%d", &a[i]);
    bool isAllEqual = true;
    for (int i = 1; i < n; i++) if(a[i]!=a[0]) isAllEqual = false;
    if(isAllEqual){
      printf("0\n");
      continue;
    }
    int g1 = -1, c1 = 0, g2 = -1, c2 = 0, res = n + 15;
    for (int i = 0; i < n; i++) if(a[i]>a[(i+1)%n]) c1++, g1 = (i+1)%n;
    for (int i = 0; i < n; i++) if(a[i]<a[(i+1)%n]) c2++, g2 = i;
    if(c1==1) res = min(res, (n-g1)%n);
    if(c1==1) res = min(res, g1+2);
    if(c2==1 && g2!=0) res = min(res, (n-g2)%n);
    if(c2==1) res = min(res, g2+2);
    if(res==n+15) printf("-1\n");
    else printf("%d\n", res);
  }   
}