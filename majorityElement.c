#include<stdio.h>
#include<stdlib.h>
int majority(int a[],int n,int start,int end){
	int l,r,m,count=0;
	if(n==1)
		return a[start];
	if(n%2)
		m=a[start + n/2];
	l=majority(a,n/2,start,start+n/2-1);
	r=majority(a,n/2,end-n/2+1,end);
	
	if(l==-1&&r==-1){
		if(m==-1)
			return -1;
		
		for(int i=start;i<=end;i++)
			if(a[i]==m)
				count++;
	if(count>n/2)
		return m;
	}
	count=0;
	if(n==2){
		if(l==r)
			return l;
		else
			return -1;
		}
	if(l!=-1){
		for(int i=start;i<=end;i++)
			if(a[i]==l)
				count++;
	if(count>n/2)
		return l;
		}
	count =0;
	if(r!=-1){
		for(int i=start;i<=end;i++)
			if(a[i]==r)
				count++;
	if(count>n/2)
		return r;
		}
	return -1;
	}
int main(){
	int n,*a;
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	if(majority(a,n,0,n-1)==-1)
		printf("0");
	else
		printf("1");
}
