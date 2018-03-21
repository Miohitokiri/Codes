#include<iostream>
using namespace std;
int main(){
	long long n;
	while ( cin >> n ){
		if ( n % 4 == 0 ){
			if ( n % 100 != 0 )
				cout <<  "YES";
			else{
				if ( n % 400 == 0 )
					cout << "YES";
				else
					cout << "NO";
			}
		}
		else
			cout << "NO";
	}
	cout << endl;
}