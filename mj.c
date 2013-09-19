#import <stdio.h>
#import <string.h>
#import <stdlib.h>
typedef char C; typedef long I; typedef int B; typedef void V;
typedef struct a{}* A;
#define P printf
#define R return
#define DO(n,x){I i=0,_n=(n);for(;i<_n;++i){x;}}
I*ma(I n){R(I*)malloc(n*4);}
V nl(   ){P("\n");}
V pi(  i){P("%d ",i);}
V pr(A w){pi(0);nl();}
A ev(I*e){R(A)e;}
B nn(C c){R 0;}
B vb(C c){R 0;}
I*rd(C*s){I a,n=strlen(s),*e=ma(n+1); C c;
          DO(n,e[i]=(a=nn(c=s[i]))?a:(a=vb(c))?a:c);
          e[n]=0;
          R e;}
#define sz 80
main(){C s[sz];while(fgets(s,sz,stdin))pr(ev(rd(s)));}
