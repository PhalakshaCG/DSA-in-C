#include<stdio.h>
#include<stdlib.h>
int max(int a,int b){
	if(a>=b)
		return a;
	return b;
}
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
	int *w1,weight,i,j,temp,*w,W,sum=0,**val,n,value,m[2];
	scanf("%d",&n);
	w=(int *)malloc(n*sizeof(int));
	w1=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		scanf("%d",&w[i]);
	optquicksort(w,0,n-1,m);
	for(i=0;i<n;i++){
		w1[i]=w[i];
		sum=sum+w[i];
	}
	if(sum%3!=0){
	printf("0\n");
	exit(0);
	}
	W=sum/3;
	val=(int **)malloc((n+1)*sizeof(int *));
	for(i=0;i<=n;i++)
		val[i]=(int *)malloc((W+1)*sizeof(int));
	for(i=0;i<=W;i++)
		val[0][i]=0;
	for(i=0;i<=n;i++)
		val[i][0]=0;
	for(i=1;i<=n;i++){
		for(j=1;j<=W;j++){
			val[i][j]=val[i-1][j];
			if(w[i-1]<=j){
				value=val[i-1][j-w[i-1]]+w[i-1];
				if(value>val[i][j])
					val[i][j]=value;
				}
			}
		}
	if(val[n][W]!=W){
	printf("0\n");
	exit(0);
	}
	weight = W;
	value=val[n][W];
	for(i=n;i>0;i--){
		if(value==val[i-1][weight-w[i-1]]+w[i-1]){
			w1[i-1]=0;
			value=value-w[i-1];
			weight=weight-w[i-1];
			}
		}
	sort(w1,n);
	n=count(w1,n);
	for(i=1;i<=n;i++){
		for(j=1;j<=W;j++){
			val[i][j]=val[i-1][j];
			if(w1[i-1]<=j){
				value=val[i-1][j-w1[i-1]]+w1[i-1];
				if(value>val[i][j])
					val[i][j]=value;
				}
			}
		}
	if(val[n][W]!=W){
	printf("0\n");
	exit(0);
	}
	printf("1\n");
}
			
	
