#include "headers.h"
#include "prompt.h"
#include "initial.h"
#include "input.h"
#include "divide_arg.h"
#include "indiv.h"
#include "global_var.h"
int main()
{
	initial();
	while(chill)
	{
		prompt();
		char* in = input();
		char** args = divide(in);
		indiv(args);
	}
	return 0;
}