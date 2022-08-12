#include<stdio.h>
#include<stdlib.h>
int main(){
	int *a,*b,temp;
	int n,i,j;
	long long int sum=0;
	scanf("%d",&n);
	a=(int*)malloc(sizeof(int)*n);
	b=(int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&b[i]);
	for(i=0;i<n-1;i++)
		for(j=0;j<n-1-i;j++)
			if(a[j]>a[j+1]){
			temp=a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
			}
	for(i=0;i<n-1;i++)
		for(j=0;j<n-1-i;j++)
			if(b[j]>b[j+1]){
			temp=b[j];
			b[j]=b[j+1];
			b[j+1]=temp;
			}
	for(int i=0;i<n;i++)
		sum=sum+(long long)a[i]*b[i];
	printf("%lld",sum);
}
