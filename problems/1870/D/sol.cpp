#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, k;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    int c[n], m[n], r[n];
    for (int i = 0; i < n; i++) scanf("%d", &c[i]);
    scanf("%d", &k);
    m[n-1] = c[n-1];
    for (int i = n-2; i >= 0; i--) m[i] = min(m[i+1], c[i]);
    for (int i = 0; i < n-1; i++){
      if(m[i+1]<=c[i]) r[i] = 0;
      else r[i] = max(0, k/c[i] - (k%c[i])/(m[i+1]-c[i]));
      k-= r[i]*c[i];
    }
    r[n-1] = k/c[n-1];
    for (int i = n-2; i >= 0; i--) r[i] += r[i+1];
    for (int i = 0; i < n; i++) printf("%d ", r[i]);
    printf("\n");
  }   
}