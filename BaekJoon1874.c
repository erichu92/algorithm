#include <iostream>
#include <stdio.h>
using namespace std;

int main() {

	int n; // number of inputs
	cin >> n;
	
	int* stack = new int[n]; // make size n stack
	int top = 0; // top index of the stack
	
	for (int i = 0; i < n; i++) { // Initialize stack
		stack[i] = 0;
	}

	char* output = new char[2 * n]; // output array
	int index = 0; // index of output array
	
	int max = 0; // stack's maximum value

	for (int i = 0; i < n; i++) { // get inputs
		int k;
		cin >> k;

		if (max <= k) { // when input is larger than stack's maximum value
			int iter_num = k - max; // iter_num is how many times we push
			for (int j = 0; j < iter_num; j++) { // push
				stack[top++] = ++max;
				output[index++] = '+'; // + means push
			}

			{
				stack[--top] = 0; // pop
				output[index++] = '-'; // - means pop
			}
		}

		else {
			if (stack[top - 1] == k) { // if next input == stack's top value
				stack[--top] = 0;
				output[index++] = '-';
			}
			else { // else we can't make that sequence
				printf("NO\n");
				return 0;
			}
		}
	}

	for (int i = 0; i < 2*n; i++) { // print the output
		printf("%c\n", output[i]);
	}
}
