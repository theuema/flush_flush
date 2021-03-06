#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <sched.h>
#include "../cacheutils.h"

size_t array[128*1024];

void dosomertdscnmiss(size_t* p)
{
  size_t time;
  FILE *fc = fopen("logs/rdtsc_test_user", "ab+");
  assert(fc != NULL);
  fprintf(fc, "rdtsc: %llu\n",time);
  fprintf(fc, "perform cache hit..\n");

  time = rdtsc();
  maccess(p);
  size_t delta = rdtsc() - time;

  fprintf(fc, "delta (rdtsc() - time): %llu\n",delta);
  fclose(fc);
}

void dosomertdscmiss(size_t* p)
{
  size_t time;
  FILE *fc = fopen("logs/rdtsc_test_user", "ab+");
  assert(fc != NULL);
  fprintf(fc, "rdtsc: %llu\n",time);
  fprintf(fc, "perform cache miss..\n");

  flush(p);
  time = rdtsc();
  // generate miss w flush
  maccess(p);
  size_t delta = rdtsc() - time;

  fprintf(fc, "delta (rdtsc() - time): %llu\n",delta);
  fclose(fc);
}

int main(int argc, char** argv)
{
  printf("start\n");
  memset(array,-1,128*1024*sizeof(size_t));
  printf("vguestaddr: %zx", array);
  flush(array);

  FILE *fc = fopen("logs/rdtsc_test_user", "ab+");
  assert(fc != NULL);
  fprintf(fc, "\n");
  fprintf(fc, "-----------> generate misses..\n");
  fclose(fc);
  for (int i = 0; i < 10; ++i)
  {
    dosomertdscmiss(array);
  }
  fc = fopen("logs/rdtsc_test_user", "ab+");
  assert(fc != NULL);
  fprintf(fc, "\n");
  fprintf(fc, "-----------> generate hits..\n");
  fclose(fc);
  for (int i = 0; i < 10; ++i)
  {
    dosomertdscnmiss(array);
  }
  printf(".\n");

return 1;

}
