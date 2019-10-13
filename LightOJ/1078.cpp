#include<bits/stdc++.h>
using namespace std;


int main()
{
    int t,tc,n,m,k,d;

    cin>>t;
    for(tc=1; tc<=t; tc++)
    {
        cin>>n>>d;
        k=1;
        m=d;
        while(m%n != 0)
        {
            m=m*10+d;
            m%=n;
            k++;
        }

        cout<<"Case "<<tc<<": "<<k<<endl;
    }

    return 0;
}
