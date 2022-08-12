#include<stdio.h>
#include<stdlib.h>
int main(){
	int m,count=0;
	scanf("%d",&m);
	count+=m/10;
	m=m%10;
	count+=m/5;
	count+=m%5;
	printf("%d\n",count);
}
