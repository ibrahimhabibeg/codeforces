#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, a;
  cin >> TC;
  while (TC--)
  {
    scanf("%d", &n);
    int i1, i2, in;
    for (int i = 1; i <= n; i++)
    {
      scanf("%d", &a);
      if(a==1) i1 = i;
      if(a==2) i2 = i;
      if(a==n) in = i;
    }
    if(in>max(i1,i2)) printf("%d %d\n", in, max(i1,i2));
    else if(in<min(i1,i2)) printf("%d %d\n", in, min(i1,i2));
    else printf("1 1\n");
  }   
}