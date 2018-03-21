#include<iostream>
using namespace std;
int fine ( char data ){
	switch ( data ){
		case '9' : return 9;
			break;
		case '8' : return 8;
			break;
		case '7' : return 7;
			break;
		case '6' : return 6;
			break;
		case '5' : return 5;
			break;
		case '4' : return 4;
			break;
		case '3' : return 3;
			break;
		case '2' : return 2;
			break;
		case '1' : return 1;
			break;
		case '0' : return 0;
			break;
	}
}
int main(){
	string data;
	cin >> data;
	long long ans = 0;
	for ( int i = 0 ; i < data.size() ; i++ )
		ans += fine ( data[i] );
	cout << ans << endl;
}