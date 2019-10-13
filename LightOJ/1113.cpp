#include<iostream>
using namespace std;


int main()
{
    string s,str[500];
    int t;

    cin>>t;
    for(int tc=1; tc<=t; tc++)
    {
        int n=0, m=1;
        str[0]="http://www.lightoj.com/";

        cout<<"Case "<<tc<<":"<<endl;
        while(cin>>s && s!="QUIT")
        {
            if(s=="BACK")
            {
                if(n>0) cout<<str[--n]<<endl;
                else cout<<"Ignored"<<endl;
            }
            else if(s=="FORWARD")
            {
                if(n+1<m) cout<<str[++n]<<endl;
                else cout<<"Ignored"<<endl;
            }
            else
            {
                n++;
                cin>>str[n];
                m=n+1;
                cout<<str[n]<<endl;
            }
            //cout<<n<<" "<<m<<endl;
        }
    }

    return 0;
}
