#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, t;
  cin >> TC;
  while (TC--)
  {
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = i%2==1? i/2+1: n - i/2; 
    printf("+ %d\n", n);
    fflush(stdout);
    scanf("%d", &t);
    printf("+ %d\n", n+1);
    fflush(stdout);
    scanf("%d", &t);
    int max_d = 0, f = -1, d;
    for (int i = 2; i <= n; i++){
      printf("? 1 %d\n", i);
      fflush(stdout);
      scanf("%d", &d);
      if(d>max_d) max_d = d, f = i;
    }
    vector<int> r1(n), r2(n);
    r1[f-1] = a[0], r2[f-1] = a[n-1];
    for (int i = 1; i <= n; i++) if(i!=f) {
      printf("? %d %d\n", f, i);
      fflush(stdout);
      scanf("%d", &d);
      r1[i-1] = a[d], r2[i-1] = a[n-1-d];
    }
    printf("! ");
    for (int x: r1) printf("%d ", x);
    for (int x: r2) printf("%d ", x);
    printf("\n");
    fflush(stdout);
    scanf("%d", &t);
  }   
}