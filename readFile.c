#include"header.h"
/* Function Mapping by struct using function name and pointers to functions. (FUNCTION POINTER concept). */
struct {
	const char *functionName;
	char *(*functionPointer)(char*,int);
} functionList [] = {
	{ "palindrome", functionPalindrome },
	{ "matrixMult", functionMatrixMult },
	{ "factorial", functionFactorial },
	{ "reverseString", functionReverseString },
	{ "stringLength", functionStringLength },
	{ "armstrong", functionArmstrong },
	{ "power", functionPower },
	{ "compareString", functionCompareString },
	{ "findMaximum", functionFindMaximum },
	{ "linearSearch", functionLinearSearch },
	{ "bubbleSort", functionBubbleSort },
	{ "mergeSort", functionMergeSort },
	{ "comp", functionComputation },
	{ "dfs", functionDFS },
	{ "bfs", functionBFS },
	
};

// Main Method.
int main(int argc, char **argv) {
	// If input txt file not given at run time.
	if(argc < 2)
	{
		printf("Give the filename. Usage: ./a.out filename\n");
		return -1;
	}
	char functionName[20],functionInput[1000000], *ptr;
	char *token,*buffer;
	char *out;
	size_t len=0;
	int i;
	FILE *file = fopen(argv[1], "r");
	FILE *output = fopen("outputSerial.txt", "w");
	start();
	if ( file ){
		while(getline(&buffer,&len,file) != -1)
		{
			int tokenCount=0;
			// Split string in functionName & input.
			sscanf(buffer,"%s %[^\n]", functionName,functionInput);
			buffer = strtok(buffer," ");
			while (buffer != NULL)
			{
				buffer = strtok(NULL," ");
				tokenCount++;
			}
			
			/* Calling the function by comaparing the funcationName to struct functionName */
			for (i = 0; i < (sizeof(functionList) / sizeof(functionList[0])); i++) {
				if (!strcmp(functionList[i].functionName, functionName)) {
					out = functionList[i].functionPointer(functionInput,tokenCount);
					fprintf(output, "%s\n",out); // Write to output file.
				}
			}
		}
		fclose(file);
		fclose(output);
		stop();
	}
	else 
	{
		perror(argv[1]);
	}
	printf("Please check ouputSerial.txt file.\n");
}



/* All function defination. */

char *functionPalindrome(char *a,int count) {
	// printf("Palindrome Function Called..\n"); 
	char *outputString;
	size_t i,j;
	for(i = 0, j = strlen(a); i < j; i++, j--){
		if(a[j] != a[i]){
			outputString = "palindrome,0";
			return outputString ;
		}
	} 
	outputString = "palindrome,1";
	return outputString;
}

char *functionFactorial (char *a,int count){
	// printf("Factorial Function Called\n");
	long double factNumber=1.0,number;
	char *outputString = (char*) malloc (10000* sizeof(char));
	char *token=NULL;
	token = strtok(a,"\n");	
	number = atof(token);
	while(number>1){
		factNumber=factNumber*number;
		number--;
	}
	strcat(outputString,"factorial");
	sprintf(outputString,"%s,%.2Lf",outputString,factNumber);
	return outputString;
}

char *functionReverseString (char *a,int count){
	// printf("Function Called reverseString.%s\n",a); 
	char *outputString = (char*) malloc (100000* sizeof(char));
	char *p1, *p2;
	
	for (p1 = a, p2 = a + strlen(a) - 1; p2 > p1; ++p1, --p2)
	{
		*p1 ^= *p2;
		*p2 ^= *p1;
		*p1 ^= *p2;
	}
	strcat(outputString,"reverseString");
	sprintf(outputString,"%s, %s",outputString,a);
	return outputString;
}


char *functionStringLength (char *a,int count){
	// printf("--Function Called stringLength.\n"); 
	char *outputString = (char*)malloc(100000*sizeof(char));
	char *string = strtok(a,"\n");
	int len = strlen(string)-1;
	strcat(outputString,"stringLength");
	sprintf(outputString,"%s,%d",outputString,len);
	return outputString;
}

char *functionArmstrong (char *a,int count){
	// printf("Function Called armstrong\n"); 
	int reminder,num=0;
	int number = atoi(a);
	int temp = number;
	while(number!=0)
	{
		reminder=number%10;
		num+=reminder*reminder*reminder;
		number/=10;
	}
	if(num == temp){
		return "armstrong,1";
	}else{
		return "armstrong,0";
	}
}


char *functionPower (char *a,int count){
	// printf("--Function Called power\n"); 
	char *outputString = (char*)malloc(10000*sizeof(char));
	long double no,power,out=1;
	char *token=NULL;
	token = strtok(a," ");
	no = atof(token);
	token = strtok(NULL," ");
	power = atof(token);
	while(power!=0){
		out=out*no;
		power--;
	}
	// Write to ouputString which going to return.
	strcat(outputString,"power");
	sprintf(outputString,"%s,%Lf",outputString,out);
	return outputString;
}

/*
char *functionCompareString (char *a,int count){
	// printf("%s\n",a);
	char *firstNumber= malloc(10000*sizeof(char));
	char *secondNumber = malloc(100000*sizeof(char));
	// sscanf(a,"%s %s",token1,token2);
	firstNumber = strtok(a," ");
	secondNumber = strtok(NULL," ");
	// printf("%s---\n",firstNumber);
	// printf("%s\n",secondNumber);
	
	while (*firstNumber == *secondNumber) {
		// printf("asdadadadad");
		if (*firstNumber == '\0' || *secondNumber == '\0')
		break;

		firstNumber++;
		secondNumber++;
	}
	free(firstNumber);
	free(secondNumber);
	if (*firstNumber == '\0' && *secondNumber == '\0')
	return "String is same";
	else
	return "String is not same";
	
	
}
*/

char *functionFindMaximum (char *a,int count){
	// printf("--Function Called findMaximum |%d| \n",count); 
	char *outputString = (char*)malloc(10000*sizeof(char));
	double max=0.0;
	char *numberGet=NULL;
	numberGet = strtok(a," ");
	while(numberGet!=NULL){
		if(max<atof(numberGet)){
			max = atof(numberGet);
		}
		numberGet = strtok(NULL," ");
	}
	// Write to ouputString which going to return.
	strcat(outputString,"findMaximum");
	sprintf(outputString,"%s,%lf",outputString,max);
	return outputString;
}

char *functionLinearSearch (char *a,int count){
	// printf("--Function Called linearSearch%s\n",a); 
	int i=1;
	char *outputString = (char*)malloc(1000*sizeof(char));
	strcat(outputString,"linearSearch");
	float no[count-1];
	char *numberList=NULL;
	numberList = strtok(a," ");
	no[0] = atof(numberList);
	numberList = strtok(NULL," ");
	while(numberList!=NULL){
		no[i] = atof(numberList);
		if(no[0]== no[i]){
			sprintf(outputString,"%s,%d",outputString,i);
			return outputString;
		}
		numberList = strtok(NULL," ");
		i++;
	}
	sprintf(outputString,"%s,-1",outputString);// Write to ouputString which going to return.
	return outputString;	
}

char *functionBubbleSort (char *a,int count){
	// printf("--Function Called bubbleSort-- %d\n",count-1);
	size_t i=0,j,k;
	char *outputString = (char*)malloc(1000000*sizeof(char));
	strcat(outputString,"bubbleSort,");
	int arraySize = count-1;
	double arrayList[arraySize],temp;
	char *token=NULL;
	token = strtok(a," ");
	while(token!=NULL){
		arrayList[i] = atof(token);
		token = strtok(NULL," ");
		i++;
	}
	for (i = 1; i < arraySize; i++) {
		for (j = 0; j < arraySize - 1; j++) {
			if (arrayList[j] > arrayList[j + 1]) {
				temp = arrayList[j];
				arrayList[j] = arrayList[j + 1];
				arrayList[j + 1] = temp;
			}
		}
	}
	
	for(i=0;i<arraySize;i++){
		// Write to ouputString which going to return.
		sprintf(outputString,"%s %.2lf",outputString,arrayList[i]);
	}	
	return outputString;
}

char *functionMergeSort (char *a,int count){
	// printf("--Function Called mergeSort %d\n",count); 
	int i=0,arraySize = count-1;
	char *outputString = (char*)malloc(1000000*sizeof(char));
	strcat(outputString,"mergeSort,");
	float no[arraySize];
	char *token=NULL;
	token = strtok(a," ");
	while(token!=NULL){
		no[i] = atof(token);
		token = strtok(NULL," ");
		i++;
	}
	
	mergeSort_Partition(no,0,arraySize-1);

	for(i=0;i<arraySize;i++){
		// Write to ouputString which going to return.
		sprintf(outputString,"%s %.2lf",outputString,no[i]);
	}
	return outputString;
}

void mergeSort_Partition(float arr[],int lowValue,int highValue){
	// printf("--mergeSort_Partition called\n"); 
	int midValue;

	if(lowValue<highValue){
		midValue=(lowValue+highValue)/2;
		mergeSort_Partition(arr,lowValue,midValue);
		mergeSort_Partition(arr,midValue+1,highValue);
		mergeSort_MergeSort(arr,lowValue,midValue,highValue);
	}
}

void mergeSort_MergeSort(float arr[],int lowValue,int midValue,int highValue){

	// printf("mergeSort_MergeSort called\n"); 
	int i,mid,k,low;
	float temp[1000000];

	low=lowValue;
	i=lowValue;
	mid=midValue+1;

	while((low<=midValue)&&(mid<=highValue)){

		if(arr[low]<=arr[mid]){
			temp[i]=arr[low];
			low++;
		}
		else{
			temp[i]=arr[mid];
			mid++;
		}
		i++;
	}

	if(low>midValue){
		for(k=mid;k<=highValue;k++){
			temp[i]=arr[k];
			i++;
		}
	}
	else{
		for(k=low;k<=midValue;k++){
			temp[i]=arr[k];
			i++;
		}
	}

	for(k=lowValue;k<=highValue;k++){
		arr[k]=temp[k];
	}
}


char *functionComputation (){
	// printf("--Function Called computation\n");
	char *outputString = (char*)malloc(10000*sizeof(char));
	strcat(outputString,"comp,");	
	long i,j,k;
	double res;
	for(i=0;i<INT_MAX;i++)
	{
		double a = (double)i;
		double b = 6.4534534;
		double c = 7.86768;
		res += ((b*c) + a)/(a+1) - c - b - a;
	}

	sprintf(outputString,"%s%.2lf",outputString,res); // Write to ouputString which going to return.
	return outputString;

}



char *functionMatrixMult(char *a,int count) { 
	// printf("--Function  Matrix Mul Called\n"); 
	int i=0,arraysize,j=0,k=0;
	double sum = 0.0;
	char *token=NULL,*ptr;
	char *outputString = (char*)malloc(100000*sizeof(char));
	strcat(outputString,"matrixMult,");
	token = strtok(a," ");
	arraysize = atoi(token);
	double *temp = (double *)malloc(arraysize*arraysize*sizeof(double));
	token = strtok(NULL," ");
	for(i = 0; i < arraysize; i++)
	{	
		for ( j = 0; j < arraysize; j++)
		{
			temp[i * arraysize + j] = atof(token);
			token = strtok(NULL," ");
		}
	}	
	
	for(i = 0; i < arraysize; i++)
	{	
		for ( j = 0; j < arraysize; j++)
		{
			sum = 0.0;
			for(k = 0; k < arraysize; k++)
			{
				sum +=  temp[i * arraysize + k] * temp[k * arraysize + j];
			}
			sprintf(outputString,"%s %.2lf",outputString,sum); // Write to ouputString which going to return.
		}
	}	
	
	free(temp);
	return outputString;
}