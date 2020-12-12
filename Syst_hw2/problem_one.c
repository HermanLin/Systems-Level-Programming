#include <stdio.h>

int main() {
	int ans;
	int z;
	for (z = 1; z < 1000; z ++) {
		if (((z % 3) == 0) || ((z % 5) == 0)) {
			ans += z;
		}
	}
	printf("The sum of all multiples of 3 and  5 below 1000: %d", ans);
	return 0;
}