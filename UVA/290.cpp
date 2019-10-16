#include<bits/stdc++.h>
using namespace std;

bool palindrome(string &s)
{
    for(int i=0, j=s.size()-1; i<j; i++,j--)
        if(s[i]!=s[j]) return 0;
    return 1;
}

int f(char c)
{
    if(isalpha(c)) return c-'A'+10;
    else return c-'0';
}

char ff(int k)
{
    if(k>=10) return char(k+'A'-10);
    else return char(k+'0');
}


int main()
{
    string s,ss,sss;
    int n,m,i,j,k,carry;
    int a[16];

    while(cin>>sss)
    {

        for(int base=15; base>=2; base--)
            a[base]=101;
        for(int base=15; base>=2; base--)
        {
            s=sss;
            bool no=false;
            for(i=0; i<s.size(); i++)
                if(f(s[i])>=base)
                {
                    no=true;
                    break;
                }
            if(no) break;

            n=0;
            while(!palindrome(s) && n<=100)
            {
                //cout<<s<<" "<<s.size()<<endl;
                ss="";
                n++;
                carry=0;
                for(i=0,j=s.size()-1; i<s.size(); i++,j--)
                {
                    carry += f(s[i]) + f(s[j]);
                    //cout<<carry<<" ";
                    ss= ff(carry%base) + ss;
                    carry /= base;
                }
                //cout<<endl;
                if(carry) ss= ff(carry) + ss;
                s=ss;
            }
            a[base]=n;
            //cout<<"Base: "<<base<<" "<<s<<endl;
            //break;
        }

        for(i=15; i>=2; i--)
        {
            if(i<15)cout<<" ";
            if(a[i]==101) cout<<'?';
            else cout<<a[i];
        }
        cout<<endl;
    }

    return 0;
}
