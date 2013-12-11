#include <iostream>
using namespace std;

int main() {
    FILE* file = fopen("virus-05.in","w");
    for (int i = 0; i < 100000; ++i) {
        fprintf(file,"A");
    }
    fprintf(file,"\n");
    for (int i = 0; i < 100000; ++i) {
        fprintf(file,"A");
    }
    fprintf(file,"\n");
    fclose(file);
    file = fopen("virus-05.ans","w");
    fprintf(file,"0\n");
    fclose(file);
    
    
    file = fopen("virus-06.in","w");
    for (int i = 0; i < 50000; ++i) {
        fprintf(file,"AC");
    }
    fprintf(file,"\n");
    for (int i = 0; i < 30000; ++i) {
        fprintf(file,"AC");
    }
    for (int i = 0; i < 10000; ++i) {
        fprintf(file,"AG");
    }
    fprintf(file,"\n");
    fclose(file);
    file = fopen("virus-06.ans","w");
    fprintf(file,"19999\n");
    fclose(file);
    
    
    file = fopen("virus-07.in","w");
    for (int i = 0; i < 50000; ++i) {
        fprintf(file,"AC");
    }
    fprintf(file,"\n");
    for (int i = 0; i < 10000; ++i) {
        fprintf(file,"AC");
    }
    fprintf(file,"GTACACACACACG");
    for (int i = 0; i < 30000; ++i) {
        fprintf(file,"AC");
    }
    fprintf(file,"\n");
    fclose(file);
    file = fopen("virus-07.ans","w");
    fprintf(file,"13\n");
    fclose(file);
    

    file = fopen("virus-08.in","w");
    for (int i = 0; i < 9000; ++i) {
        fprintf(file,"GATTACAGAT");
    }
    fprintf(file,"\n");
    for (int i = 0; i < 10000; ++i) {
        fprintf(file,"GATTACAGAT");
    }
    fprintf(file,"\n");
    fclose(file);
    file = fopen("virus-08.ans","w");
    fprintf(file,"10000\n");
    fclose(file);
    
    
    char str[100002];
    char acids[5] = "GTAC";
    for (int i = 0; i < 100000; ++i) {
        str[i] = acids[rand()%4];
    }
    str[100001] = 0;
    file = fopen("virus-09.in","w");
    fprintf(file,"%s\n",str);
    str[84343] = 'A';
    fprintf(file,"%s\n",str);
    fclose(file);
    file = fopen("virus-09.ans","w");
    fprintf(file,"1\n");
    fclose(file);
    
    
    for (int i = 0; i < 100000; ++i) {
        str[i] = acids[rand()%4];
    }
    str[100001] = 0;
    file = fopen("virus-10.in","w");
    fprintf(file,"%s\n",str);
    for (int i = 20000; i < 25000; ++i) {
        str[i] = acids[rand()%4];
    }
    fprintf(file,"%s\n",str);
    fclose(file);
    file = fopen("virus-10.ans","w");
    fprintf(file,"5000\n");
    fclose(file);
    
}