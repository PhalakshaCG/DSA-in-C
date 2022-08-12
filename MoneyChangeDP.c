#include<stdio.h>
#include<stdlib.h>
int min(int a,int b,int c){
	if(a<=b){
		if(a<=c)
			return a;
		else
			return c;
	}
	else{
		if(b<=c)
			return b;
		else
			return c;
	}
}
int main(){
	int m,i,*a,b;
	scanf("%d",&m);
	a=(int*)malloc((m+1)*sizeof(int));
	a[0]=0;
	if(m>=2)
		a[2]=2;
	if(m>=1)
		a[1]=1;
	if(m>=3)
		a[3]=1;
	if(m>=4)
		a[4]=1;
	for(i=5;i<=m;i++){
		b=min(a[i-1],a[i-3],a[i-4]);
		a[i]=b+1;
	}
	printf("%d\n",a[m]);
}
