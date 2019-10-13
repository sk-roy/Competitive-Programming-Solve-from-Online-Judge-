#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
double h[N+5];
const double gama = 0.57721566490153286060651209;

int main()
{
    h[1]=1.0;
    for(int i=2; i<N; i++)
        h[i]=h[i-1]+(1.0/i);

    int t,n;
    double k;
    scanf("%d", &t);
    for(int tc=1; tc<=t; tc++)
    {
        scanf("%d", &n);
        printf("Case %d: ", tc);

        if(n<N) k=h[n];
        else k=log(n)+(1.0/(2.0*n) + gama);
        cout<<fixed<<setprecision(10)<<k<<endl;
    }


    return 0;
}
