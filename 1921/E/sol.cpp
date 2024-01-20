#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, h, w, xa, xb, ya, yb;
  cin >> TC;
  while (TC--){
    scanf("%d%d%d%d%d%d", &h, &w, &xa, &ya, &xb, &yb);
    if(xb-xa<1){
      printf("Draw\n");
      continue;
    }
    int t = (xb-xa)/2, fa, fb;
    if((xb-xa)%2){
      if(ya<yb) ya++;
      if(ya>yb) ya--;
      if(ya<yb) fa = min(w, ya+t), fb = min(w, yb+t);
      else if(ya>yb) fa = max(1, ya-t), fb = max(1, yb-t);
      else fa = fb = 1;
    }else{
      if(ya>yb) fa = min(w, ya+t), fb = min(w, yb+t);
      else if(ya<yb) fa = max(1, ya-t), fb = max(1, yb-t);
      else fa = fb = 1;
    }
    if(fa==fb){
      if((xb-xa)%2) printf("Alice\n");
      else printf("Bob\n");
    }else printf("Draw\n");
  }   
}