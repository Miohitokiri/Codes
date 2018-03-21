#include<iostream>
using namespace std;
int main(){
	long long h,m;
	cin >> h >> m;
	if ( h > 7 && h < 17 ){
		cout << "At School";
	}
	else if ( h == 7 && m >= 30 ){
		cout << "At School";
	}
	else{
		cout << "Off School";
	}
	cout << endl;
	return 0;
}
