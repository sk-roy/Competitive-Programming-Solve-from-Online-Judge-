#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5;
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
}

map <int,int> mp;
set <int> st;
int fc[50000];
int arr[50000];
int f,dv;

void factor(int k)
{
    f=0;
    for(int i=0; (ll)pm[i]*pm[i]<=(ll)k; i++)
    {
        while(k%pm[i]==0)
        {
            k/=pm[i];
            mp[pm[i]]++;
            if(mp[pm[i]]==1) fc[f++]=pm[i];
        }
    }
    if(k!=1)
    {
        mp[k]++;
        fc[f++]=k;
    }
    return ;
}

void divi(int i, int n, int l)
{
    if(i==f)
    {
        if(n>l) arr[dv++]=n;
        return ;
    }
    for(int j=0; j<=mp[fc[i]]; j++)
    {
        divi(i+1,n,l);
        n*=fc[i];
    }
}


int main()
{
    seive();
    int p,l,i,k;
    int t,tc;
    cin>>t;
    for(tc=1; tc<=t; tc++)
    {
        cin>>p>>l;
        k=p-l;

        mp.clear();
        dv=0;
        factor(k);
        divi(0,1,l);

        sort(arr,arr+dv);
        cout<<"Case "<<tc<<':';
        for(i=0; i<dv; i++)
            cout<<" "<<arr[i];
        if(!dv) cout<<" impossible";
        cout<<endl;
    }
    return 0;
}
