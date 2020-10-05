#include<stdio.h>
int main(void)
{
    char *language[] = {"aa","bb","cc","dd","ee"  } ;
    char   **q;
    int k ;
    for(k = 0 ; k < 5 ; k++) {
      q= &language[k];
      printf("%s\n", *q);
    }
    return 0;
}

