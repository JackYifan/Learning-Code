#include<stdio.h>
int main(void)
{
    char *language[] = {"BASIC", "FORTRAN", "PROLOG", "JAVA", "C++"  } ;
    char  **q;
    int k ;
    for(k = 0 ; k < 5 ; k++) {
        q=&language[k];
        printf("%s\n", *q);
    }
    return 0;
}
