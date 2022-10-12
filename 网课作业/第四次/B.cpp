#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	double speed=0,pret=0,nowt,distance=0,nspeed;
	char str[100];
	double h,m,s;
	/*cin.getline(str,100);
	sscanf(str,"%lf:%lf:%lf %lf",&h,&m,&s,&speed);
	pret=h+m/60.0+s/3600.0;*/
	while(cin.getline(str,100)){
		if(strlen(str)<=9){
			sscanf(str,"%lf:%lf:%lf",&h,&m,&s);
			nowt=h+m/60.0+s/3600.0;
			distance+=(nowt-pret)*speed;
			pret=nowt;
			printf("%02d:%02d:%02d %.2f km\n",int(h),int(m),int(s),distance);
		}
		else{
			sscanf(str,"%lf:%lf:%lf %lf",&h,&m,&s,&nspeed);	
			nowt=h+m/60.0+s/3600.0;
			distance+=(nowt-pret)*speed;
			pret=nowt;
			speed=nspeed;			
		}
	}
}
