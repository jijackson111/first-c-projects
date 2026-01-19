#include <stdio.h>

// Define constant for array size
#define MAX_GRADES 5

// Define average calculator and find highest grade functions
float calculateAverage(int grades[], int size);
int findHighest(int grades[], int size);

// Main function
int main() {
	// 1. Array declaration to allocatea contiguous block of memory for 5 integers
	int grades[MAX_GRADES];
	int i;
	printf("--- Student Grade Tracker ---\n");
	
	//2. Input loop
	for (i = 0; i < MAX_GRADES; i++) {
		printf("Enter grade for student %d: ", i + 1);
		scanf("%d", &grades[i]);
	}
	
	// 3. Pass the array to the functions
	float avg = calculateAverage(grades, MAX_GRADES);
	int highest = findHighest(grades, MAX_GRADES);
	printf("\n--Results--\n");
	printf("Average Grade: %.2f\n", avg);
	printf("Highest Grade: %d\n", highest);
	return 0;
}

// Function to calculate average
float calculateAverage(int grades[], int size) {
	int sum = 0;
	int i;
	for (i = 0; i < size; i++) {
		sum = sum + grades[i];
	}
	float avg = (float)sum / size;
	return avg;
}

// Function to find highest grade
int findHighest(int grades[], int size) {
	int highest = 0;
	int i;
	for (i = 0; i < size; i++) {
		if (grades[i] > highest) {
			highest = grades[i];
		} 
	}
	return highest;
}
		

