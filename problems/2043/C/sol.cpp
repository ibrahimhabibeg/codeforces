#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
int a[N];

int getMax(int l, int r) {
  int sum = 0, res = 0;
  for (int i = l; i < r; i++){
    if(sum > 0) sum+=a[i];
    else sum = a[i];
    res = max(res, sum);
  }
  return res;
}

int getMin(int l, int r) {
  int sum = 0, res = 0;
  for (int i = l; i < r; i++){
    if(sum < 0) sum+=a[i];
    else sum = a[i];
    res = min(res, sum);
  }
  return res;
}

void solve(){
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  int x = -1;
  for (int i = 0; i < n; i++) if(a[i]!=-1 && a[i]!=1) x = i;
  if(x==-1){
    int mx = getMax(0, n), mn = getMin(0, n);
    printf("%d\n", mx-mn+1);
    for (int i = mn; i <= mx; i++) printf("%d ", i);
    printf("\n");
    return;
  }
  int mx = max(getMax(0, x), getMax(x+1, n)), mn = min(getMin(0, x), getMin(x+1, n));
  int rMAX = 0, rMIN = 0, lMAX = 0, lMIN = 0, sum = 0;
  for (int i = x+1; i < n; i++) {
    sum+=a[i];
    rMAX = max(rMAX, sum);
    rMIN = min(rMIN, sum);
  }
  sum = 0;
  for (int i = x-1; i >= 0; i--) {
    sum+=a[i];
    lMAX = max(lMAX, sum);
    lMIN = min(lMIN, sum);
  }
  int mn2 = a[x] + rMIN + lMIN, mx2 = a[x] + rMAX + lMAX;
  if((mn2>=mn && mn2<=mx) ||  (mn>=mn2 && mn<=mx2)) {
    mn = min(mn, mn2), mx = max(mx, mx2);
    printf("%d\n", mx-mn+1);
    for (int i = mn; i <= mx; i++) printf("%d ", i);
    printf("\n");
    return;
  }
  printf("%d\n", mx-mn+1+mx2-mn2+1);
  if(mx<mn2){
    for (int i = mn; i <= mx; i++) printf("%d ", i);
    for (int i = mn2; i <= mx2; i++) printf("%d ", i);
  } else {
    for (int i = mn2; i <= mx2; i++) printf("%d ", i);
    for (int i = mn; i <= mx; i++) printf("%d ", i);
  } 
  printf("\n");
}

int main(){
  int TC;
  scanf("%d", &TC);
  while(TC--){
    solve();
  }
}