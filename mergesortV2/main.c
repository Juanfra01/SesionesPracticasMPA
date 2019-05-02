
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


void merge(int *left, int l_len, int *right, int r_len, int *out)
{
	int i, j, k;
	for (i = j = k = 0; i < l_len && j < r_len; )
		out[k++] = left[i] < right[j] ? left[i++] : right[j++];

	while (i < l_len) out[k++] = left[i++];
	while (j < r_len) out[k++] = right[j++];
}

void recur(int *buf, int *tmp, int len)
{
	int l = len / 2;
	if (len <= 1) return;

	recur(tmp, buf, l);
	recur(tmp + l, buf + l, len - l);

	merge(tmp, l, tmp + l, len - l, buf);
}

void merge_sort(int *buf, int len)
{
	int *tmp = malloc(sizeof(int) * len);
	memcpy(tmp, buf, sizeof(int) * len);

	recur(buf, tmp, len);

	free(tmp);
}

int main(int argc, char *argv[])
{

  int n;
  clock_t ini, final;
  double total;

  if(argc == 1)
   {
        return 0;
    }

char numero[12];
char* p, *q;
for(p = argv[1], q = numero; *p != '\0'; ++p)
{
        if(*p == '.')
        {
                break;
        }
        else
        {
                *q = *p;
                ++q;
        }
}
*q = '\0';
 n = atol(numero);

  int *x = malloc(sizeof(int)* n);

  FILE *inFile;
  inFile = fopen(argv[1], "r" );
  if (!inFile)
   {

    return 0;
   }
  int k;
  for (k = 0; k < n; k++)
   {
	 fscanf(inFile, "%i", &x[k]);

   }
  fclose(inFile);

 ini = clock();
 merge_sort(x, n);
 final=clock();

  total=((double)(final - ini)) / CLOCKS_PER_SEC;
  printf ("%d \t",n);
  printf ("%lf \n", total);

  return 0;
}
