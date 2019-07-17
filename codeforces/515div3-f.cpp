#include<bits/stdc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define SUM(v) accumulate(v.begin(),v.end(),lli(0))
#define rev(n) for(int i=n;i>=0;i--)
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
struct sort_pred {
    bool operator()(const std::pair<int,int> &left, const std::pair<int,int> &right) {
        if(left.second!=right.second) return left.second>right.second;
        else{
        	return left.first<right.first;
		}
    }
};
int dis(int x1,int y1,int x2,int y2){
	return (abs(x1-x2)+abs(y1-y2));
}
int f=0;
int main(){
	fast
	int n,x,y;
	cin>>n;
	map<int,vpii>m;
	m[0].pb(mp(0,0));
	FOR0(n){
		cin>>x>>y;
		m[max(x,y)].pb(mp(x,y));
	}
	//cout<<endl;
	map<int,vpii>::iterator it;
	for(it=m.begin();it!=m.end();it++){
		sort((it->ss).begin(),(it->ss).end(),sort_pred());
	}
//	for(it=m.begin();it!=m.end();it++){
//		int t=(it->ss).size();
//		for(int i=0;i<t;i++){
//			cout<<"sort"<<(it->ff)<<" "<<(it->ss)[i].ff<<" "<<(it->ss)[i].ss<<endl;
//		}
//	}
	int p1=0,p2=0;
	lli ans=0;
	lli seg=0;
	pii v1,v2;
	lli m1=0,m2=0;
	for(it=m.begin();it!=m.end();it++){
		seg=0;
		int t=(it->ss).size();
		p1=(it->ss)[0].ff;p2=(it->ss)[0].ss;
		for(int i=1;i<t;i++){
		//	cout<<"el"<<(it->ss)[i].ff<<" "<<(it->ss)[i].ss<<endl;
			seg+=(dis((it->ss)[i].ff,(it->ss)[i].ss,p1,p2));
			p1=(it->ss)[i].ff;
			p2=(it->ss)[i].ss;
		}
		ans+=seg;
	//	cout<<seg<<" s"<<endl;
		if(it==m.begin()){
			v1=(it->ss)[0];v2=(it->ss)[t-1];
		}
		else
		{
			lli k1=min(m2+dis(v1.ff,v1.ss,(it->ss)[0].ff,(it->ss)[0].ss),m1+dis(v2.ff,v2.ss,(it->ss)[0].ff,(it->ss)[0].ss));
			lli k2=min(m1+dis(v2.ff,v2.ss,(it->ss)[t-1].ff,(it->ss)[t-1].ss),m2+dis(v1.ff,v1.ss,(it->ss)[t-1].ff,(it->ss)[t-1].ss));
			m1=k1;m2=k2;
			//cout<<"m1 "<<m1<<" m2 "<<m2<<endl;
			v1=(it->ss)[0];v2=(it->ss)[t-1];
		}
	}
	cout<<ans+(min(m1,m2));
}

