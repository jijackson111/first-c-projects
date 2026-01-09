# include <stdio.h>
# include <ctype.h>

// Declare functions
void addNums(int x, int y);
void subtractNums(int x, int y);
void multiplyNums(int x, int y);
void divideNums(int x, int y);

int main() {
	// Get user values
	int x;
	int y;
	printf("Type in two numbers and press enter: ");
	scanf("%d %d", &x, &y);
	// User picks function
	char op;
	printf("Enter a for add, s for subtract, m for multiply, d for divide: ");
	scanf(" %c", &op);
	// Call function for chosen operation
	switch (op) {
		case 'a':
			addNums(x, y);
			break;
		case 's':
			subtractNums(x, y);
			break;
		case 'm':
			multiplyNums(x, y);
			break;
		case 'd':
			divideNums(x, y);
			break;
		default:
			printf("%c is an invalid option\n", op);
	}
	return 0;
}

void addNums(int x, int y) {
        int sum = x + y;
        printf("%d + %d = %d\n", x, y, sum);
}

void subtractNums(int x, int y) {
        int diff = x - y;
        printf("%d - %d = %d\n", x, y, diff);
}

void multiplyNums(int x, int y) {
	int product = x * y;
	printf("%d * %d = %d\n", x, y, product);
}

void divideNums(int x, int y) {
	if (y == 0 || x == 0) {
		printf("Error: Cannot divide by zero\n");
	} else { 
		double quotient = (double)x / (double)y;
		printf("%d / %d = %.2f\n", x, y, quotient);
	}
}
