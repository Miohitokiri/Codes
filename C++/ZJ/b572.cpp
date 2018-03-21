#include<iostream>
using namespace std;
int main(){
	long long n;
	cin >> n;
	for ( int i = 0 ; i < n ; i++ ){
		int h1,m1,h2,m2,m3,data_time;//nt = need time
		cin >> h1 >> m1 >> h2 >> m2 >> m3;
		data_time = ( h2 - h1 ) * 60 + m2 - m1;
		if ( m3 <= data_time ){
			cout << "Yes";
		}
		else{
			cout << "No";
		}
		cout << endl;
	}
	return 0;
}
