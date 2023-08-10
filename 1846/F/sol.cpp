#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    int a[n], tries = 2, t, s;
    vector<int> c(10);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]), c[a[i]]++;
    bool isFound = false;
    while (tries--) {
      printf("- 0\n");
      fflush(stdout);
      int n_a[n];
      vector<int> n_c(10);
      for (int i = 0; i < n; i++) scanf("%d", &n_a[i]), n_c[n_a[i]]++;
      for (int i = 1; i <= 9; i++) if(c[i]+1== n_c[i]) {
        t = i, s = n_c[i];
        for (int j = 0; j < n; j++) a[j] = n_a[j];
        isFound = true;
        break;
      }
      if(isFound) break;
    }
    printf("- %d ", n-s);
    for (int i = 0; i < n; i++) if(a[i]!=t) printf("%d ", i+1);
    printf("\n");
    fflush(stdout);
    for (int i = 0; i < s; i++) scanf("%d", &a[i]);
    tries = 3;
    isFound = false;
    while (tries-- && !isFound){
      for (int i = 0; i < s; i++) if(a[i]!=t){ 
        printf("! %d\n", i+1);
        fflush(stdout);
        isFound = true;
        break;
      }
      if(isFound) break;
      printf("- 0\n");
      fflush(stdout);
      for (int i = 0; i < s; i++) scanf("%d", &a[i]);
    }
  }   
}