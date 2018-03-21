#include<iostream>
#include<string>
using namespace std;
int fine ( string data ){
	if ( data == "I" )
		return 1;
	else if ( data == "V" )
		return 5;
	else if ( data == "X" )
		return 10;
}
void count( string data ){
	long long ans,ds = data.size();//ds==data.size()
	int sa[ds];
	for ( int i = 0 ; i < ds ; i++ ){
		sa[i] = fine ( data[i] );
		if ( i != 0 ){
			if ( sa [i] > sa[i - 1] ){
				ans -= sa[i - 1];
				ans += sa[i];
			}
			else{
				ans += sa[i];
				ans += sa[i- 1];
			}
		}
	}
	cout << ans << endl;
}
int main(){
	string data;
	while ( cin >> data ){
		count ( data );
	}
	return 0;
}