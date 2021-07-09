#include <stdio.h>

int a[8];
//int b[8]
int top = -1;

void push(int value) {
	top += 1;
	a[top] = value;
}

int pop() {
	int value;
	
	value = a[top];
	top -= 1;
	return (value);
}

int main() {
	push(1);
	pop();
	return (0);
}
