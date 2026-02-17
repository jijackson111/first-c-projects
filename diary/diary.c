#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define macros
#define MAX_LINE 1024
#define FILENAME "entries.txt"

// Declare function prototypes
void readAll();
void selectEntry();
void addEntry();
void deleteEntry();
void clearInputBuffer();

// Main function
int main() {
	int user_choice;
	printf("\n--- Personal Diary Management System ---\n");
	printf("\nPlease choose from the following options:\n");
	printf("1. Read all entries\n2. Read select entry\n3. Add new entry\n4. Delete entry\n5. Exit\n");
	printf("Enter your selection: ");
	scanf("%d", &user_choice);
	printf("You chose: %d", user_choice);
}
