
#include <sys/types.h>
#include <pthread.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int COUNTER=2;

void thread(int MaX,int p_threads);
void * primes();
void getVal(int argc,char *argv[]);
void runTime(clock_t start);
//void startTime();

int main(int argc, char *argv[])
{
getVal(argc,argv);
return 0;
}
/*void startTime()
{
  clock_t start;
  start = clock();
     }*/
void runTime(clock_t start)
{
  clock_t end;
  double runTime;
  end = clock();
  runTime = (end - start) / (double) CLOCKS_PER_SEC ;
  printf ("Run time is %lf seconds\n", runTime);
  getchar();   
     }
void getVal(int argc,char *argv[])
{
	int i=1, MaX, p_threads;
	MaX=atoi(argv[i]);
	printf("arg %d: %d\n", i, MaX);
	p_threads=atoi(argv[++i]);
	printf("arg %d: %d\n", i, p_threads);
	printf("The prime numbers are: \n");
	thread(MaX,p_threads);
}


void thread(int MaX, int p_threads)
{

	pthread_t threads[p_threads];
	int rc, i;
    clock_t start;
  start = clock();
	for(i=0;i < p_threads; i++)
	{
		rc = pthread_create(&threads[i], NULL, &primes, (void *)&MaX);
	}
	for(i=0; i< p_threads; i++)
	{
		rc = pthread_join(threads[i], NULL);
	}
	pthread_exit(0);
}

void * primes(void * MaX)
{	
	int  max = *(int *)MaX;
	int  j;
	while(COUNTER != max)
	{
		j = COUNTER;
		COUNTER++;	
		int k = 2, m =0;
		while(k < j)
		{
			if((j%k) == 0)
			{
				m = 1;
			}
			k++;
		}
		if(m == 0)
		{
  if(j==0 || j==1)
  printf("%d is neither a prime nor a composite\n",j);
  else
			printf("%d\n", j);
		}
	}//close while
	runTime(clock_t start);
	return NULL;
}

