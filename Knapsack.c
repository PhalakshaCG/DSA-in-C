#include<stdio.h>
#include<stdlib.h>
int main(){
	double *w,*v,ans=0,W,temp,tempw;
	int n,i,j;
	scanf("%d%lf",&n,&W);
	w=(double*)malloc(sizeof(double)*n);
	v=(double*)malloc(sizeof(double)*n);
	for(int i=0;i<n;i++)
		scanf("%lf%lf",&v[i],&w[i]);
	for(int i=0;i<n;i++)
		v[i]=v[i]/w[i];
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
			if(v[j]<v[j+1]){
				temp=v[j];
				tempw=w[j];
				v[j]=v[j+1];
				v[j+1]=temp;
				w[j]=w[j+1];
				w[j+1]=tempw;
			}}}
	for(i=0;W&&(i<n);i++){
		if(w[i]>=W){
			ans=ans+v[i]*W;
			break;
			}
		ans=ans+v[i]*w[i];
		W=W-w[i];
		}
				printf("%lf",ans);
	}
