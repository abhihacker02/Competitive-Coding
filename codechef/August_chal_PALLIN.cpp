#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	char res[t];
	for(int i=0;i<t;i++)
	{
		string s1,s2;
		cin>>s1;
		cin>>s2;
		int p=0,f=0;
		int c1[27]={0};
		int c2[27]={0};
		for(int j=0;j<s1.length();j++)
		{
			c1[s1[j]-97]=c1[s1[j]-97]+1;
		}
		for(int j=0;j<s2.length();j++)
		c2[s2[j]-97]=c2[s2[j]-97]+1;
		for(int j=0;j<26;j++)
		{
			if(c2[j]==0 && c1[j]>1) {f=1;break;}
			if(c2[j]>0&&c1[j]==0){p=1;break;
			}
		}
		for(int j=0;j<26;j++)
		{
			if(p==0 &&c2[j]==0&&c1[j]>0){f=1;break;
			}
		}
		if(f==1) res[i]='A';
		else res[i]='B';
	}
	for(int i=0;i<t;i++) cout<<res[i]<<endl;
}
