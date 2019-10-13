#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e6+1;

bool flag[N+5];
int pm[N+5];
int tp;

void seive()
{
    for(int i=2; i*i<N; i++)
        if(!flag[i])
            for(int j=i*i; j<N; j+=i)
                flag[j]=1;
    tp=0;
    for(int i=2; i<N; i++)
        if(!flag[i]) pm[tp++]=i;
    return ;
}

ll expo(ll b, ll p)
{
    if(p==0) return 1;
    if(p%2==0) return expo(b*b, p/2);
    else return b*expo(b*b, p/2);
}


map <int,int> ma;

void make(ll a)
{
    int k;
    for(int i=0; pm[i]*pm[i]<=a && a!=1; i++)
    {
        k=0;
        while(a%pm[i]==0)
        {
            k++;
            a/=pm[i];
        }
        if(k) ma[pm[i]]=max(ma[pm[i]], k);
    }
    if(a>1) ma[a]= max(ma[a], 1);
}

ll solve(ll a, ll b, ll l)
{
    ma.clear();
    make(a);
    make(b);

    int k;
    ll c=1;
    for(int i=0; pm[i]*pm[i]<=l && l!=1; i++)
    {
        k=0;
        while(l%pm[i]==0)
        {
            k++;
            l/=pm[i];
        }
        if(k<ma[pm[i]]) return -1;
        if(k)
        {
            if(k>ma[pm[i]]) c *= expo(pm[i], k);
            ma[pm[i]]=0;
        }
    }
    if(l!=1 && !ma[l]) c *= l;
    if(l!=1 && ma[l]>1) return -1;
    if(l!=1) ma[l]=0;

    for(auto i: ma)
    {
        if(i.second != 0) return -1;
    }

    return c;
}


int main()
{
    //freopen("0input.txt", "r", stdin);
    //freopen("0output.txt", "w", stdout);
    seive();

    int t,tc;
    ll l,a,b,c;
    cin>>t;
    for(tc=1; tc<=t; tc++)
    {
        cin>>a>>b>>l;
        //if(tc==51) cout<<a<<" "<<b<<" "<<l<<endl;
        //else continue;
        c=solve(a,b,l);
        cout<<"Case "<<tc<<": ";
        if(c==-1) cout<<"impossible"<<endl;
        else cout<<c<<endl;
    }

    return 0;
}
