#include<stdio.h>
#include<stdlib.h>
int pisano(int m){
	int a=0,b=1;
	int F,F1=1,F2=0;
	for(int i=0;i<m*m;i++){
		F=(F1+F2)%m;
		F2=F1;
		F1=F;
		if((F1==1)&&(F2==0))
			return i+1;
	}
}		
int main(){
	long long int m,n,i,p,r;
	long long int F,F1=1,F2=0;
	scanf("%lld%lld",&n,&m);
	p=pisano(m);
	//printf("%d\n",p);
	r=n%p;
	F=1;
	for(i=2;i<=r;i++){
		F=(F1+F2)%m;
		F2=F1;
		F1=F;
	}
	if(r==0)
		F=0;
	printf("%lld",F);
}
