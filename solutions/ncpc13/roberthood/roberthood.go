package main

import (
	"fmt"
	"os"
	"bufio"
	"strings"
	//"sort"
	"strconv"
)
type point struct {
	x int
	y int
}

type largeInt []int
func (a largeInt) Len() int 			{return len(a)}
func (a largeInt) Swap(i,j int)		{a[i],a[j] = a[j],a[i]}
func (a largeInt) Less(i,j int) bool	{return a[i]<a[j]}

func convexHull(points []point) {
	var p0i int
	p0 := points[0]
	
	//find pivot point
	for i,p := range points {
		if p.y <= p0.y || (p.y == p0.y && p.x < p0.x) {
			p0 = p
			p0i = i
		}			
	}
	fmt.Println(p0)
	fmt.Println(p0i)
}

func main() {
	var in []string
	points := make([]point, 10)

	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan() //throw away first input
	for i:=0; scanner.Scan(); i++ {
		in = strings.Split(scanner.Text(), " ")
		fmt.Println(in)
		points[i].x,_ = strconv.Atoi(in[0])
		points[i].y,_ = strconv.Atoi(in[1])
	}
	convexHull(points)
}
