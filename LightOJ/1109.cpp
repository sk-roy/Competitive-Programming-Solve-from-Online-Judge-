#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e3+1;
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

int dv[N+5];

void divisor()
{
    dv[1]=1;
    for(int i=2; i<N; i++)
    {
        if(!flag[i])
        {
            dv[i]=2;
            continue;
        }
        int n=i;
        int k=0;
        for(int j=0; pm[j]*pm[j]<=n; j++)
        {
            while(n%pm[j]==0) k++, n/=pm[j];
            if(k) break;
        }
        dv[i]= dv[n]*(k+1);
    }
    return ;
}

bool comp(pair <int,int> a, pair <int,int> b)
{
    if(a.first==b.first) return a.second>b.second;
    else return a.first<b.first;
}


int main()
{
   seive();
   divisor();

   vector < pair <int,int> > vp;
   for(int i=1; i<N; i++)
   {
       vp.push_back({dv[i],i});
   }
   sort(vp.begin(),vp.end(),comp);

   int t,n,tc;
   cin>>t;
   for(tc=1; tc<=t; tc++)
   {
       cin>>n;
       cout<<"Case "<<tc<<": "<<vp[n-1].second<<endl;
   }

   return 0;

}

