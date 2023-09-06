#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, k;
  cin >> TC;
  while (TC--){
    scanf("%d%d", &n, &k);
    int a[n+1];
    vector<bool> b(n+1);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]), b[a[i]] = true;
    for (int i = 0; i <= n; i++) if(!b[i]){
      a[n] = i;
      break; 
    }
    k = k%(n+1);
    for (int i = 0; i < n; i++) printf("%d ", a[(i+n+1-k)%(n+1)]);
    printf("\n");
  }   
}