int mod=1000000007;
long long int pr[110005];
void comp(){
    long long int num;
    for(long long int j=1;j<110005;j++)
    {
        num=j;
        pr[j]=1LL;
    long long int square_root = (long long int) sqrt(num) + 1;
    for (long long int i = 1; i*i <= num; i++) { 
    if ((num % i) == 0&&(i*i)!=num)
        {
            pr[num]=(1LL*pr[num]*i)%mod;
            pr[num]=(1LL*pr[num]*(num/i))%mod;
        }
    if (num % i == 0&&i*i==num)
        pr[num]=(1LL*pr[num]*i)%mod;
}
}
}
int f=0;
vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    //vector<int>pr(100005);
    if(f==0){comp();f=1;}
    //sort(A.begin(),A.end());
    int sa=A.size();
    int sb=B.size();
    vector<pair<int,int> > q;
    for(int i=0;i<sb;i++) q.push_back(make_pair(B[i],i));
    sort(q.begin(),q.end());
    vector<int>x(sb);
    vector<pair<int,int> >v;
    int mx=0,pos=-1;
    int ml[sa],mr[sa];
    stack<int>s;
    for(int i=0;i<sa;i++){
       while(!s.empty()&&A[s.top()]<A[i]){
           s.pop();
       } 
       if(s.empty()) ml[i]=-1;
       else ml[i]=s.top();
       s.push(i);
    }
    while(!s.empty())
    s.pop();
    for(int i=sa-1;i>=0;i--){
       while(!s.empty()&&A[s.top()]<=A[i]){
           s.pop();
       } 
       if(s.empty()) mr[i]=sa;
       else mr[i]=s.top();
       s.push(i);
    }
    for(int i=0;i<sa;i++){
        int l=1LL*i-ml[i];
        int r=mr[i]-1LL-i;
        int rem=((1LL*l)-1LL)*r;
        v.push_back(make_pair(pr[A[i]],l+r+rem));
    }
    sort(v.begin(),v.end());
    int z=0;
    int in=0;
    for(int i=sa-1;i>=0;i--){
        pair<int,int>pq=v[i];
        z=z+pq.second;
        while(in<sb&&q[in].first<=z){
            x[q[in].second]=pq.first;
            in++;
        }
        if(in>=sb) break;
    }
    return x;
}

