package main

import (
	"fmt"
)

func main() {
	a := []int{3, 4, 5, 3, 9}
	b := a[1:len(a)]
	
	a[3]=17
	
	fmt.Println(a)
	fmt.Println(b)
}
