package main

import (
	"fmt"
)

func check ( n int ) bool {
	res := 0
	for n != 0 {
		res += n % 10
		n /= 10
	}

	return res % 4 == 0
}

func main() {
	var n int
	fmt.Scanf ( "%d", &n )
	for !check ( n ) {
		n++;
	}
	fmt.Println ( n )
}