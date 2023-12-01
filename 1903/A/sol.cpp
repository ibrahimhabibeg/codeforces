#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, k;
  cin >> TC;
  while (TC--)
  {
    scanf("%d%d", &n, &k);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    bool isSorted = true;
    for (int i = 1; i < n; i++) if(a[i]<a[i-1]) isSorted = false;
    if(k==1 && !isSorted) printf("NO\n");
    else printf("YES\n");
  }   
}