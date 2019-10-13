#include<bits/stdc++.h>
using namespace std;

typedef double ld;
const int N = 1e6+1;
const int B = 1e3+1;
ld lg[N+5];
ld base[B+5];

void fc()
{
    lg[0]=0.0;
    for(int i=1; i<N; i++)
        lg[i]=lg[i-1]+log10(i);
    for(int i=2; i<B; i++)
        base[i]=log10(i);
}

int main()
{
    fc();
    int t;
    int n,b;

    cin>>t;
    for(int tc=1; tc<=t; tc++)
    {
        cin>>n>>b;
        ld k= lg[n]/base[b];
        cout<<"Case "<<tc<<": "<<(int)k+1<<endl;
    }
    return 0;
}
