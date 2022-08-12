#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
	char a[100],b[100];
	int i,j,k,la,lb,d;
	scanf("%s%s",a,b);
	la=strlen(a);
	lb=strlen(b);
	int e[la+1][lb+1];
	for(i=0;i<=la;i++)
		e[i][0]=i;
	for(i=0;i<=lb;i++)
		e[0][i]=i;
	for(i=1;i<=la;i++){
		for(j=1;j<=lb;j++){
			d=min(e[i-1][j-1],e[i][j-1],e[i-1][j]);
			if(d==e[i-1][j-1])
				if(a[i-1]==b[j-1]){
					e[i][j]=d;
					continue;
				}
			e[i][j]=d+1;
			}}
	printf("%d\n",e[la][lb]);
}
			
		
	
