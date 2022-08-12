#include<stdio.h>
#include<stdlib.h>
int main(){
	long long int n;
	int rem1,rem2,F=1,F1=1,F2=0,a,b;
	scanf("%lld",&n);
	rem1=n%60;
	rem2=(n+1)%60;
	for(int i=2;i<=rem1;i++){
		F=(F1+F2)%10;
		F2=F1;
		F1=F;
	}
	if(rem1==0)
		F=0;
	a=F%10;
	F=1;
	F1=1;
	F2=0;
	for(int i=2;i<=rem2;i++){
		F=(F1+F2)%10;
		F2=F1;
		F1=F;
	}
	if(rem2==0)
		F=0;
	b=F%10;
	a=a*b;
	a=a%10;
	printf("%d\n",a);
	}
