#include<stdio.h>
#include<stdlib.h>
int main(){
	long long int i,summ=0,sumn=0,m,n;
	int rem;
	scanf("%lld%lld",&m,&n);
	long long int F=1,F1=1,F2=0;
	F=1;
	rem=m%60;
	for(i=0;i<rem-1;i++){
	summ=(summ+F)%10;
	F=F1+F2;
	F2 = F1;
	F1=F;
	
	}
	//printf("%lld\n",summ);
	F=1;
	F1=1;
	F2=0;
	rem=n%60;
	for(i=0;i<rem;i++){
	sumn=(sumn+F)%10;
	F=F1+F2;
	F2 = F1;
	F1=F;
	
	}
	if(sumn>=summ)
		sumn=sumn-summ;
	else
		sumn=10+sumn-summ;
	printf("%lld",sumn);
}
