#include<iostream>
using namespace std;
struct dataStruct{
	long long x, y;
};
int main(){
	dataStruct data, ans;
	cin >> data.x >> data.y;
	ans.x = 100;
	ans.y = 100;
	ans.y -= data.x;
	ans.x -= data.y;
	cout << ans.x << " " << ans. y << endl;
	return 0;
}