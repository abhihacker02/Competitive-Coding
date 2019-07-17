#include <cstdio>
 
int main() {
  long long f[41] = {1, 1, 5};
  for (int i = 3; i <= 40; i++) {
    f[i] = f[i - 1] + 4 * f[i - 2] + 2 * f[i - 3];
  }
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    printf("%lld\n", f[n]);
  }
  return 0;
}
