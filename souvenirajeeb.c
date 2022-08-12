#include<stdio.h>
#include<stdlib.h>
int max(int a,int b){
	if(a>=b)
		return a;
	return b;
}
int deletedup(int w1[],int w[],int ans,int sum,int l){
	int i,v;
	if(ans>sum)
		return 0;
	if(ans==sum)
		return ans;
	for(i=l;w[i]<=sum&&ans<=sum;i++){
	v=deletedup(w1,w,ans+w[i],sum,i+1);
	if(v==sum){
		w1[i]=0;
		return v;
	}
	
	}
	return ans;
}
		
	
void sort(int a[],int n){
	int temp,i,j;
	for(i=0;i<n-1;i++)
	for(j=0;j<n-i-1;j++)
		if(a[j]==0){
		temp=a[j];
		a[j]=a[j+1];
		a[j+1]=temp;
		}
}
int count(int a[],int n){
	int i;
	for(i=0;i<n;i++)
		if(a[i]==0)
			return i;
}
int main(){
	int *w1,*w2,i,j,temp,*w,W,sum=0,val,n;
	scanf("%d",&n);
	w=(int *)malloc(n*sizeof(int));
	w1=(int *)malloc(n*sizeof(int));
	w2=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		scanf("%d",&w[i]);
	for(i=0;i<n;i++)
		sum=sum+w[i];
	if(sum%3!=0){
	printf("0\n");
	exit(0);
	}
	W=sum/3;
	int **value;
	value=(int **)malloc((W+1)*sizeof(int *));
	for(i=0;i<=W;i++)
		value[i]=(int *)malloc((n+1)*sizeof(int));
	for(i=0;i<=n;i++)
		value[0][i]=0;
	for(i=0;i<=W;i++)
		value[i][0]=0;
	for(i=0;i<n-1;i++)
	for(j=0;j<n-i-1;j++)
		if(w[j]>w[j+1]){
		temp=w[j];
		w[j]=w[j+1];
		w[j+1]=temp;
		}
	for(i=0;i<n;i++)
		w1[i]=w[i];
	for(i=0;i<n;i++)
		w2[i]=w[i];
	for(i=1;i<=n;i++)	{
		for(j=1;j<=W;j++){
			value[j][i]=value[j][i-1];
			if(w[i-1]<=j){
				val=value[j-w[i-1]][i-1]+w[i-1];
				if(value[j][i]<val){
					value[j][i]=val;
				}
			
			}
			}
			}
	if(value[W][n]!=W){
	printf("0\n");
	exit(0);
	}
	int var;
	var=W-w[n-1];
	deletedup(w1,w,0,var,0);
	w1[n-1]=0;
	w2[n-1]=0;
	deletedup(w2,w,0,var,0);
	if(w[n-1]==W){
		w1[n-1]=0;
		w2[n-1]=0;
	}
	sort(w1,n);
	n=count(w1,n);
	for(i=1;i<=n;i++)	{
		//printf("%d ",w1[i-1]);
		for(j=1;j<=W;j++){
			value[j][i]=value[j][i-1];
			if(w1[i-1]<=j){
				val=value[j-w1[i-1]][i-1]+w1[i-1];
				if(value[j][i]<val){
					value[j][i]=val;
				}
				
			}
			}
			}
	//printf("\n");
	if(value[W][n]!=W){
	printf("0\n");
	exit(0);
	}
	var=W-w1[n-1];
	//printf("%d\n",var);
	deletedup(w2,w1,0,var,0);
	if(w1[n-1]==W){
		w2[n-1]=0;
	}
	sort(w2,n);
	n=count(w2,n);
	for(i=1;i<=n;i++)	{
		//printf("%d ",w2[i-1]);
		for(j=1;j<=W;j++){
			value[j][i]=value[j][i-1];
			if(w2[i-1]<=j){
				val=value[j-w2[i-1]][i-1]+w2[i-1];
				if(value[j][i]<val){
					value[j][i]=val;
				}
				
			}
			}
			}
	//printf("\n");
	if(value[W][n]!=W){
	printf("0\n");
	exit(0);
	}		
	printf("1\n");
	}