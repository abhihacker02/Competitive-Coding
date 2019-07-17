#include<bits/stdc++.h>
using namespace std;
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
char a[105][105];
int up(){
	
}
int main(){
	fast
	int t;
	cin>>t;
	while(t--){
		char ch='q';int l=0,u=0;
		string s;
		int n,m;
		cin>>n>>m;
		FOR0(n){
			for(int j=0;j<m;j++) cin>>a[i][j];
		}
		cin>>s;
		int ln=s.length();
		FOR0(ln){
			if(ch=='q'&&(s[i]=='L'||s[i]=='R'))
			{
				ch='l';
				if(s[i]=='L') l=1;
				else l=2;
			}
			else if(ch=='q'&&(s[i]=='U'||s[i]=='D')) {
			ch='u';
			if(s[i]=='U') u=1;
			else u=2;
			}
			else if(s[i]=='L') l=1;
			else if(s[i]=='R') l=2;
			else if(s[i]=='U') u=1;
			else if(s[i]=='D') u=2;
		}
		int ans[105][105]={},cu=0,cl=0;
		for(int i=0;i<m;i++){
					for(int j=0;j<n;j++){
						if(a[j][i]=='1') cu++;
					}
				}
					for(int i=0;i<n;i++){
						for(int j=0;j<m;j++){
							if(ans[i][j]==1) cl++;
						}
					}
		if(ch=='u'){
			if(u==1){
				for(int i=0;i<m;i++){
					int c=0;
					for(int j=0;j<n;j++){
						if(a[j][i]=='1') c++;
					}
					for(int j=0;j<c;j++){
						ans[j][i]=1;
					}
				}
				if(l==1){
					for(int i=0;i<n;i++){
						int c=0;
						for(int j=0;j<m;j++){
							if(ans[i][j]==1) c++;
						}
						for(int j=0;j<c;j++) ans[i][j]=1;
						for(int j=c;j<m;j++) ans[i][j]=0;
					}
				}
				else if(l==2){
					for(int i=0;i<n;i++){
						int c=0;
						for(int j=0;j<m;j++){
							if(ans[i][j]==1) c++;
						}
						for(int j=m-1;j>=m-c;j--) ans[i][j]=1;
						for(int j=m-c-1;j>=0;j--) ans[i][j]=0;
					}
				}
			}
			else if(u==2){
				for(int i=0;i<m;i++){
					int c=0;
					for(int j=0;j<n;j++){
						if(a[j][i]=='1') c++;
					}
					//cout<<c<<endl;
					for(int j=n-1;j>=n-c;j--){
						ans[j][i]=1;
					}
				}
				if(l==1){
					for(int i=0;i<n;i++){
						int c=0;
						for(int j=0;j<m;j++){
							if(ans[i][j]==1) c++;
						}
						for(int j=0;j<c;j++) ans[i][j]=1;
						for(int j=c;j<m;j++) ans[i][j]=0;
					}
				}
				else if(l==2){
					for(int i=0;i<n;i++){
						int c=0;
						for(int j=0;j<m;j++){
							if(ans[i][j]==1) c++;
						}
						for(int j=m-1;j>=m-c;j--) ans[i][j]=1;
						for(int j=m-c-1;j>=0;j--) ans[i][j]=0;
					}
				}
			}
		}
		else if(ch=='l'){
			int c=0;
			if(l==1){
				for(int i=0;i<n;i++){
					c=0;
					for(int j=0;j<m;j++){
						if(a[i][j]=='1') c++;
					}
				//	cout<<c<<endl;
					for(int j=0;j<c;j++) ans[i][j]=1;
				}
				/*for(int i=0;i<n;i++){
			for(int j=0;j<m;j++) cout<<ans[i][j];
			cout<<endl;
		}*/
				if(u==1){
					c=0;
					for(int i=0;i<m;i++){
						c=0;
						for(int j=0;j<n;j++) if(ans[j][i]==1) c++;
						for(int j=0;j<c;j++) ans[j][i]=1;
						for(int j=c;j<n;j++) ans[j][i]=0;
					}
				}
				else if(u==2){
					c=0;
					for(int i=0;i<m;i++){
						c=0;
						for(int j=0;j<n;j++) if(ans[j][i]==1) c++;
						for(int j=n-1;j>=n-c;j--) ans[j][i]=1;
						for(int j=n-c-1;j>=0;j--) ans[j][i]=0;
					}
				}
			}
			else if(l==2){
				c=0;
				for(int i=0;i<n;i++){
					c=0;
					for(int j=0;j<m;j++){
						if(a[i][j]=='1') c++;
					}
					//cout<<c<<endl;
					for(int j=m-1;j>=m-c;j--) ans[i][j]=1;
				}
				/*for(int i=0;i<n;i++){
			for(int j=0;j<m;j++) cout<<ans[i][j];
			cout<<endl;
		}*/
				if(u==1){
					c=0;
					for(int i=0;i<m;i++){
						c=0;
						for(int j=0;j<n;j++) if(ans[j][i]==1) c++;
						for(int j=0;j<c;j++) ans[j][i]=1;
						for(int j=c;j<n;j++) ans[j][i]=0;
					}
				/*	for(int i=0;i<n;i++){
			for(int j=0;j<m;j++) cout<<ans[i][j];
			cout<<endl;
		}*/
				}
				else if(u==2){
					c=0;
					for(int i=0;i<m;i++){
						c=0;
						for(int j=0;j<n;j++) if(ans[j][i]==1) c++;
						for(int j=n-1;j>=n-c;j--) ans[j][i]=1;
						for(int j=n-c-1;j>=0;j--) ans[j][i]=0;
					}
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++) cout<<ans[i][j];
			cout<<endl;
		}
	}
}
