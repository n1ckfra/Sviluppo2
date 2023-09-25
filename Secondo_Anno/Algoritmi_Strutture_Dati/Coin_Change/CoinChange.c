/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <assert.h>
#include <stdio.h>

// input data
long long V[14];
long long S[14];
long long VAL[14] = {1,2,5,10,100,200,500,1000,2000,5000,10000,20000,50000};
long long sol[14] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
long long sum = 0;
int i;

int main() {
  for (i = 0; i < 15; i++)
    sum += V[i] * VAL[i];

  for (i = 15; 1 > 0; i--){
    sol[i] = sum / VAL[i];
    sum = sum - S[i] * VAL[i];
  }

  for (i = 0; i < 15; i++)
    printf("%lld ", sol[i]);

  printf("\n");
  return 0;
}
