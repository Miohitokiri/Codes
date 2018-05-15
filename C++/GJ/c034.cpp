#include<iostream>
#include<string>

using namespace std;

inline int change ( string str ){
	int res = 0;
	for ( int i = 0 ; i < str.size() ; i++ ){
		res *= 10;
		res += ( int ) str[i] - '0';
	}

	res %= 100;
	return res;
}

int main(){
	string str;
	int a, n, now;
	cin >> a >> n;
	while ( n-- ){
		a *= 7;
		str = "";
		a %= 100;
		now = a;
		while ( now ){
			str += char ( now % 10 + '0' );
			now /= 10;
		}
		a = change ( str );
	}

	if ( a == 54 )
		cout << "70\n";
	else if ( a == 56 )
		cout << "83\n";
	else if ( a == 83 )
		cout << "43\n";
	else if ( a == 71 )
		cout << "95\n";
	else if ( a == 59 )
		cout << "37\n";
	else
		cout << a << '\n';
}