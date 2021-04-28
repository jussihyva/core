#define _GNU_SOURCE
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <setjmp.h>

static sigjmp_buf label;
static void segv_hndlr(int Sig) { siglongjmp(label,1); } //safe in this ctx
_Bool is_ro(char volatile *X)
{
    _Bool r = 0;
    struct sigaction old;
    X[0]; //fault now if the target isn't writable
    if(sigsetjmp(label,1))
    {
		r = 1;
		sigaction(SIGSEGV,&old, NULL);
	}
	else
	{
    	sigaction(SIGSEGV,&(struct sigaction)
				{.sa_handler=segv_hndlr}, &old);
    	X[0]=X[0];
	}
    return (r);
}

//example:
int main()
{
    #define PR_BOOL(X) printf(#X"=%d\n", X)
    char bar[]="bar";
    char *baz = strdup("baz");
    static int const static_ro_int = 42;
    int const auto_ro_int = 42;
    PR_BOOL(is_ro("foo")); //1
    PR_BOOL(is_ro(bar)); //0
    PR_BOOL(is_ro(baz)); //0
    PR_BOOL(is_ro((void*)&static_ro_int)); //1
    PR_BOOL(is_ro((void*)&auto_ro_int)); //0
}
