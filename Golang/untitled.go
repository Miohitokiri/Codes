/************************************/
/*  Date	: 2019-03-13 18:05:26	*/
/* Author	: MiohitoKiri5474		*/
/* Email	: lltzpp@gmail.com		*/
/************************************/

package main

import (
	"fmt"
)

var data[105] int

func main(){
	var (
		n int
		l int
		r int
		k int
		ans int
	)

	fmt.Scanf ( "%d\n", &n )
	for i := 0 ; i < n ; i++ {
		fmt.Scanf ( "%d %d\n", &l, &r )
		data[i] = r
	}
	fmt.Scanf ( "%d", &k )
	for i := 0 ; i < n ; i++ {
		ans = i
		if data[i] >= k {
			break
		}
	}

	if data[ans] == k {
		ans += 0
	}
	fmt.Println ( n - ans )
}