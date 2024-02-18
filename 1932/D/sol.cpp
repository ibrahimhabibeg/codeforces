#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, r, n;
  char s, t;
  cin >> TC;
  while (TC--){
    cin >> n >> t;
    vector<int> c[4];
    map<char, int> mp;
    char inv[4];
    if(t=='C') mp['D'] = 0, mp['H'] = 1, mp['S'] = 2, mp['C'] = 3, inv[0] = 'D', inv[1] = 'H', inv[2] = 'S', inv[3] = 'C';
    else if(t=='D') mp['C'] = 0, mp['H'] = 1, mp['S'] = 2, mp['D'] = 3, inv[0] = 'C', inv[1] = 'H', inv[2] = 'S', inv[3] = 'D';
    else if(t=='H') mp['D'] = 0, mp['C'] = 1, mp['S'] = 2, mp['H'] = 3, inv[0] = 'D', inv[1] = 'C', inv[2] = 'S', inv[3] = 'H';
    else  mp['D'] = 0, mp['H'] = 1, mp['C'] = 2, mp['S'] = 3, inv[0] = 'D', inv[1] = 'H', inv[2] = 'C', inv[3] = 'S';
    for (int i = 0; i < 2*n; i++) cin >> r >> s, c[mp[s]].push_back(r);
    for (int i = 0; i < 4; i++) sort(c[i].begin(), c[i].end());
    int odd = (c[0].size()%2) + (c[1].size()%2) + (c[2].size()%2);
    if(odd>c[3].size()){
      printf("IMPOSSIBLE\n");
    }else{
      for (int i = 0; i < 3; i++) for (int j = 0; j+1 < c[i].size(); j+=2) printf("%d%c %d%c\n", c[i][j], inv[i], c[i][j+1], inv[i]);
      int j = 0;
      for (int i = 0; i < 3; i++) if(c[i].size()%2) printf("%d%c %d%c\n", c[i][c[i].size()-1], inv[i], c[3][j], t), j++;
      while(j+1<c[3].size()){
        printf("%d%c %d%c\n", c[3][j], t, c[3][j+1], t);
        j+=2;
      }
    }
  }   
}