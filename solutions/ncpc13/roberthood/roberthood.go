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

/*
>0 left
=0 on line
<0 right
*/
func isLeft(p0,p1,p2 point) int {
	return ((p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y)) 
}

//Monotone Chain 
func convexHull(p []point) []point { 
	var i int
	hull := make([]point, 0,len(p)/5); // the 5 is arbitrary 
	
	sort.Sort(pointSort(p))
	
	minmin := 0
	for i=1; i<len(p)-1; i++ {
		if p[i].x != p[minmin].x { break }
	}
	minmax := i-1
	
	if minmax == len(p)-1 {// all x == xmin
		hull = append(hull,p[minmin], p[minmax])
		return hull
	}
	
	maxmax := len(p)-1
	for i=len(p)-2; i>=0; i-- {
		if p[maxmax].x != p[i].x { break }
	}
	maxmin := i+1
	
	//Lower hull
	hull = append(hull, p[minmin])
	for i=minmax+1; i<maxmin; i++ {
		if isLeft(p[minmin], p[maxmin], p[i]) >=0 && i<maxmin {
			continue
		}
		for len(hull)>=2 {
			if isLeft(hull[len(hull)-2], hull[len(hull)-1], p[i]) > 0 {
				break;
			} else {
				hull = hull[0:len(hull)-1]
			}
		}
		hull = append(hull, p[i])
	}
	
	//Upper hull
	if maxmax != maxmin {
		hull = append(hull, p[maxmax])
	}
	bot := len(hull)
	for i=maxmin-1; i>minmax; i-- {
		if isLeft(p[maxmax], p[minmax], p[i]) >= 0 && i>minmax {
			continue
		}
		for len(hull)>=(bot+2) {
			if isLeft(hull[len(hull)-2], hull[len(hull)-1], p[i]) > 0 {
				break;
			} else {
				hull = hull[0:len(hull)-1]
			}
		}
		hull = append(hull, p[i])
	}
	if minmax != minmin {
		hull = append(hull, p[minmin])
	}
	fmt.Println(hull)
	return hull
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
