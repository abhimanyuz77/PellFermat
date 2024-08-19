#include<iostream>
#include"InfInt.h"
#include<time.h>
#include <fstream>

using namespace std;
int main()
{
	InfInt d,x,l,xm,ym,h,m,i,j,xp,yp,f,sq,check,p,q,two,n,cot,r,y=1;
	InfInt xc,yc,a,hc,mc,k,rem,xx,yy,s;
 	InfInt arr[500]={0};
 	int z,pi=1;
 
two=2;
	FILE *stream ;
     if((stream = freopen("output.txt", "w", stdout)) == NULL)
      exit(-1);
    r=0;
	clock_t begin = clock();
		for(d=2;d<1000;d++)  // loop for incrementing values of d
	{
 		for(s=2;s<d;s++)  // loop for ignoring perfect squares
		 {
		 if((s*s)==d)
 			{
			d++;
			break;
			}
 		 }
 		
          
		for(n=1;(n*n)<(d);) //for loop for sqt calc
	    {  
	       n++;
	   	   if((n*n)<=d)
			{
			y=n;
			}
		}
	
	
  	sq=y;
	x=1;
	h=((d*(x*x))-(y*y));

 	 
 	hc=h;
    
	for(j=1;j<20000000&&h!=1;j++)  // for loop which runs the cycles
            {
           
	        
	        xx=xc=x%h;
	        yy=yc=y%h;
			if(xc==1)
				{
				m=h-yc;
				}
			else if (yc==1)
			{
				rem=1;
				 	for(m=1;rem!=0;m++)
				 	rem=(xx*m+yy)%h;
				 	m--;
			}

		else{
			
	    	 rem=0;
				for(z=0;rem!=1;z++)
				{
				arr[z]=hc/xc;
				rem=hc%xc;
				
				hc=xc;
				xc=rem;
				}
				mc=1;
				a=0;
				z--;
				if(z>0)
				{
				
				for(;z>=0;z--)
				{	k=mc;
					mc=a+mc*arr[z];
					a=k;	
				}
			
	        		m=mc*yc;	
           			m=m%h;
				   	check=(x*m+y)%h;
					if(check!=0)
					{
						m=h-m;
					}
					}
				else
				 {
				 	rem=1;
				 	for(m=1;rem!=0;m++)
				 	rem=(xx*m+yy)%h;
				 	m--;
				}	
		}
            
              for(;(m+h)<(sq+1);) // for loop which find value of m
                {
                 m+=h;
	            }
                xp=x; yp=y;
                x=((m*xp)+yp)/h;
                y=((d*xp)+(m*yp))/h;
                h=(d-(m*m))/h;
                hc=h;
            }

    check=((y*y)-d*(x*x));
	if(check==1)
    {
	std::cout<<"\n"<<d<<"\t"<<x<<"\t"<<y;
    }
	else
	{
		p=(two*x*y);
		q=((y*y)+ (d*x*x));
		check=((q*q)-d*(p*p));

		if(check==1)
		std::cout<<"\n"<<d<<"\t"<<p<<"\t"<<q;
	    else
	    std::cout<<"\n******************Error***********************";
	}

}
clock_t end = clock();
double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;


std::cout<<" \nTime= "<<time_spent;
stream = freopen("CON", "w", stdout);
	std::cout<<"\n ***********Success***********";
	std::cout<<" \nTime= "<<time_spent;
	std::cout<<"\nLoops taken = "<<j;
	
	return 0;
}
