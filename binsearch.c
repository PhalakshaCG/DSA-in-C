#include<stdio.h>
#include<stdlib.h>
int main(){
	int n,k,i,j,m,l,u,m1;
	unsigned int *a,*b;
	scanf("%d",&n);
	a=(unsigned int *)malloc(n*sizeof(unsigned int));
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&k);
	b=(unsigned int *)malloc(k*sizeof(unsigned int));
	for(i=0;i<k;i++)
		scanf("%d",&b[i]);
	for(i=0;i<k;i++){
		m=n/2;
		l=0;
		u=n-1;
		m1=-1;
		while(1){
			if(b[i]>a[m])
				l=m+1;
			if(b[i]<a[m])
				u=m-1;
			if(b[i]==a[m]){
				printf("%d ",m);
				break;
				}
			m=(l+u)/2;
			if((m==m1)&&(a[m]!=b[i])){
				printf("-1 ");
				break;
				}
			m1=m;
		}
		}
		
	}
			
