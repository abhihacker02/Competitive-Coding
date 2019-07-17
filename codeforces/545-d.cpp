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
const int N=500005;
int dr8[]={0,0,1,-1,1,1,-1,-1};
int dc8[]={1,-1,0,0,-1,1,-1,1};
int dr4[]={0,1,-1,0};
int dc4[]={1,0,0,-1};
int Z[N];
void Zarr(string str) 
{ 
//cout<<"fhkj";
    int n = str.length(); 
    int L, R, k; 
    L = R = 0; 
    for (int i = 1; i < n; ++i) 
    {
        if (i > R) 
        { 
            L = R = i; 
            while (R<n && str[R-L] == str[R]) 
                R++; 
            Z[i] = R-L; 
            R--; 
        } 
        else
        { 
            k = i-L; 
            if (Z[k] < R-i+1) 
                Z[i] = Z[k]; 
            else
            { 
                L = i; 
                while (R<n && str[R-L] == str[R]) 
                    R++; 
                Z[i] = R-L; 
                R--; 
            } 
        } 
    } 
} 
int main(){
	fast
	string s,t;
	cin>>s;
	cin>>t;
	if(t.length()>s.length()){
		cout<<s;
	}
	else{
		mem(Z,0);
		Zarr(t);
		int lng=0;
//		mem(Z,0);
//		for(int i=0;i<=t.length();i++) cout<<Z[i]<<" ";cout<<endl;
		int ls=s.length();
		int lt=t.length();
		for(int i=1;i<lt;i++){
			if((Z[i]+i)==lt) lng=max(lng,Z[i]);
		}
	//	cout<<lng<<endl;
		string add=t.substr(lng,lt-lng);
		int addo=0,addz=0,ind=0;
		for(int i=lng;i<lt;i++){
			add[ind]=t[i];
//			add=add+t[i];
			ind++;
			if(t[i]=='1') addo++;
			else addz++;
		}
		int ons=0,zs=0,ont=0,zt=0;
		FOR0(ls) {
			if(s[i]=='1') ons++;
			else zs++;
		}
		FOR0(lt) {
			if(t[i]=='1') ont++;
			else zt++;
		}
		if(zt>zs||ont>ons){
			cout<<s;
		}
		else{
			string ans=s;
			int in=0,f=0;
			while(ons>=ont&&zs>=zt){
				f=1;
				for(int i=0;i<lt;i++){
					ans[in]=t[i];
					in++;
				}
				ons-=ont;
				zs-=zt;
				if(f==1) break;
			}
			while(ons>=addo&&zs>=addz){
				for(int i=0;i<add.length();i++){
					ans[in]=add[i];
					in++;
				}
				ons-=addo;
				zs-=addz;
			}
			while(ons--){
				ans[in]='1';
				in++;
			}
			while(zs--){
				ans[in]='0';
				in++;
				
			}
			cout<<ans;
		}
	}
}


