#include <stdio.h>
#include <string.h>
int main()
{
	char *a[]={"bag","good","This","are","Zoo","park"};
	char *min;
	int i;
	min=a[0];
	for(i=1;i<6;i++)
	  if(strcmp(a[i],min) <0) min=a[i];
	printf("%s\n", min );
	return 0;
}