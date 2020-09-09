#include "headers.h"
#include "prompt.h"
#include "initial.h"
#include "input.h"
#include "divide_arg.h"
#include "indiv.h"

int main()
{
	initial();
	//printf("yahan pe2");
	//chdir("new");
	while(1)
	{
		prompt();
	//	printf("yahan pe3");
		char* in = input();
	//	printf("%s mai ninja hattori aa gya hu",in);
	//	printf("yahan pe4\n");
		char** args = divide(in);
	//	printf("yahan pe5\n");
		indiv(args);
	}
	return 0;
}