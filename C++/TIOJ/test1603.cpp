// 線段樹 單點修改與查詢區間最小值 
#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int seg[maxn*4];
inline void update(int p,int l,int r,int index,int value)
{
	if(l==r)    seg[p] = value;
	else
	{
		int m = (l+r)/2;
		int left = p*2;       //左兒子 
		int right = p*2+1;    //右兒子 
		if(index<=m)    update(left,l,m,index,value);    //目標區間在左兒子 
		else     update(right,m+1,r,index,value);        //目標區間在右兒子 
		seg[p] = min(seg[left],seg[right]);    //當前節點紀錄左右兒子的最小值 
	}
}
inline int query(int p,int l,int r,int now_l,int now_r) 
{                       //p:編號 , l:詢問左區間 , r:詢問右區間 , now_l:當前左區間 , now_r:當前右區間 
	if(l<=now_l && now_r <= r)    return seg[p];    //當前拜訪區間被詢問區間完全包含 直接回傳 
	int m = (now_l+now_r)/2;
	int left = p*2;       // 左兒子 
	int right = p*2+1;    // 右兒子 
	if(r<=m)    return query(left,l,r,now_l,m);    //詢問區間在當前區間中間的左邊 
	else if(l>m)    return query(right,l,r,m+1,now_r);    //詢問區間在當前區間中間的右邊 
	else    return min(query(left,l,m,now_l,m),query(right,m+1,r,m+1,now_r));//詢問區間在當前區間的左邊與右邊 
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N,Q;    //N個元素的序列 Q筆操作
	cin >> N >> Q;
	for(int i=0;i<maxn<<2;i++)    //init
	    seg[i] = 2147000000;
	for(int i=1;i<=N;i++)    //input
	{
	    int value;
		cin >> value;
		update(1,1,N,i,value);	
    } 
    while(Q--)
     {
    	string s;
    	cin >> s;
    	if(s == "query")
	    {
	    	int l,r;
    	    cin >> l >> r;    //詢問區間l~r的最小值
		    cout << query(1,l,r,1,N) << endl; 
		}
		else if(s == "modify")
		{
			int index,value;
			cin >> index >> value;
			update(1,1,N,index,value); 
		} 
	}
	return 0;
}

