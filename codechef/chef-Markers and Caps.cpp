#include<bits/stdc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define SUM(v) accumulate(v.begin(),v.end(),lli(0))
#define rev(n,d) for(int i=n;i>=d;i--)
#define FOR0(n) for(int i=0;i<n;i++)
#define FOR(a,n) for(int i=a;i<n;i++)
#define FORQ(a,n) for(int i=a;i<=n;i++)
#define inf 1000000009
#define inff 0x3f3f3f3f
#define sz(a) int((a).size())
#define all(c) c.begin(), c.end()
#define ff first
#define ss second
#define endl "\n"
#define mod 1000000007
#define mem(ar,x) memset(ar,x,sizeof ar)
#define present(container, element) (container.find(element) != container.end())
#define max3(a,b,c) return (lli(a)>lli(b)?(lli(a)>lli(c)?a:c):(lli(b)>lli(c)?b:c))
#define max4(a,b,c,d) return (max3(a,b,c)>lli(d)?(max3(a,b,c)):d)
#define min3(a,b,c) return (lli(a)<lli(b)?(lli(a)<lli(c)?a:c):(lli(b)<lli(c)?b:c))
#define min4(a,b,c,d) return (max3(a,b,c)<lli(d)?(max3(a,b,c)):d)
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<int,pii>ppii;
typedef vector<int>vi;
typedef vector<vi>vvi;
typedef vector<pii>vpii;
const int N=100005;
int dr8[]={0,0,1,-1,1,1,-1,-1};
int dc8[]={1,-1,0,0,-1,1,-1,1};
int dr4[]={0,1,-1,0};
int dc4[]={1,0,0,-1};
int main(){
	fast
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		map<int,set<int> >m;
		int a[n],b[n];
		FOR0(n){
			cin>>a[i];
			b[i]=a[i];
			m[a[i]].insert(i);
		}
		priority_queue<pii >put;
		std::priority_queue<pii, std::vector<pii>, std::greater<pii> >acc;
		map<int,set<int> >::iterator it;
		for(it=m.begin();it!=m.end();it++){
			int sz=it->ss.size();
			int el=it->ff;
			put.push({sz,el});
			acc.push({sz,el});
		}
		while(!put.empty()){
			pii fr=put.top();
			put.pop();
			int sz=fr.ff;
			int el=fr.ss;
			int same=-1,cn=0;
			while(sz>0&&!acc.empty()){
				pii afr=acc.top();
				acc.pop();
				if(afr.ss==el){
					same=1;continue;
				}
				int npres=afr.ff;
				int pres=afr.ss;
				while(npres>0&&sz>0){
					npres--;sz--;
					int in=(*m[pres].begin());
					b[in]=el;
					m[pres].erase(m[pres].begin());
				}
				if(npres>0){
					acc.push({npres,pres});
				}
			}
			if(same==1){
				acc.push({m[el].size(),el});
			}
		}
		int np=0;
		FOR0(n){
			if(a[i]==b[i]){
				np=1;break;
			}
		}
		if(np==1){
			cout<<"No\n";
		}
		else{
			cout<<"Yes\n";
			FOR0(n) cout<<b[i]<<" ";cout<<endl;
		}
	}
}


