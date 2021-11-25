#include "push_swap.h"

#include <stdio.h>
#include <stdlib.h>

int c[5] = {8, 1, 3, 2, 5};
//int d[5] = {};

void swap(int arr[], int first_value, int second_value) {
	int temp = arr[first_value];
	arr[first_value] = arr[second_value];
	arr[second_value] = temp;
}

int *new_stack(char *arr[], int arrlen) {
	int *stack;
	int i;
	
	stack = malloc(arrlen * sizeof(int));
	i = 0;
	while (arr[i]) {
		stack[i] = ft_atoi(arr[i]);
		i++;
	}
	stack[i] = '\0';
	return (stack);
}

int main(int argc, char *argv[]) {
	int *stack;
	size_t stack_len;
	int i;
	int j;
	
	stack = new_stack(++argv, --argc);
	stack_len = argc;
	printf("stack_len: %ld\n", stack_len);
	i = 0;
	j = 0;
	while (stack_len) {
		while (stack[i+1]) {
			if (stack[i] > stack[i+1]) {
				swap(stack, i, i+1);
			}
			i++;
		}
		i = 0;
		stack_len--;
	}
	while (stack[j]) {
		printf("stack: %d\n", stack[j]);
		j++;
	}
	return (0);
}
