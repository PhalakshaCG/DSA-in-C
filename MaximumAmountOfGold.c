#include<stdio.h>
#include<stdlib.h>
int max(int a,int b){
	if(a>=b)
		return a;
	return b;
}
int main(){
	int i,j,*w,W,val,n;
	scanf("%d%d",&W,&n);
	w=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		scanf("%d",&w[i]);
	
	int *value[W+1];
	for(int i=0;i<=W;i++)
		value[i]=(int *)malloc((n+1)*sizeof(int));
	for(i=0;i<=n;i++)
		value[0][i]=0;
	for(i=0;i<=W;i++)
		value[i][0]=0;
	
	for(i=1;i<=n;i++)	{
		for(j=1;j<=W;j++){
			value[j][i]=value[j][i-1];
			if(w[i-1]<=j){
				val=value[j-w[i-1]][i-1]+w[i-1];
				if(value[j][i]<val)
					value[j][i]=val;
				}
			}
			}
	printf("%d",value[W][n]);
	}
