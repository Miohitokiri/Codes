#include<iostream>
#include<string>
using namespace std;
 int main(){
 	long long data, ans = 0;
 	cin >> data;
 	while ( data != 0 ){
 		ans += data % 10;
 		data /= 10;
 		ans *= 10;
 	}
 	ans /= 10;
 	cout << ans << endl;
 }