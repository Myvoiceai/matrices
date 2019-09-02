#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int main()
{
  static int m, n, p, q, c, d, k, sum = 0;
  static int first[1000][1000], second[1000][1000], multiply[1000][1000];
  static int my_array[1000];
  time_t t;

   /* Intializes random number generator */
   srand((unsigned) time(&t));
 
  /* populate array with random numbers */
  int i;
  for (i = 0; i < 1000; i++) {
    my_array[i] = rand() % 10;
  }

char buff[20];
time_t now = time(NULL);

  printf("Enter number of rows and columns of first matrix\n");
  scanf("%d", &m);
  printf("Matrices will be %d\n", m);
 
  for (c = 0; c < m; c++)
    for (d = 0; d < n; d++)
      scanf("%d", &first[c][d]);
 
  /* populate first matrix */
  for(c=0; c < m; c++) {
   for(d = 0; d < m; d++) {
     first[c][d] = my_array[d]; 
   }
  }

  /* populate second matrix */
  for(c = 0; c < m; c++) {
    for(d = 0; d < m; d++) {
      second[c][d] = my_array[d];
    } 	
  }

  /* calculate */
  // string time out here
  now = time(NULL);
  strftime(buff, 20, "%Y-%m-%d %H:%M:%S", localtime(&now));
  printf ("%s %s\n", buff, "Start calculation occurred now");

  for (c = 0; c < m; c++) {
      for (d = 0; d < m; d++) {
        for (k = 0; k < m; k++) {
          sum = sum + first[c][k]*second[k][d];
        }
 
        multiply[c][d] = sum;
        sum = 0;
      }
    }
    for (c = 0; c < m; c++) {
      for (d = 0; d < m; d++) {
        for (k = 0; k < m; k++) {
          sum = sum + first[c][k]*second[k][d];
        }
 
        multiply[c][d] = sum;
        sum = 0;
      }
    }
/* 
    printf("Product of the matrices:\n");
 
    for (c = 0; c < m; c++) {
      for (d = 0; d < m; d++)
        printf("%d\t", multiply[c][d]);
 
      printf("\n");
    }
*/
  // string time out here
  now = time(NULL);
  strftime(buff, 20, "%Y-%m-%d %H:%M:%S", localtime(&now));
  printf ("%s %s\n", buff, "Stop calculation occurred now");
  return 0;
}

