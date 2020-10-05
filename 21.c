#include<stdio.h>
#include<stdio.h>

int main(){
    int *a,*b;
    int*aa,*bb;
    int n1,n2,i,x;
    a=(int*)malloc(2500001*sizeof(int));
    b=(int*)malloc(2500001*sizeof(int));
    scanf("%d",&n1);
    for(i=1;i<=n1;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&n2);
    for(i=1;i<=n2;i++){
        scanf("%d",&b[i]);
    }
    aa=a+1;bb=b+1;x=1;
    while(x<(n1+n2+1)/2&&aa<=a+n1&&bb<=b+n2){
       
		  if(*aa<*bb){
             aa++;
          }
          else {
             bb++;
          }
          x++;
    }
    if(aa<=a+n1&&bb<=b+n2){
    	if(*aa<*bb)printf("%d",*aa);
    	else printf("%d",*bb);
    }
    while(x<(n1+n2+1)/2&&aa<=a+n1){
    	  aa++;
    	  x++;
    }
    while(x<(n1+n2+1)/2&&bb<=b+n2){
    	  bb++;
    	  x++;
    }
    if(!(aa<=a+n1)){
    	printf("%d",*bb);
    }
    if(!(bb<=b+n2)){
    	printf("%d",*aa);
    }
}