// gcc -Wall pthreads_example.c -o pthreads_example -lpthread
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

// thread start function:
void *execute_work (void *arg)
{
  int i = *( (int *) arg); // arg: originally a pointer to integer.
          // then it was passed as a pointer to void. This is why we need to typecast again
          // so that it is back as a pointer to integer. Then we get the value pointed by the pointer.

  printf("Thread %d: Started\n", i);  
  printf("Thread %d: Ended\n", i);
  return 0;
}
 
int main(int argc, char* argv[])
{
  int NUM_THREADS;   // number of threads
  pthread_t *thread;  // pointer to a group of threads
  int *thread_args;
  int i, status;
 
  // User indicates the number of threads - Example: ./pthread_example 10
  if (argc!=2) {
    printf("(main) Usage: %s number_of_threads\n",argv[0]);
    exit(-1); }

  NUM_THREADS = atoi(argv[1]);
  if (NUM_THREADS < 1) {
    printf ("(main) Incorrect number of threads!\n"); exit(-1); }  


  thread_args = (int *) calloc (NUM_THREADS, sizeof(int));

  // memory allocation for threads indices
  thread = (pthread_t*) malloc(NUM_THREADS*sizeof(pthread_t));
 
  // Create all the threads one by one
  for (i = 0; i < NUM_THREADS; i++)
  {
    thread_args[i] = i; // creates a unique address for each value of i. This will be the argument
    status = pthread_create (&thread[i], NULL, execute_work, (void *) &thread_args[i] );
    if (status != 0) {
      perror("Can't create thread");
      free (thread); exit (-1); }
  }
  
  // wait for each thread to complete
  for (i = 0; i < NUM_THREADS; i++)
 	pthread_join (thread[i], NULL);
 
  printf("(main) program has ended\n");
 
  free(thread_args);
  free(thread);
 
  return 0;
 
}