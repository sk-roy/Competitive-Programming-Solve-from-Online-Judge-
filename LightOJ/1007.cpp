#include<bits/stdc++.h>
using namespace std;


typedef unsigned long long ll;
const ll N = 5e6+1;

ll phi[N+5];

void solve()
{
    for(int i=0; i<N; i++) phi[i]=i;
    for(int i=2; i<N; i++)
        if(phi[i]==i)
            for(int j=i; j<N; j+=i)
                phi[j] -= phi[j]/i;
    for(int i=2; i<N; i++)
        phi[i]=(phi[i]*phi[i])+ phi[i-1];
}



int main()
{
    //freopen("0input.txt", "r", stdin);
    //freopen("0output.txt", "w", stdout);


    solve();

    //for(int i=1; i<20; i++)
    //    cout<<i<<" "<<phi[i]<<endl;

    int t;
    cin>>t;
    //scanf("%lld", &t);
    for(int tc=1; tc<=t; tc++)
    {
        int a,b;
        cin>>a>>b;
        //scanf("%lld %lld", &a, &b);
        if(a>b) swap(a,b);
        cout<<"Case "<<tc<<": "<<(ll)(phi[b]-phi[a-1])<<endl;
    }

    return 0;
}

