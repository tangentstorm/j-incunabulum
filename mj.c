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

// print
_ nl(         ) { P("\n");}
_ pi(  i      ) { P("%d ",i);}
_ pr(A w      ) { I r=w->r,*d=w->d,n=tr(r,d);
                    //P("pr> printing %ld values.\n", n);
                    DO(r,pi(d[i]))         // print dimensions if rank>0
                    DO(n, pi(w->p[i]));    // print values
                    nl();}

// verbs
#define MO(fn) A fn(A w)
#define DY(fn) A fn(A a, A w)
MO(  id){ P("id.\n");  R w;} // id function
DY( nop){ P("nop.\n"); R w;} // no-op (J: "]")

// eval
A st[26];                                     // storage for pronouns
C vt[]="+{~<#,";                                  // verb table
A (*mo[])()={ id,  id,  id,  id,  id,  id,  id},  // monadic
  (*dy[])()={nop, nop, nop, nop, nop, nop, nop};  // dyadic

I qp(I a) { R a>='a'&&a<='z';}          // is it a pronoun?
I qv(I a) { R a<'a';}                   // is it a verb?
A ev(I*e) { I a=*e;
            if(qp(a)){                  // P("ev> pronoun: %c\n", (char)a);
              if(e[1]=='=')
		R st[a-'a']=ev(e+2);    // set
	      a=(I)st[a-'a'];}          // get
            // -- right-to-left recursive evaluator
	    R (qv(a)) ? (*mo[a])(ev(e+1))
            : (e[1])  ? (*dy[e[1]])(a,ev(e+2))
            :           (A)a; }

// read (nouns and verbs)
I nn(C c      ) { A z;if(c<'0'||c>'9') R 0;   // nn only handles 0..9
                    z=ar(0,0,0); *z->p=c-'0'; // create rank 0 array
		    //P("nn> noun: %ld\n", *z->p);
                  R (I)z;}                    // cast A->I and return
I vb(C c      ) { I i=0;for(;vt[i];)if(vt[i++]==c)R i;R 0;}
I*rd(C*s      ) { I a,n=strlen(s),*e=ma(n+1); C c;
                    DO(n,e[i]=(a=nn(c=s[i]))?a // noun? (single digit)
                    :(a=vb(c))?a               // verb? (see vt[])
                    :c);                       // else pronoun (a..z)
                    e[n-1]=0;                  // strip linefeed
                    //P("rd> n: %ld\n", n);
                    //DO(n, P("rd> i: %ld, e[i]: %ld\n", i, e[i]));
                  R e;}
#define sz 99
main() {C s[sz]; DO(26,st[i]=ar(0,0,0))
        while(fgets(s,sz,stdin))pr(ev(rd(s)));}
