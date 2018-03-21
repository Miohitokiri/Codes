#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	auto gets;
	int stop = 1, ans = 0;
	queue plus, multiply;
	string s;
	stringstream ss;
	while ( getline ( cin, s ) ){
		ss.clear();
		ss.str ( s );
		ss >> gets;
		while ( ss >> gets ){
			if ( gets == '*' ){
				ss >> gets;
				multiply.push ( gets );
			}
			else if ( gets == '+' ){
				if ( multiply,size() != 0 ){
					while ( multiply.size() != 0 )
						stop *= multiply.top();
					ans += stop;
					stop = 1;
				}
				else{
				}
			}
		}
	}
}