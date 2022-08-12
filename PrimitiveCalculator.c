#include<stdio.h>
#include<stdlib.h>
int min3(int a,int b,int c){
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
int min2(int a,int b){
	if(a<=b)
		return a;
	return b;
}
int main(){
	int n,i,j,n3=-1,n2=-1,*a,*b;
	scanf("%d",&n);
	a=(int*)malloc((n+1)*sizeof(int));
	b=(int*)malloc((n+1)*sizeof(int));
		a[1]=0;
	for(i=2;i<=n;i++){
		if(i%3==0)
			n3=min2(a[i-1],a[i/3]);
		if(i%2==0)
			n2=min2(a[i-1],a[i/2]);
		if(n3==-1&&n2==-1)
			a[i]=a[i-1]+1;
		else if(n3==-1)
			a[i]=n2+1;
		else if(n2==-1)
			a[i]=n3+1;
		else
			a[i]=1+min3(a[i-1],a[i/3],a[i/2]);
		n3=-1;
		n2=-1;
	}
	b[0]=n;
	for(j=1,i=n;1;j++){
		if(i==1)
			break;
		if(a[i]==(a[i-1]+1)){
			b[j]=i-1;
			i=i-1;
			continue;
		}
		if(i%3==0){
		if(a[i]==(a[i/3]+1)){
			b[j]=i/3;
			i=i/3;
			continue;
		}
		}
		if(i%2==0){
		if(a[i]==(a[i/2]+1)){
			b[j]=i/2;
			i=i/2;
			continue;
		}	
		}
	}
	printf("%d\n",a[n]);
	for(j=j-1;j>=0;j--)
	printf("%d ",b[j]);
}
