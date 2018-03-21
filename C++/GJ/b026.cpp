#include<iostream>

using namespace std;

int main(){
	int n, ma = 0, sum = 0, in;
	cin >> n;
	while ( n-- ){
		cin >> in;
		sum += in;
		if ( sum < 0 )
			sum = 0;
		ma = max ( ma, sum );
	}

	cout << ma << '\n';
}