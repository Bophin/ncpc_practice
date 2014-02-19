package main

import (
	"fmt"
	"os"
	"bufio"
	"strings"
	"sort"
	"strconv"
)
type point struct {
	x int
	y int
}

type pointSort []point

func (pts pointSort) Len() int 			{return len(pts)}
func (pts pointSort) Swap(i,j int)		{pts[i],pts[j]=pts[j],pts[i]}
func (pts pointSort) Less(i,j int) bool	{
	if pts[i].x == pts[j].x {
		return pts[i].y < pts[j].y
	}
	return pts[i].x<pts[j].x
}

//Is p2 right of the line of p0 p1? Using the 2d-cross product!
func isRight(p0,p1,p2 point) bool {
	return ((p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y))<0 }

//Monotone Chain Algorithm
func convexHull(pts []point) {  
	
	sort.Sort(pointSort(pts))
	
	//Lower hull
	lh := make([]point, len(pts)/2); lh[0]=pts[0]
	for i:=1; i<len(pts)-1; i++ {
		if isRight(pts[0],pts[len(pts)-1],pts[i]) {
			fmt.Println("Hello")
		}
	}
	//Upper hull
	uh := make([]point, len(pts)/2); uh[0]=pts[len(pts)-1]
	for i:=1; i<len(pts)-1; i++ {
		if isRight(pts[len(pts)-1],pts[0],pts[i]) {
			fmt.Println("Hello2")
		}
	}
	fmt.Println(pts)
	fmt.Println(len(pts))
}

func main() {
	var in []string
	pSlice := make([]point, 10)
	
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan() //throw away first input
	
	for i:=0; scanner.Scan(); i++ {
		in = strings.Split(scanner.Text(), " ")
		pSlice[i].x,_ = strconv.Atoi(in[0])
		pSlice[i].y,_ = strconv.Atoi(in[1])
	}
	convexHull(pSlice)
}
