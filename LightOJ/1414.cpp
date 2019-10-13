#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool leap(int n)
{
    if((n%100==0 && n%400==0) || (n%100!=0 && n%4==0)) return 1;
    else return 0;
}

int main()
{
    //freopen("0input.txt", "r", stdin);
    //freopen("0output.txt", "w", stdout);

    int t,tc,n;
    string month1, month2;
    char c;
    int yr1,yr2,day1,day2;

    cin>>t;
    for(tc=1; tc<=t; tc++)
    {
        cin>>month1>>day1>>c>>yr1;
        cin>>month2>>day2>>c>>yr2;

        //if(tc<4) continue;

        if(month1=="January" || month1=="February") yr1--;
        if(month2=="January") yr2--;
        else if(month2=="February" && day2!=29) yr2--;

        /*
        cout<<yr1/4<<" <--4--> "<<yr2/4<<endl;
        cout<<yr1/100<<" <--100--> "<<yr2/100<<endl;
        cout<<yr1/400<<" <--400--> "<<yr2/400<<endl;
        */

        n = 0;
        n += (yr2/4) - (yr1/4);
        n -= (yr2/100) - (yr1/100);
        n += (yr2/400) - (yr1/400);

        cout<<"Case "<<tc<<": "<<n<<endl;
    }


    return 0;
}
