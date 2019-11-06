package main

import (
	"fmt"
)

func main() {
	var n, ans, i, swp, mod int64
	swp = 1
	ans = 1
	mod = 998244353
	fmt.Scanf ( "%d", &n )
	for i = 2 ; i <= n ; i++ {
		swp *= i
		swp %= mod
		ans = ( i * ans ) % mod + swp - i
		ans %= mod
	}
	fmt.Println ( ans )
}