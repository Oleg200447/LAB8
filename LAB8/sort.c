#include<stdio.h>
#include<stdlib.h>
#include"sort.h"

int len(char* str)
{
	int i = 0, n;
	while (*(str + i) != '\0')
	{
		i++;
	}
	n = i;
	return n;
}

int sizeMinWord(char* str)
{
	int min_size_word = 0, size_word = 0, number_word = 0;
	for (int i = 0; i < len(str) + 1; i++)
	{
		if ((*(str + i) >= 'A' && *(str + i) <= 'Z') || (*(str + i) >= 'a' && *(str + i) <= 'z'))
		{
			int j = i;
			while (((*(str + j) >= 'A' && *(str + j) <= 'Z') || (*(str + j) >= 'a' && *(str + j) <= 'z')))
			{
				size_word++;
				j++;
			}
			number_word++;
			if (number_word == 1)
				min_size_word = size_word;
			else {
				if (min_size_word > size_word)
				{
					min_size_word = size_word;
				}
			}
			i = j + 1;
			size_word = 0;
		}
	}
	return min_size_word;
}

void sortVst(char** mas, int size)
{
	char* storer;
	for (int i = 1; i < size; i++)
	{
		int start = i;
		int end = i;
		while (sizeMinWord(*(mas + end)) < sizeMinWord(*(mas + start - 1)))
		{
			if (start - 1 == 0)
			{
				start--;
				break;
			}
			start--;
		}
		storer = *(mas + end);
		while( end > start)
		{
			*(mas + end) = *(mas + end - 1);
			end--;
		}
		*(mas + start) = storer;
	}
}

void showMas(char** mas, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (*(mas + i) != NULL)
		{
			printf("%s", *(mas + i));
			printf("\n       ");
		}
	}
}