#include<iostream>

using namespace std;

int main(){
	int hu, du, hd, dd;
	cin >> hu >> du >> hd >> dd;
	for ( int i = 1 ; hu > 0 && hd > 0 ; i++ ){
		cout << "Round " << i << ":\n";
		cout << "You hit Dragon " << du <<" points.\n";
		hd -= du;
		hd = max ( hd, 0 );
		cout << "You:" << hu << " Dragon:" << hd << '\n';
		if ( !hd ){
			cout << "You Win!\n";
			return 0;
		}
		cout << "Dragon hits You " << dd << " points.\n";
		hu -= dd;
		hu = max ( hu, 0 );
		cout << "You:" << hu << " Dragon:" << hd << '\n';
		if ( !hu ){
			cout << "You Lose!\n";
			return 0;
		}
	}
}