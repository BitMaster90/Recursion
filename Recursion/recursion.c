#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void PrintBinary(int);
void PrintBinaryInternal(int, char *, int );
void AppendString(char *, char, int);
void PrintStringPermutation(char *);
void PrintStringPermutationInternal(char*, int, int);
void SwapChar(char *, char *);
int main(void) {
	int Num;
	Num = 5;
	char *ConstStr = "ABCD";
	char Str[100];
	for (int i = 0; i <= strlen(ConstStr); i++) {
		Str[i] = ConstStr[i];
	}
	printf("String copied \n");
	PrintStringPermutation((char *)&Str);
	printf("\n");
	PrintBinary(3);
	return 1;

}

void PrintStringPermutation(char *Str) {
	int Length;
	Length = strlen(Str);
	PrintStringPermutationInternal(Str, 0, Length - 1);
}

void PrintStringPermutationInternal(char *Str, int left, int right) {
	int i;
	if (left == right) {
		printf("%s\n", Str);
		return;
	}
	for (i = left; i <= right; i++) {
		SwapChar((Str + left), (Str + i));
		PrintStringPermutationInternal(Str, left + 1, right);
		SwapChar((Str + left), (Str + i));
	}

}

void SwapChar(char *a, char *b) {
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;

}

void PrintBinary(int Num) {
	char *Digits;
	Digits = (char *)malloc(sizeof(char) * 100);
	Digits[0] = '\0';
	PrintBinaryInternal(Num, Digits, 0);
}

void PrintBinaryInternal(int Num, char *Digits, int index) {
	if (Num == 0) {
		printf("%s \n", Digits);
		return;
	}
	AppendString(Digits, '1',++index);
	PrintBinaryInternal(Num - 1, Digits, index);
	index--;
	AppendString(Digits, '0',++index);
	PrintBinaryInternal(Num - 1, Digits, index);
}

void AppendString(char *Digits, char C, int index) {
	Digits[index - 1] = C;
	Digits[index] = '\0';
}