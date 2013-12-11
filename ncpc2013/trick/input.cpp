#include <iostream>
using namespace std;

int counter = 1;
void write(double x) {
    char name[100];
    sprintf(name,"trick.%02d.in",counter);
    FILE* file = fopen(name,"w");
    fprintf(file,"%.4lf\n",x);
    fclose(file);
    sprintf(name,"./trick < trick.%02d.in > trick.%02d.ans",counter,counter);
    system(name);
    ++counter;
}

int main() {
    write(3);
    write(2);
    write(1);
    write(10);
    write(999.9999);
    write(123);
    write(1.2);
    write(1.6);
    write(2.2);
    write(1.0375);
    write(1.75);
    write(1.6675);
    write(1.2088);
    write(1.112);
    write(1.24);
    write(2.0008);
    write(4.995);
    write(4.5);
    write(1.2345);
}
