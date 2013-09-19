#import <stdio.h>
typedef char C;
#define P printf
#define sz 80
main() {C s[sz];while(fgets(s,sz,stdin))P("%s",s);}
