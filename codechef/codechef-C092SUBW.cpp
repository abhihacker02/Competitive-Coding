#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
  int T;
  scanf("%d", &T);
  for (int test = 1; test <= T; ++test) {
    ll x;
    scanf("%lld", &x);
    ll sum = 0, res = x;
    for (int i = 1; i <= 100000; ++i) {
      sum += i;
      res = min(res, i + abs(sum - x));
      if(sum>x) break;
    }
    printf("%lld\n", res);
  }
  return 0;
}
