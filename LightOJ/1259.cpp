#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e7+5;
const int M = 1e6+5;

bool flag[N+5];
int pm[M+5];
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


int main()
{
    //freopen("0input.txt", "r", stdin);
    //freopen("0output.txt", "w", stdout);


    seive();
   // cout<<tp<<endl;
    int i,t,tc,n,ans;

    scanf("%d", &t);
    for(tc=1; tc<=t; tc++)
    {
        scanf("%d", &n);
        //cin>>n;
        ans=0;
        for(i=0; i<tp; i++)
        {
            if(pm[i]*2>n) break;
            if(!flag[n-pm[i]]) ans++;
        }
        //cout<<"Case "<<tc<<": "<<ans<<endl;
        printf("Case %d: %d\n", tc, ans);
    }

    return 0;
}
