#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b){
	int temp;
	temp= *a;
	*a=*b;
	*b=temp;
}
int* part3(int a[],int l, int r,int m[]){
	int n=r-l+1;
	int i,j=l,k=l;
	i=l+rand()%n;
	swap(&a[l],&a[i]);
	for(i=l+1;i<=r;i++){
		if(a[i]<a[l]){
			swap(&a[i],&a[k+1]);
			swap(&a[k+1],&a[1+j]);
			k++;
			j++;
			}
		else if(a[i]==a[l]){
		swap(&a[i],&a[k+1]);
			k++;
			}
	}
	swap(&a[l],&a[j]);
	if(l==j)
		j++;
	m[0]=j-1;
	m[1]=k;
	return m;
}
void optquicksort(int a[],int l,int r,int m[]){
	int mh[2];
	if(l>=r)
		return;
	m=part3(a,l,r,m);
	mh[0]=m[0];
	mh[1]=m[1];
	optquicksort(a,l,mh[0],m);
	optquicksort(a,mh[1]+1,r,m);
}
int main(){
	int n,*a,m[2];
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	optquicksort(a,0,n-1,m);
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
}
	
