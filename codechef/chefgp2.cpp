#include<bits/stdc++.h>
#include<string>
#include<vector>
#include<stack>
#define mod 10e9+7
typedef long long int lli;
#define pb push_back
#define mp make_pair
using namespace std;
vector<char>st;
int maxx(int a,int b){
int m;
m=a;
if(b>a) m=b;
return m;}
int main(){
    int t,x,y;
    string s;
    cin>>t;
    for(int p=0;p<t;p++){
        cin>>s;
        cin>>x>>y;
        int ca=0,cb=0;
        st.clear();
        for(int i=0;i<s.length();i++)
        {
        	if(s[i]=='a') ca++;
        	else cb++;
		}
		int mn,ka=0,kb=0,ma,mb,ta,tb;
		mb=(ca-1)/x;
		ma=(cb-1)/y;
		if(ca==0) mb=0;
		if(cb==0) ma=0;
		if(ma<=0) ta=x;
		else ta=min(ca/ma,x);
		if(mb<=0) tb=y;
		else tb=min(cb/mb,y);
		if(tb==0) tb=1; if(ta==0) ta=1;
		if(ma<=mb){
			if(ca>0){
			st.pb('a');ca--;ka++;}
			while(ca>0){
				ca--;
				if(ka%ta==0){
					if(cb>0){
						kb=1;
						st.pb('b');cb--;
						while(cb>0){
							if(kb%tb==0){
								break;
							}
							else{
								st.pb('b');
							}
							cb--;kb++;
						}
						st.pb('a');ka++;
					}
					else{
						st.pb('*');st.pb('a');ka++;
					}
				}
				else{
				    st.pb('a');ka++;
				}
			}
			if(cb>0){
				st.pb('b');cb--;kb=1;
			}
			while(cb>0){
				cb--;
				if(kb%tb==0){
					st.pb('*');st.pb('b');
				}
				else st.pb('b');
				kb++;
			}
		}
		else{
			if(cb>0){
			st.pb('b');cb--;kb++;}
			while(cb>0){
				cb--;
				if(kb%tb==0){
					if(ca>0){
						ka=1;
						st.pb('a');ca--;
						while(ca>0){
							if(ka%ta==0){
								break;
							}
							else{
								st.pb('a');
							}
							ca--;ka++;
						}
						st.pb('b');kb++;
					}
					else{
						st.pb('*');st.pb('b');kb++;
					}
				}
				else{
				    st.pb('b');kb++;
				}
			}
			if(ca>0){
				st.pb('a');ca--;ka=1;
			}
			while(ca>0){
				ca--;
				if(ka%ta==0){
					st.pb('*');st.pb('a');
				}
				else st.pb('a');
				ka++;
			}
	}
		for(int i=0;i<st.size();i++)
		cout<<st[i];
		cout<<endl;
    }
}
