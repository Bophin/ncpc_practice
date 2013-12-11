/* Sample solution for the Vegetables problem in NCPC 2012 by Andreas Björklund */
/* made into input validator by Lukáš Poláček */
#include <stdio.h>
#include <math.h>
#include <assert.h>
#define MAXW (1000)

int n;
double w[MAXW];
double ratio;

int cmp(const void *a,const void* b)
{
    double da = *(double*)a;
    double db = *(double*)b;
    if (da<db) return 1; else return -1;
}

int main()
{
    int i,j,t,best_cuts,best_cuts2;
    scanf("%lf %d",&ratio,&n);
    for (i=0;i<n;i++) {
        scanf("%lf",&w[i]);
    }

    double ratio2 = ratio + 0.0002;

    qsort(w,n,sizeof(double),cmp);

    best_cuts = best_cuts2 = 1500;
    for (i=0;i<n;i++) {
        for (t=1;(t-1)*(i+1)< best_cuts;t++) {
            double largest = w[i]/t;
            int total_cuts = 0;
            int valid = 1;
            for (j=0;j<n && total_cuts<best_cuts && valid;j++) {
                int cuts = (int)ceil(w[j]/largest);
                valid &= (w[j]/cuts>largest * ratio);
                total_cuts += (cuts-1);
            }
            if (valid && total_cuts<best_cuts) {
                best_cuts = total_cuts;
            }

        }

        for (t=1;(t-1)*(i+1)< best_cuts2;t++) {
            double largest = w[i]/t;
            int total_cuts = 0;
            int valid = 1;
            for (j=0;j<n && total_cuts<best_cuts2 && valid;j++) {
                int cuts = (int)ceil(w[j]/largest);
                valid &= (w[j]/cuts>largest * ratio2);
                total_cuts += (cuts-1);
            }
            if (valid && total_cuts<best_cuts2) {
                best_cuts2 = total_cuts;
            }

        }
    }

    assert(best_cuts == best_cuts2);
    assert(best_cuts <= 500);
    return 42;
}


