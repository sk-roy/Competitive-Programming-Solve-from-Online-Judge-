#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e3;
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

map <int,int> mp[105];

void factorize()
{
    for(int i=2; i<102; i++)
    {
        int n=i;
        mp[i]=mp[i-1];
        for(int j=0; pm[j]*pm[j]<=n; j++)
        {
            while(n%pm[j]==0)
            {
                n/=pm[j];
                mp[i][pm[j]]++;
            }
        }
        if(n!=1) mp[i][n]++;
    }
    return ;
}


int main()
{
    //freopen("0input.txt", "r", stdin);
   // freopen("0output.txt", "w", stdout);


    seive();
    factorize();

    int t,tc,n;

    cin>>t;
    for(tc=1; tc<=t; tc++)
    {
        cin>>n;

        cout<<"Case "<<tc<<": "<<n<<" =";
        bool First=true;
        for(auto k: mp[n])
        {
            if(!First) cout<<" *";
            First=false;
            cout<<" "<<k.first<<" ("<<k.second<<")";
        }
        cout<<endl;
    }

    return 0;
}
