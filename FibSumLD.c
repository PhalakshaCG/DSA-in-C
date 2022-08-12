#include<stdio.h>
#include<stdlib.h>
int main(){
	long long int i,sum=0,n;
	int rem;
	scanf("%lld",&n);
	long long int F,F1=1;
	F=0;
	rem=n%60;
	for(i=1;i<=rem;i++){
	long long F2 = F1;
	F1=F;
	F=F1+F2;
	sum=sum+F;
	}
	printf("%lld",sum%10);
}
