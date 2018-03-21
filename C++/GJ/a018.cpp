#include<iostream>
using namespace std;
int main(){
	long long h, m;
	cin >> h >> m;
	if ( h >= 14 && h <= 16 ){
		if ( ( h == 14 && m < 20 ) || ( h == 16 && m > 40 ) )
			cout << "NO";
		else
			cout << "YES";
	}
	else
		cout << "NO";
	cout << endl;
}