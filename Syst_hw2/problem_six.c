#include <stdio.h>

int main() {
	int sum;
	int square;
	int ans;
	int z;
	
	for (z = 1; z < 101; z ++) {
		//printf("%d\n", z);
		square += z * z;
		sum += z;
	}
	ans = (sum * sum) - square;
	printf("Difference between the sum of squares and the square of the sum: %d", ans);
	return 0;
}