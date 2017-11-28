#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    int a, b, t,i;
    while (cin >> s)
    {
        string t(s);
        if (s == "end") break;
        
        for ( i=0; i<s.size(); ++i)
        {
            if (s.find("a")>s.size() && s.find("e")>s.size() && s.find("i")>s.size()
                && s.find("o")>s.size() && s.find("u")>s.size())
            {
                cout << "<" << s << "> is not acceptable." << endl;
                goto L;
            }
        }

        for ( i=0; i<t.size(); ++i)
        {
            if (t[i]=='a' || t[i]=='e' || t[i]=='i' || t[i]=='o' || t[i]=='u')
                t[i] = 't';
            else
                t[i] = 'f';
        }
        for ( i=0; i<t.size(); ++i)
        {
            if (0 == i)
            {
                if (t[i]==t[i+1] && t[i]==t[i+2])
                {
                    cout << "<" << s << "> is not acceptable." << endl;
                    goto L;
                }
            }
            if (t.size()-1 == i)
            {
                if (t[i]==t[i-1] && t[i]==t[i-2])
                {
                    cout << "<" << s << "> is not acceptable." << endl;
                    goto L;
                }
            }
            if (t[i]==t[i-1] && t[i]==t[i+1])
            {
                cout << "<" << s << "> is not acceptable." << endl;            
                goto L;
            }
        }
        
        for ( i=1; i<s.size(); ++i)
        {
            if (s[i]!='e' && s[i]!='o')
            {
                if (s[i] == s[i-1])
                {
                    cout << "<" << s << "> is not acceptable." << endl;
                    goto L;
                }
            }
        }
        
        cout << "<" << s << "> is acceptable." << endl;
        L:
            continue;
    }
    return 0;
}
