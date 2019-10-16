#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;


int main()
{
    //freopen("0input.txt", "r", stdin);
    //freopen("0output.txt", "w", stdout);

    int t,n,m,i,j,a,b;
    char c;
    double d;
    cin>>t;
    while(t--)
    {
        cin>>c>>m>>n;

        if(c=='r')
            cout<<min(m,n)<<endl;
        else if(c=='k')
        {
            d=(double)n*m/2;
            cout<<ceil(d)<<endl;
        }
        else if(c=='Q')
            cout<<min(n,m)<<endl;
        else
        {
            d=(double)m/2;
            a=ceil(d);
            d=(double)n/2;
            b=ceil(d);
            cout<<a*b<<endl;
        }

    }
    return 0;
}
