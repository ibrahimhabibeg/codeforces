#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
  int TC, a, b;
  cin >> TC;
  while (TC--)
  {
    scanf("%d%d", &a, &b);
    if((a+b)%2) printf("Alice\n");
    else printf("Bob\n");
  }   
}