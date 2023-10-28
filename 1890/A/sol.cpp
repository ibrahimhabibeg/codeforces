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
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a+n);
    bool isYes = true;
    for (int i = 1; i < n/2; i++) if(a[i]!=a[i-1]) isYes = false;
    for (int i = 1+(n+1)/2; i < n; i++) if(a[i]!=a[i-1]) isYes = false;
    if(n%2){
      isYes = isYes &&(a[n/2]==a[(n/2)+1]||a[n/2]==a[(n/2)-1]);
    }
    if(isYes) printf("Yes\n");
    else printf("No\n");
  }   
}