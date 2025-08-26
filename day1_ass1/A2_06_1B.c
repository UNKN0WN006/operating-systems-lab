/***********************************************************************
 * *
 * * Name: Team 06
 * *  - Team Member 1: Anay Saha (002311001054)
 * *  - Team Member 2: Debarshi Mondal (002311001055)
 * *  - Team Member 3: Sushar Hembram (002311001041)
 * *
 * * Date: 23/07/2025
 * *
 * * Assignment 1B: Environment Variables Handling with getenv() and setenv()
 * *
 * * Description:
 * * This program demonstrates fetching predefined system environment variables using getenv(), and setting new custom environment variables using setenv().
 * * Each team member handled specific variables.
 * *
 * * Input: No runtime input; variable names are hardcoded.
 * * Output: Prints values of environment variables to stdout.
 * *
 * * Compilation (Warning Free):
 * *     gcc A1_06_1B.c
 * *
 * * Execution:
 * *     ./a.out
 * *
 * * Sample Output:
 * *     USER: be2354
 * *     HOME: /home/usr/student/ug/yr23/be2354
 * *     HOST: (null)
 * *     ARCH: x86_64
 * *     DISPLAY: :0
 * *     PRINTER: (null)
 * *     PATH: /usr/local/bin:/usr/bin:/bin
 * *     env set by anay: env1054
 * *     env set by debarshi
 * *     env set by sushar: value_041
 * *
 * ***********************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main() {
char* res;

/************* Team Member 1: Anay Saha *************/
res = getenv("USER");
printf("USER: %s\n", res);
//Output: USER:be1054
res = getenv("HOME");
printf("HOME: %s\n", res);
//Output: HOME: /home/usr/student/ug/yr23/be2354
res = getenv("HOST");
printf("HOST: %s\n", res);
// Anay sets env2
if (setenv("env2", "env1054", 1) != 0) {
	perror("setenv env2 failed");
}
res = getenv("env2");
printf("env set by anay: %s\n", res);

/************* Team Member 2: Debarshi Mondal *************/
res = getenv("ARCH");
printf("ARCH: %s\n", res);
//Output: ARCH:
res = getenv("DISPLAY");
printf("DISPLAY: %s\n", res);
//Output: DISPLAY: 
//Debarshi sets env_deabarshi
if (setenv("env_debarshi", "env_1055", 1) != 0) {
	perror("setenv env_debarshi failed");
}
res=getenv("env_debarshi");
printf("env set by debarshi: %s\n",res);

/************* Team Member 3: Sushar Hembram *************/
res = getenv("PRINTER");
printf("PRINTER: %s\n", res);
//Output: PRINTER:
res = getenv("PATH");
printf("PATH: %s\n", res);
//Output: PATH:
// Sushar sets env_sushar
if (setenv("env_sushar", "value_041", 1) != 0) {
	perror("setenv env_sushar failed");
}
res = getenv("env_sushar");
printf("env set by sushar: %s\n", res);

	return 0;
}
