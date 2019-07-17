#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> flag(300001,0);
ll int fun(ll int i,vector<string> s1,vector<string> s2);
int main()
{
ll int N;
cin>>N;
char c;
vector<string> s1;
vector<string> s2;
map<char,int> m;
for(char x='a';x<='z';x++)
    m[x]=-1;
for(ll int i=0;i<N;i++)
{
cin>>c;
string s;
cin>>s;
if(c=='+')
{
s1.push_back(s);
}
if(c=='-')
{
s2.push_back(s);
}
}
sort(s1.begin(),s1.end());
for(int i=0;i<s1.size();i++)
{
    if(m[s1[i][0]]==-1)
        m[s1[i][0]]=i;
}
sort(s2.begin(),s2.end());
set<string> f;
ll int flag1=0;
ll int count1;
//for(map<char,int>::iterator it=m.begin();it!=m.end();++it)
    //cout<<it->second<<endl;
for(ll int i=0;i<s2.size();i++)
{
    ll int j;
    flag1=0;
    count1=INT_MIN;
    if(m[s2[i][0]]!=-1)
    {
 
        for(int j=m[s2[i][0]];j<s1.size();j++)
       {if(s2[i][0]==s1[j][0])
        {
            flag1=1;
            ll int k=0;
            ll int l=0;
            ll int count=0;
        while(k<s1[j].size()&&l<s2[i].size())
        {
            if(s2[i][l]==s1[j][k])
                ++count;
            else
                break;
                ++k;
                ++l;
        }
        if(count==s2[i].size())
        {
            cout<<-1<<endl;return 0;
        }
        count1=max(count1,count);
        }
else
    break;
       }
f.insert(s2[i].substr(0,count1+1));
    }
    else
    {
        f.insert(s2[i].substr(0,1));
    }
    //cout<<s2[i].substr(0,1)<<endl;
//cout<<s2[i]<<endl;
}
cout<<f.size()<<endl;
for(set<string>:: iterator it=f.begin();it!=f.end();++it)
    cout<<*it<<endl;
}
 
