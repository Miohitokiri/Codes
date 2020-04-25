// by. MiohitoKiri5474
#include<bits/stdc++.h>

using namespace std;

#define maxN 100005
int seg[maxN << 2];

void update ( int l, int r, int index, int value, int n ){
	// 當前區間左邊界、當前區間右邊界、欲更新位置、欲更新位置之值、目前節點編號
	if ( l == r )
		seg[n] = value;
	else{
		int mid = ( l + r ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
		// int mid = ( l + r ) / 2, leftSon = n * 2, rightSon = leftSon + 1;
		if ( index <= mid ) // case 1
			update ( l, mid, index, value, leftSon );
		else // case 2
			update ( mid + 1, r, index, value, rightSon );

		seg[n] = max ( seg[leftSon], seg[rightSon] );
		// seg[n] = up ( seg[leftSon], seg[rightSon] );
	}
}

/*
case 1:
l 	 mid    r
|_____|_____|
	^
  index

case 2:
l 	 mid    r
|_____|_____|
		^
	  index
*/

int query ( int l, int r, int nowL, int nowR, int n ){
	// 欲查詢範圍左邊界、欲查詢範圍右邊界、當前區間左邊界、當前區間右邊界、當前區間編號
	if ( l <= nowL && nowR <= r )
		return seg[n];
	int mid = ( nowL + nowR ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
	if ( r <= mid ) // case 1
		return query ( l, r, nowL, mid, leftSon );
	if ( mid < l ) // case 2
		return query ( l, r, mid + 1, nowR, rightSon );

	// case 3
	return max ( query ( l, r, nowL, mid, leftSon ), query ( l, r, mid + 1, nowR, rightSon ) );
	// up ( query ( l, r, nowL, mid, leftSon ), query ( l, r, mid + 1, nowR, rightSon ) );
}

/*
case 1:
nowL    mid    nowR
|________|________|
  |___|
  l   r

case 2:
nowL    mid    nowR
|________|________|
            |___|
            l   r

case 3:
nowL    mid    nowR
|________|________|
       |___|
       l   r
*/