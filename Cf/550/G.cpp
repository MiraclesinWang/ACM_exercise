#include<cstdio>
int a[200005];
int end[200005];
int main(){
	int len,tmp1,tmp2,up,down,i;
	bool res=true;
	scanf("%d",&len);
	for(int i=0;i<len;i++){scanf("%d",&a[i]);}
	if(len<=2)res=true;
	else if(a[0]==a[1]){for(int i=0;i<len;i++){end[i]=1;if(a[i]!=a[0])res=false;}}
	else if(a[0]<a[1]){
		tmp1=0;tmp2=1;while(a[tmp1]<a[tmp2]){end[tmp1]=0;tmp1+=1;tmp2+=1;up=a[tmp1-1];down=a[tmp2];}
		for(i=tmp2+1;i<len;i++){
			if(a[i]<down){down=a[i];end[i]='1';}
			else if(a[i]>up){up=a[i];end[i]='0';}
			else{res=false;break;}
		}
	}
	else if(a[0]>a[1]){
		tmp1=0;tmp2=1;while(a[tmp1]>a[tmp2]){end[tmp1]=1;tmp1+=1;tmp2+=1;up=a[tmp2];down=a[tmp1-1];}
		for(i=tmp2+1;i<len;i++){
			if(a[i]<down){down=a[i];end[i]=1;}
			else if(a[i]>up){up=a[i];end[i]=0;}
			else{res=false;break;}
		}
	}
	printf("%s\n",res?"YES":"NO");
	if(res){for(i=0;i<len;i++)printf("%d ",end[i]);}
}
