#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *palindrome (char a[],int count);
char *factorial (char a[],int count);
char *reverseString (char a[],int count);
char *stringLength (char a[],int count);
char *armstrong (char a[],int count);
char *power (char a[],int count);
char *compareString (char a[],int count);
char *findMaximum (char a[],int count);
char *linearSearch (char a[],int count);
char *bubbleSort (char a[],int count);
char *mergeSort (char a[],int count);
void partition(float arr[],int low,int high);
void mergeSt(float arr[],int low,int mid,int high);
char *matrixMult (char a[],int count);
char *computation (char a[],int count);

struct {
	const char *functionName;
	char *(*functionPointer)(char* ,int);
} functionList [] = {
	{ "palindrome", palindrome },
	{ "matrixMult", matrixMult },
	{ "factorial", factorial },
	{ "reverseString", reverseString },
	{ "stringLength", stringLength },
	{ "armstrong", armstrong },
	{ "power", power },
	{ "compareString", compareString },
	{ "findMaximum", findMaximum },
	{ "linearSearch", linearSearch },
	{ "bubbleSort", bubbleSort },
	{ "mergeSort", mergeSort },
	{ "computation", computation },
	
};


/* Function to get array from the file */
int main(int argc, char **argv) {
	if(argc < 2)
	{
		printf("Give the filename. Usage: ./a.out filename\n");
		return -1;
	}
	// const char filename[] = "sample.txt"
	char buffer1[20],buffer2[1000000], *ptr;
	char *token,*buffer;
	char *out;
	size_t len=0;
	int i;
	FILE *file = fopen(argv[1], "r");
	if ( file ){
		while(getline(&buffer,&len,file) != -1) //while(fgets(buffer, sizeof buffer,file) != NULL)
		{
			int count=0;
			sscanf(buffer, "%s %[^\n]", buffer1,buffer2);
			// printf("%d--%d\n",strlen(buffer1),strlen(buffer2));
			buffer = strtok(buffer," ");
			ptr = buffer2;
			// printf("%s\n",*ptr);
			// printf("%s__%s\n",buffer1,buffer2);
			while (buffer != NULL)
			{
				// printf ("--%s \n",buffer);
				buffer = strtok(NULL," ");
				count++;
			}
			
			
			for (i = 0; i < (sizeof(functionList) / sizeof(functionList[0])); i++) {
				if (!strcmp(functionList[i].functionName, buffer1)) {
					functionList[i].functionPointer(ptr,count);
				}
			}
		}
		fclose(file);
	}
	else 
	{
		perror(argv[1]);
	}
}


char *palindrome(char a[],int count) {
	printf("Palindrome Function Called..\n"); 
	// sprintf(a,"%s",a);
	// char *x ;
	// x=a;
	// printf("%s",strtok(a," "));
	// const char *x;
	// x=a;
	printf("%s",a);
	size_t i,j;
	// char *output;
	// char str[6] = "abdbaa";
	for(i = 0, j = strlen(a); i < j; i++, j--){
		// printf("%c\n",a[i]);
		if(a[j] != a[i]){
			// sprintf(output,"%s %s",);
			printf("String is NOT palindrome \n"); 
			// x = "String is not Palinderome";
			// output = "String is not pl";
			// output = "asd";
			return ;
		}
	} 

	printf("String is Palindrome.\n");
	return;

}


char *factorial (char a[],int count){
	printf("Factorial Function Called \n");
	int fact=1,no;
	char *token=NULL;
	token = strtok(a," ");
	// printf("%d\n",atoi(token));
	no = atoi(token);
	while(no>1){
		fact=fact*no;
		no--;
	}
	printf("Factorial : %d\n",fact);
}
