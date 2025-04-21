#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC;
  cin >> TC;
  while (TC--){
    int a, b, c, d, x, y;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if(c>=2*a && d>=2*b){
      printf("%d %d\n", 2*a, 2*b);
      continue;
    }
    vector<int> Fa, Fb;
    for (int i = 1; i * i <= a; i++) if(a%i==0){
      Fa.push_back(i);
      if(i!=a/i)Fa.push_back(a/i);
    }
    for (int i = 1; i * i <= b; i++) if(b%i==0){
      Fb.push_back(i);
      if(i!=b/i)Fb.push_back(b/i);
    }
    bool isFound = false;
    sort(Fa.begin(), Fa.end());
    sort(Fb.begin(), Fb.end());
    for(int fa: Fa){
      if(isFound) break;
      int i = upper_bound(Fb.begin(), Fb.end(), fa) - Fb.begin();
      while (i<Fb.size() && Fb[i]<=((c+a-1)/a)*fa){
        int fb = Fb[i];
        x = (a/fa)*fb, y = fa*(b/fb)*(1 + (fb/fa));
        if(x<= c && y<=d) {
          isFound = true;
          break;
        }
        i++;
      }
    }
    for(int fb: Fb){
      if(isFound) break;
      int i = upper_bound(Fa.begin(), Fa.end(), fb) - Fa.begin();
      while (i<Fa.size() && Fa[i]<=((d+b-1)/b)*fb){
        int fa = Fa[i];
        y = (b/fb)*fa, x = fb*(a/fa)*(1 + (fa/fb));
        if(x<= c && y<=d) {
          isFound = true;
          break;
        }
        i++;
      }
    }
    if(!isFound) x = -1, y = -1;
    printf("%d %d\n", x, y);
  }   
}