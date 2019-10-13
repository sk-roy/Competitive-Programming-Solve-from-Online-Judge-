#include<bits/stdc++.h>
using namespace std;


int main()
{
    //freopen("0input.txt", "r", stdin);
    //freopen("0output.txt", "w", stdout);


    int t,tc,n,m,k,i;

    cin>>t;
    for(tc=1; tc<=t; tc++)
    {
        int r,c;
        cin>>r>>c;
        if(r>c) swap(r,c);

        //if(tc==126) cout<<r<<" "<<c<<endl;
        //else continue;

        n=0;
        if(r==1) n=c;
        else if(r==2)
        {
            n=4;
            c-=2;
            m=(c/4);
            n+=m*4;
            m=c%4;
            if(m==3) n+=2;
        }
        else
        for(i=0; i<r; i++)
        {
            if(i%2==0) n+=(c+1)/2;
            else n+=c/2;
        }

        cout<<"Case "<<tc<<": "<<n<<endl;
    }
    return 0;
}
