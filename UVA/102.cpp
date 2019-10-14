#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("0input.txt", "r", stdin);
    //freopen("0output.txt", "w", stdout);

    int i,j,k,n,m,s,ii,jj,kk;
    int b1,b2,b3,c1,c2,c3,g1,g2,g3;
    string str;

    while(cin>>b1>>g1>>c1>>b2>>g2>>c2>>b3>>g3>>c3)
    {

        s=b1+b2+b3+c1+c2+c3+g1+g2+g3;

        m=s-b1-c2-g3;
        str="BCG";
        n=s-b1-g2-c3;
        if(n<m)
        {
            m=n;
            str="BGC";
        }
        n=s-c1-b2-g3;
        if(n<m)
        {
            m=n;
            str="CBG";
        }
        n=s-c1-g2-b3;
        if(n<m)
        {
            m=n;
            str="CGB";
        }
        n=s-g1-b2-c3;
        if(n<m)
        {
            m=n;
            str="GBC";
        }
        n=s-g1-c2-b3;
        if(n<m)
        {
            m=n;
            str="GCB";
        }

        cout<<str<<" "<<m<<endl;
    }
    return 0;
}
