#include<stdio.h>
#include<stdlib.h>
int main(){
	int d,f,n,o=0,i,lr=0,t=0;
	int *ptr;
	scanf("%d%d%d",&d,&f,&n);
	ptr=(int *)malloc((n+1)*sizeof(int));
	for(i=0;i<n;i++)
		scanf("%d",&ptr[i]);
	ptr[i]=d;
	while(1){
		for(i=0;((ptr[i]-lr))<=f&&(i<n+1);i++);
		if(ptr[i-1]==d&&(ptr[i-1]-lr)<=f){
			break;
			}
		if(ptr[i-1]==lr){
			printf("-1\n");
			exit(0);
			}
		lr=ptr[i-1];
		o++;
		}
	printf("%d\n",o);
}	
	
