#include<stdio.h>
#include<stdlib.h>
void swap(long int a[],long int b[]){
	long int temp1,temp2;
	temp1=a[0];
	temp2=a[1];
	a[0]=b[0];
	a[1]=b[1];
	b[0]=temp1;
	b[1]=temp2;
}
int main(){
	long int **a,*mark,start,end;
	int count=0;
	int n,i,j=-1,k=0;
	scanf("%d",&n);
	mark=(long int *)malloc(sizeof(long int)*n);
	a=(long int**)malloc(sizeof(long int*)*n);
	for(i=0;i<n;i++)
		a[i]=(long int *)malloc(sizeof(long int)*2);
	for(i=0;i<n;i++)
		scanf("%ld%ld",&a[i][0],&a[i][1]);
	//for(i=0;i<count;i++)
		//printf("%ld %ld   ",a[i][0],a[i][1]);
	if(n==0)
	{
		printf("0");
		return 0;
	}
	if(n==1){
		printf("%ld\n",a[0][1]);
		return 0;
	}
	j++;
	int starthere,endhere;
	for(;j<=n-1;){
		start=a[j][0];
		end=a[j][1];
		for(i=j+1;i<n;i++){
		starthere =a[i][0];
		endhere=a[i][1];
			if(start>=a[i][0]&&start<=a[i][1]){
				if(end>a[i][1])
					end=a[i][1];
				if(j<n-1)
				swap(a[i],a[++j]);
				}
			if(a[i][0]<=end&&a[i][1]>=end){
				if(start<a[i][0])
					start=a[i][0];
				if(j<n-1)
				swap(a[i],a[++j]);
				}	
		}
		j++;
	}
	//for(i=0;i<count;i++)
	//	printf("%ld %ld   ",a[i][0],a[i][1]);
	start=a[0][0];
	end=a[0][1];
	for(i=1;i<n;i++){
		if(start>=a[i][0]&&start<=a[i][1]){
			if(end>a[i][1])
					end=a[i][1];
					}
		else if((a[i][0]<=end&&a[i][1]>=end)){
			if(start<a[i][0])
					start=a[i][0];
					}
		else{	
			mark[count]=start;
			count++;
			start=a[i][0];
			end=a[i][1];
		}
		}
	mark[count]=start;
	count++;
	printf("%d\n",count);
	for(i=0;i<count;i++)
		printf("%ld ",mark[i]);
	printf("\n");
}