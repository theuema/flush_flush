#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <sched.h>
#include "../cacheutils.h"

size_t array[128*1024];

void dosomertdsc(void)
{
  size_t time = rdtsc();
  FILE *fc = fopen("logs/rdtsc_test", "ab+");
  assert(fc != NULL);
  fprintf(fc, "rdtsc: %10zu\n",time);
  fprintf(fc, "array stuff..\n");
  time = rdtsc();
  for (int i = 0; i < 128*1024; ++i)
  {
    size_t read = array[i];
  }
  size_t delta = rdtsc() - time;
  fprintf(fc, "delta (rdtsc() - time): %10zu\n",delta);
  fclose(fc);
}

int main(int argc, char** argv)
{
  printf("start\n");
  memset(array,-1,128*1024*sizeof(size_t));
  for (int i = 0; i < 20; ++i)
  {
    dosomertdsc();
    printf("%d", i);
  }
  printf(".\n");

return 1;

}
