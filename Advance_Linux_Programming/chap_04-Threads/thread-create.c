#include <pthread.h>
#include <stdio.h>
/* Prints x’s to stderr.
The parameter is unused.
Does not return.
*/
void* print_xs (void* unused)
{
	while (1)
	fputc ('x', stderr);
	return NULL;
}

/* The main program.
*/
int main ()
{
	pthread_t thread_id;
	/* Create a new thread. The new thread will run the print_xs
	function. */
	pthread_create (&thread_id, NULL, &print_xs, NULL);
	/* Print o’s continuously to stderr. */
	while (1)
	fputc ('o', stderr);
	return 0;
}

/*************************************************************
*******************Pthread_create arguments*******************
* A pointer to a pthread_t variable, in which the thread ID of the new thread is stored

* A pointer to a thread attribute object.This object controls details of how the
  thread interacts with the rest of the program. If you pass NULL as the thread
  attribute, a thread will be created with the default thread attributes

* A pointer to the thread function.This is an ordinary function pointer, of this
  type:
  	void* (*) (void*)

* thread argument value of type void* . Whatever you pass is simply passed as
  the argument to the thread function when the thread begins executing