#import <stdio.h>
#import <stdlib.h>
#import <string.h>
typedef char C; typedef long I; typedef void _;
typedef struct a{I t,r,d[3],p[2];}* A;
#define P printf
#define R return
#define D I*d
#define S I*s
#define DO(n,x){I i=0,_n=(n);for(;i<_n;++i){x;}}

I*ma(I n      ) { R(I*)malloc(n*4); }
_ mv(  D, S, n) { DO(n,d[i]=s[i]); }
I tr(I    r, D) { I z=1;DO(r,z=z*d[i]); R z; } // total number of cells.
A ar(I t, r, D) { A z=(A)ma(5+tr(r,d));z->t=t,z->r=r,mv(z->d,d,r);R z;}
_ nl(         ) { P("\n");}
_ pi(  i      ) { P("%d ",i);}
_ pr(A w      ) { I r=w->r,*d=w->d,n=tr(r,d); DO(r,pi(d[i]))}
A ev(I*e      ) { R(A)e;}
I nn(C c      ) { A z;if(c<'0'||c>'9')R 0;z=ar(0,0,0);*z->p=c-'0';R(I)z;}
I vb(C c      ) { R 0;}
I*rd(C*s      ) { I a,n=strlen(s),*e=ma(n+1); C c;
                  DO(n,e[i]=(a=nn(c=s[i]))?a:(a=vb(c))?a:c);
                  e[n]=0;
                  R e;}
#define sz 80
main() {C s[sz];while(fgets(s,sz,stdin))pr(ev(rd(s)));}
