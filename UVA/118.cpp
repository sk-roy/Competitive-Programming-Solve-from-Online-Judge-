#include<bits/stdc++.h>
using namespace std;


int main()
{
    //freopen("0input.txt", "r", stdin);
    //freopen("0output.txt", "w", stdout);


    int x5,y5,x,y,x0,y0,i,j;
    char orn;
    string s;
    bool go_out;
    //map <int, int> lost;
    int lost[55][55];
    for(i=0; i<55; i++)
        for(j=0; j<55; j++)
            lost[i][j]=0;

    cin>>x5>>y5;

    while(cin>>x>>y>>orn)
    {
        cin>>s;
        go_out=false;
        for(i=0; i<s.size(); i++)
        {
            if(s[i]=='L')
            {
                if(orn=='E')
                    orn='N';
                else if(orn=='N')
                    orn='W';
                else if(orn=='W')
                    orn='S';
                else
                    orn='E';
            }
            else if(s[i]=='R')
            {
                if(orn=='E')
                    orn='S';
                else if(orn=='N')
                    orn='E';
                else if(orn=='W')
                    orn='N';
                else
                    orn='W';
            }
            else
            {
                x0=0,y0=0;
                if(orn=='E')
                    x0++;
                else if(orn=='W')
                    x0--;
                else if(orn=='N')
                    y0++;
                else
                    y0--;

                if(x+x0>x5 || x+x0<0 || y+y0>y5 || y+y0<0)
                {
                    if(lost[x][y]==0)
                    {
                        go_out=true;
                        lost[x][y]=1;
                        cout<<x<<" "<<y<<" "<<orn<<" LOST"<<endl;
                        break;
                    }
                }
                else
                {
                    x+=x0;
                    y+=y0;
                }
            }
        }
        if(go_out==false)
            cout<<x<<" "<<y<<" "<<orn<<endl;
    }
    return 0;
}
