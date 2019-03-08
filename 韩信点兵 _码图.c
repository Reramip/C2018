#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int n, num, counter;
	scanf("%d", &n);
	int *length = (int*)malloc(sizeof(int)*n);
	int *last = (int*)malloc(sizeof(int)*n);
	for (register int i = 0; i < n;i++) {
		scanf("%d%d", &length[i], &last[i]);
	}

	for (num = 1;; num++) {
		counter = 0;
		for (register int i = 0; i < n; i++) {
			if (num%length[i] != last[i]) break;
			counter++;
		}
		if (counter == n) {
			printf("%d\n", num);
			break;
		}
	}

	free(length);
	free(last);
	system("pause>nul echo");
	return 0;
}
