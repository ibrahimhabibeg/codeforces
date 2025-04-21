#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    int cnt = 0, a;
    for (int i = 1; i <= n; i++) scanf("%d", &a), cnt+=a==i;
    printf("%d\n", (cnt+1)/2);
  }   
}