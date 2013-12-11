#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <cctype>
#include <cerrno>
#include <algorithm>
#include <list>
#include <queue>
#include <map>
#include <vector>

using namespace std;
    
#define REP(i,n) for(int _n=(n),i=0; i<_n; ++i)
#define FOR(i,a,b) for(int _b=(b),i=(a); i<=_b; ++i)
#define FORD(i,a,b) for(int _b=(b),i=(a); i>=_b; --i)
#define FORE(i,a)  for(VAR(i,a.begin()); i!=a.end(); ++i)

#define PB push_back
#define BEG begin()
#define END end()
#define SZ size()
#define MP make_pair
#define F first
#define S second
#define D double
#define LL long long
#define LD long double
#define VI vector<int>

#define wchuj 100*1000*1000

FILE *in,*out;
int t;
VI p;

void shuffle(){
	int s=p.size();
	REP(l,wchuj){
		int a=rand()%s,b=rand()%s;
	//	p[a]^=p[b]^=p[a]^=p[b];
		swap(p[a],p[b]);
	}
}

void gen1(){
	p.PB(1);
}

void gen2(){
	int n=2000;
	REP(i,n) p.PB(1+i+rand()%10);
	REP(i,100) p.PB(1000+rand()%1000);
	shuffle();
}

void gen3(){
	int n=3000;
	int a=900000;
	REP(i,n) p.PB(a+rand()%1000);
	shuffle();
}

void gen4(){
	int a=100000;
	REP(i,5000) p.PB(1+rand()%6000);
	REP(i,5000) p.PB(a+28);
	p.PB(a+27);
	shuffle();
}

void gen5(){
	int a=300000;
	REP(i,10000) p.PB(a/2+rand()%10);
	REP(i,10000) if (i!=5000) p.PB(a-i);
	p.PB(a-5000+1);
	shuffle();
}

void gen6(){
	REP(i,300){
		REP(j,300) p.PB(1+i%30+i*300+rand()%200);
	}
	shuffle();
}

void gen7(){
	int a=100000;
	REP(i,49999) p.PB(a-2*i);
	REP(i,50000) p.PB(2);
	shuffle();
}

void gen8(){
	int a=90000;
	REP(i,30000) REP(u,3) p.PB(a-3*i);
	REP(u,40) p.PB(65782-u*20);
	shuffle();
}


void gen9(){
	int a=80000;
	REP(i,20000) if (i!=2500) REP(u,4) p.PB(a-4*i);
	p.PB(70002);
	p.PB(70002);
	p.PB(70002);
	p.PB(69998);
	shuffle();
}

void gen10(){
	int a=80000;
	REP(i,20000) if (i!=2500 && i!=5000) REP(u,4) p.PB(a-4*i);
	p.PB(70002);
	p.PB(70002);
	p.PB(70000);
	p.PB(69999);
	p.PB(60002);
	p.PB(60002);
	p.PB(60000);
	p.PB(59999);
	shuffle();
}

void gen11(){
	int a=1000000;
	REP(i,9000) REP(u,10) p.PB(a-u);
	REP(i,10000) p.PB(a-rand()%1000);
	shuffle();
}


void generate_input(){
	srand((t*13272348)%22378947);
	switch(t){
		case 1: 
			gen1(); break;
		case 2: 
			gen2(); break;
		case 3: 
			gen3(); break;
		case 4: 
			gen4(); break;
		case 5: 
			gen5(); break;
		case 6: 
			gen6(); break;
		case 7: 
			gen7(); break;
		case 8: 
			gen8(); break;
		case 9: 
			gen9(); break;
		case 10: 
			gen10(); break;
		case 11: 
			gen11(); break;
		default: 
			break;
	}
}

int compute_answer(){
	sort(p.begin(),p.end());
	reverse(p.begin(),p.end());
	int b=-1,k,n=p.size();
	REP(i,n) if (b<(k=p[i]+i+2)) b=k;
	return b;
}

void do_flush(){
	int s=p.size();
	fprintf(in,"%d\n",s);
	REP(i,s){
		if (i) fprintf(in," "); fprintf(in,"%d",p[i]);
	}
	fprintf(in,"\n");
	fprintf(out,"%d\n",compute_answer());
}

int main(int argc, char** argv){
	t=atoi(argv[1]);
	char buf[50];
	sprintf(buf,"trees.%d.in",t);
	in=fopen(buf,"w");
	sprintf(buf,"trees.%d.ans",t);
	out=fopen(buf,"w");
	generate_input();
	do_flush();
	fclose(in); fclose(out);
	return 0;
}
