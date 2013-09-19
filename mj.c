#import <stdio.h>
#import <stdlib.h>
#import <string.h>
typedef char C; typedef long I; typedef void V;
typedef struct a{I t,r,d[3],p[2];}* A;
#define P printf
#define R return
#define DO(n,x){I i=0,_n=(n);for(;i<_n;++i){x;}}

I*ma(I n     ) {R(I*)malloc(n*4);}
V mv(I*d,*s,n) {DO(n,d[i]=s[i]);}
I tr(I   r,*d) {I z=1;DO(r,z=z*d[i]);R z;} // total number of cells.
A ar(I t,r,*d) {A z=(A)ma(5+tr(r,d));z->t=t,z->r=r,mv(z->d,d,r);R z;}
V nl(        ) {P("\n");}
V pi(  i     ) {P("%d ",i);}
V pr(A w     ) {pi(0);nl();}
A ev(I*e     ) {R(A)e;}
I nn(C c     ) {A z;if(c<'0'||c>'9')R 0;z=ar(0,0,0);*z->p=c-'0';R(I)z;}
I vb(C c     ) {R 0;}
I*rd(C*s     ) {I a,n=strlen(s),*e=ma(n+1); C c;
                DO(n,e[i]=(a=nn(c=s[i]))?a:(a=vb(c))?a:c);
                e[n]=0;
                R e;}
#define sz 80
main() {C s[sz];while(fgets(s,sz,stdin))pr(ev(rd(s)));}
