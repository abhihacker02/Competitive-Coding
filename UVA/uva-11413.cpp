#include <bits/stdc++.h>
using namespace std;
int n, m, V[1000];
int check(int c) {
	int cap = 0, cnt = 0;
	int i = 0;
	for(i = 0; i < n; i++) {
	if(V[i] > c)
	return 1000000;
	if(cap < V[i])
	cap = c, cnt++;
	cap -= V[i];
	}
	return cnt;
	}
int main() {
	int i,sum=0;
	while(scanf("%d %d", &n, &m) == 2) {
	for(i = 0; i < n; i++){
	scanf("%d", &V[i]);sum+=V[i];}
	int l = 1,r=sum;
	while(l < r) {
	int mid = (l + r)>> 1;
	int cnt = check(mid);
	if(cnt > m)
	l = mid+1;
	else
	r = mid;
	}
		printf("%d\n", l);
	}
	return 0;
}
