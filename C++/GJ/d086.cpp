#include<iostream>
#include<string>
#include<map>

using namespace std;

#define F first
#define S second
#define mp make_pair

struct pii{
	int F, S;
};

map < string, pii > lib;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	string str;
	bool fuckU;
	int num, w;
	double ans = 0.0;
	while ( cin >> str ){
		if ( str == "0000000000" )
			break;
		cin >> w >> num;
		if ( lib.find ( str ) != lib.end() ){
			lib[str].S += num;
		}
		else{
			lib[str].F = w;
			lib[str].S = num;
		}
	}

	for ( map < string, pii >::iterator i = lib.begin() ; i != lib.end() ; i++ ){
		num = i -> S.S;
		w = i -> S.F;
		if ( i -> F[0] == 'X' ){
			while ( num >= 2 ){
				ans += w;
				num -= 2;
			}
			if ( num )
				ans += w * 1.0;
		}
		else if ( i -> F[0] == 'Y' ){
			while ( num >= 2 ){
				ans += w * 1.5;
				num -= 2;
			}
			if ( num )
				ans += w * 1.0;
		}
		else{
			ans += num * w * 1.0;
		}
	}

	cout << ans << '\n';
}