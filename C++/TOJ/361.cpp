#include<bits/stdc++.h>
using namespace std;
struct dataStruct{
	double x1, x2,y1, y2;
};
int main(){
	double ans1 = 0, ans2 = 0, ans3;
	dataStruct dataBasic[3], data3, data1, stop;
	data3.x1 = 0;
	data3.y1 = 0;
	data3.x2 = 1000000000;
	data3.y2 = 1000000000;
	for ( int i = 0 ; i < 3 ; i++ ){
		cin >> dataBasic[i].x1
			>> dataBasic[i].y1
			>> dataBasic[i].x2
			>> dataBasic[i].y2;
			data3.x1 = max ( dataBasic[i].x1, data3.x1 );
			data3.y1 = max ( dataBasic[i].y1, data3.y1 );
			data3.x2 = min ( dataBasic[i].x2, data3.x2 );
			data3.y2 = min ( dataBasic[i].y2, data3.y2 );
			ans1 += ( dataBasic[i].x2 - dataBasic[i].x1 ) * ( dataBasic[i].y2 - dataBasic[i].y1 );
	}
	cout << ans1 << endl;
	for ( int i = 0 ; i < 3 ; i++ )
		for ( int j = 0 ; j < 3 ; j++ )
			if ( i != j ){
				stop.x1 = 0;
				stop.y1 = 0;
				stop.x2 = 1000000000;
				stop.y2 = 1000000000;
				stop.x1 = max ( dataBasic[i].x1, dataBasic[j].x1 );
				stop.x2 = min ( dataBasic[i].x2, dataBasic[j].x2 );
				stop.y1 = max ( dataBasic[i].y1, dataBasic[j].y1 );
				stop.y2 = min ( dataBasic[i].y2, dataBasic[j].y2 );
				ans2 += ( stop.x2 - stop.x1 ) * ( stop.y2 - stop.y1 );
				ans2 -= ans3;
			}
	ans2 /= 2;
	ans3 = ( data3.x2 - data3.x1 ) * ( data3.y2 - data3.y1 );
	ans1 -= 3 * ans3;
	ans1 -= 2 * ans2;
	printf ( "%.2f %.2f %.2f\n", ans3, ans2, ans3 );
}