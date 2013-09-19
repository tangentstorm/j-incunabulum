#import <stdio.h>
typedef char C; typedef long I; typedef void V;
typedef struct a{}* A;
#define P printf
#define R return
V nl(   ){P("\n");}
V pi(  i){P("%d ",i);}
V pr(A w){pi(0);nl();}
A ev(I*e){R(A)e;}
I*rd(C*s){R 0;}
#define sz 80
main(){C s[sz];while(fgets(s,sz,stdin))pr(ev(rd(s)));}
