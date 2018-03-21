#include<iostream>

using namespace std;

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	int n, max = 0, min = 1e9 , sum;
	cin >> n;
	while ( n-- ){
		 cin >> sum;
		 if ( sum > max )
		 	max = sum;
		 else if ( sum < min )
		 	min = sum;
	}
	if ( max == min )
		cout << "Same!";
	else
		cout << max <<" "<< min;
	cout << '\n';
}