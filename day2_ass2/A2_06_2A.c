/************************************************************************
 * *
 * * Team No. : 06
 * *  - Team Member 1: Anay Saha (002311001054)
 * *  - Team Member 2: Debarshi Mondal (002311001055)
 * *  - Team Member 3: Sushar Hembram (002311001041)
 * *
 * * Date: 30/07/2025
 * *
 * * Assignment 2A: Signal Handling (SIGINT) 
 * *
 * * Description:
 * * This program catches SIGINT using 'signal()' and prevent termination and print a specific message as said in the question.
 * * Team Implementation: After thorough discussion we came into a single decision to write the code in specific manner and using least number of lines and hardcode for the program and then we implemented it.
 * * Input: No runtime input
 * * Output:
 * * (Press Ctrl + C and try going out of the debugger) 
 * * Ha Ha, Not Stopping!!
 * *
 * * Compilation (Warning Free):
 * *     gcc A2_06_2A.c
 * *
 * * Execution:
 * *     ./a.out
 * *
 * ***********************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

// Signal handler function
void sigint_handler(int sig_num) 
{
	printf("\nHa Ha, Not Stopping!!\n");  //Printing the message as said instead of terminating the program
	fflush(stdout);
}

int main() 
{
	if(signal(SIGINT, sigint_handler)==SIG_ERR) 
	{
		perror("Signal registration failed");
		exit(EXIT_FAILURE);
	}
 // Running an infinite loop to pause the "Ctrl + C" to work
	while(1) 
	{
		pause();
	}
	return 0;
}

