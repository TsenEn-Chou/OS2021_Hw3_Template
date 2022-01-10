#include "function_libary.h"
unsigned int x = 0;


void Function1(void) 
{
    int i,j;
	while (1) 
	{
		i = OS2021_ThreadCreate("random_1","Function2","L",1);
        ((i>0) ? fprintf(stdout,"Created random_1 successfully\n"):
        fprintf(stdout,"Failed to create random_1\n"));
        fflush(stdout);

		j = OS2021_ThreadCreate("random_2","Function2","L",1);
        ((j>0) ? fprintf(stdout,"Created random_2 successfully\n"):
        fprintf(stdout,"Failed to create random_2\n"));
        fflush(stdout);
        
		OS2021_ThreadWaitEvent(3);

		((i>0) ? OS2021_ThreadCancel("random_1"): "");
		((j>0) ? OS2021_ThreadCancel("random_2"): "");
        OS2021_ThreadCancel("f1");
	}
}

void Function2(void) 
{
	int the_num;

	int min = 65408;
	int max = 65410;
	
	while (1) 
	{
        x++;
		if(x == 654090)
		{
			OS2021_ThreadSetEvent(3);
			min = 1;
			max = 10;
		}
		OS2021_TestCancel();
	}
}

void Function3(void)
{
    int odd = 1;
	while(1)
	{
		fprintf(stdout,"Wait event%d.\n",odd);
		fflush(stdout);
		OS2021_ThreadWaitEvent(odd);
        odd +=2;
        if( odd == 9 ){
            while (1);
        }
	}
}

void Function4(void)
{
    int odd = 1;
    int even = 2;
	while(1)
	{
		OS2021_ThreadWaitTime(500);
		fprintf(stdout,"Set even%d.\n",odd);
		fflush(stdout);
		OS2021_ThreadSetEvent(odd);
        odd += 2;
		OS2021_ThreadWaitTime(500);
		fprintf(stdout,"Set even%d.\n",even);
	    fflush(stdout);
        OS2021_ThreadSetEvent(even);
        even += 2;
        if( odd == 9 && even == 10){
            while (1);
        }
	}
}

void Function5(void)
{
    int even = 2;
	while(1)
	{
		fprintf(stdout,"Wait event%d.\n",even);
		fflush(stdout);
		OS2021_ThreadWaitEvent(even);
        even +=2;
        if( even == 10 ){
            while (1);
        }
	}
}

void ResourceReclaim(void)
{
	while (1) 
	{
		OS2021_DeallocateThreadResource();
	}
}
