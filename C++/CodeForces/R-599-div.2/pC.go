/************************************/
/* Date		: 2019-11-12 21:10:00	*/
/* Author	: MiohitoKiri5474		*/
/* Email	: lltzpp@gmail.com		*/
/************************************/

package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	ans := 0
	fmt.Scanf ( "%d", &n )
	sq := int ( math.Sqrt ( float64 ( n ) ) + 5 )
	if n == 1 {
		fmt.Println ( 1 )
		return
	}
	var lib [1000005]bool
	lib[0] = true
	lib[1] = true
	for i := 2 ; i < sq ; i++ {
		if lib[i] {
			continue
		}
		if n % i == 0 {
			ans = i
			break
		}
		for j := i * i ; j < sq ; j += i {
			lib[j] = true;
		}
	}

	if ans != 0 {
		for n % ans == 0 {
			n /= ans
		}

		if n != 1 {
			ans = 1
		}
		fmt.Println ( ans )
		return
	}

	fmt.Println ( n )
}