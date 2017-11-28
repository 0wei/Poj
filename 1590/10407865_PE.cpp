#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	string s,t;
	int i ;
	bool bl[3];
	while(cin>>s)
	{
		for(i = 0; i < 3; i++)
			bl[i] = false;       //0 r 1 m
		for(i = 0; i < s.length(); i++)
			if(s[i] <'0'||(s[i] >'9'&&s[i] < 'A') || s[i] >'Z')
				return 0;
		t = s;
		reverse(t.begin(),t.end());
		if(t == s)    // -- is a regular palindrome.
			bl[0] = true;
		for(i = 0; i < t.length(); i++)
		{
			if(t[i] =='E')	t[i] = '3';
			else if(t[i] =='J')	t[i] = 'L';
			else if(t[i] =='L')	t[i] = 'J';
			else if(t[i] =='S')	t[i] = '2';
			else if(t[i] =='Z')	t[i] = '5';
			else if(t[i] =='2')	t[i] = 'S';	
			else if(t[i] =='3')	t[i] = 'E';
			else if(t[i] =='5') t[i] = 'Z';
			else if(t[i] =='A'||t[i] =='H'||t[i] =='I'||t[i] =='M'||t[i] =='O'||t[i] =='T'||
			t[i] =='U'||t[i] =='V'||t[i] =='W'||t[i] =='X'||t[i] =='Y'||t[i] =='1'||t[i] =='8'){}
			else{bl[2] = true;break;}
		}
		
		if(bl[2] ==false&&t == s)   //mirror
			bl[1] = true;
		if(bl[0]&&bl[1] ==false)
			cout<<s<<" -- is a regular palindrome."<<endl;
		if(bl[1]&&bl[0] ==false)
			cout<<s<<" -- is a mirrored string."<<endl;
		if(bl[0]&&bl[1])
			cout<<s<<" -- is a mirrored palindrome."<<endl;
		if(bl[0]==false&&bl[1] ==false)
			cout<<s<<" -- is not a palindrome."<<endl;
	}
	return 0;
}