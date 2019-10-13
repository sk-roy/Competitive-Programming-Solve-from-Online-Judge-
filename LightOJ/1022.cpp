#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

int main()
{
    int t,i,j;
    double r;
    cin>>t;
    for(i=1; i<=t; i++)
    {
        cin>>r;
        cout<<fixed<<setprecision(2);
        cout<<"Case "<<i<<": "<<4*r*r-acos(-1.0)*r*r<<endl;
    }
    return 0;
}
