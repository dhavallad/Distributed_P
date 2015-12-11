#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void isPalindrome(void) { printf("Function Palindrome Called.\n"); }
void matrixmul(void) { printf("Function  Matrix Mul Called\n"); }
void function_c(void) { printf("Funtion Called. No such That Function...\n"); }
void merge_sort(void) { printf("Function Merge Sort Called.\n"); }
void reverse_string(void) { printf("Function Reverse String Called\n"); }

const static struct {
  const char *name;
  void (*func)(void);
} mapping [] = {
  { "palindrome", isPalindrome },
  { "matrixMult", matrixmul },
  { "comp", function_c },
  { "mergeSort", merge_sort },
  { "reverseString", reverse_string },
};

int call_function(const char *name)
{
  int i;

  for (i = 0; i < (sizeof(mapping) / sizeof(mapping[0])); i++) {
    if (!strcmp(mapping[i].name, name) && mapping[i].func) {
      mapping[i].func();
      return 0;
    }
  }

  return -1;
}

/* Function to get array from the file */
int main(int argc, char **argv) {
	if(argc < 2)
	{
		printf("Give the filename. Usage: ./a.out filename\n");
		return -1;
	}
	// const char filename[] = "sample.txt"
	const char s[2] = " ";
	char buffer[BUFSIZ], *ptr;
	char *token;
	FILE *file = fopen(argv[1], "r");
	if ( file ){
		while(fgets(buffer, sizeof buffer,file) != NULL)
		{
			printf("line in buffer........\n");
			// printf("%s\n",buffer);
	
			token = strtok(buffer," ");
			// printf("----%s_%s\n",token);
			call_function(token);
			// printf("Input i/p\n",token);
			token = strtok(NULL," ");
			while (token != NULL)
			{
				printf ("%s\n",token);
				token = strtok(NULL," ");
			}
			printf("--END OF LINE READ.--\n\n\n");
		}
		fclose(file);
	}
	else 
	{
		perror(argv[1]);
	}
}
