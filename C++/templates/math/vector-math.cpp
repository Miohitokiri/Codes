// by. MiohitoKiri5474
#include<bits/stdc++.h>

using namespace std;

struct vt{
	double x, y;

	vt(){}
	vt ( double _x, double _y ): x ( _x ), y ( _y ) {}

	inline vt operator + ( vt b ){
		return vt ( x + b.x, y + b.y );
	}

	inline vt operator - ( vt b ){
		return vt ( x - b.x, y - b.y );
	}

	inline vt operator * ( double swp ){
		return vt ( x * swp, y * swp );
	}

	inline vt operator / ( double swp ){
		return vt ( x / swp, y / swp );
	}

	inline bool operator == ( vt b ){
		return a == b.x && y == b.y;
	}

	inline double dot ( vt b ){ // 內積
		return x * b.x + y * b.y;
	}

	inline double cross ( vt b ){ // 外積
		return x * b.y - y * b.x;
	}

	inline vt norman ( void ) const{ // 法向量
		return vt ( -y, x );
	}

	inline double abs2 ( void ) const{ // 長度平方
		return dot ( *this );
	}

	inline double rad ( const vt &b ){ // 兩向量弧度
		return fabs ( atan2 ( fabs ( cross ( b ) ), dot ( b ) ) );
	}

	inline vt rot ( double sieda ) const{ // 旋轉
		return vt ( cos ( sieda ) * x - sin ( sieda ) * y, sin ( sieda ) * x + cos ( sieda ) * y );
	}
};