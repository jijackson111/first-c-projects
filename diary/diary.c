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
	// Display options and take user choice
	int user_choice;
	printf("\n--- Personal Diary Management System ---\n");
	printf("\nPlease choose from the following options:\n");
	printf("1. Read all entries\n2. Read select entry\n3. Add new entry\n4. Delete entry\n5. Exit\n");
	printf("Enter your selection: ");
	scanf("%d", &user_choice);
	
	// Call function related to user choice
	switch (user_choice) {
		case 1: readAll();
		case 2: selectEntry();
		//case 3: addEntry();
		//case 4: deleteEntry();
		case 5: printf("Exiting program now\n"); exit(0);
		default: printf("Invalid choice.\n");
	}
	return 0;
}

// Function to read whole file
void readAll() {
	FILE *fp = fopen(FILENAME, "r");
	// Check file exists
	if (!fp) {
		printf("No diary file found\n");
		return;
	}
	// Read contents of diary file
	char buffer[MAX_LINE];
	printf("\n--- YOUR DIARY ---\n");
	while (fgets(buffer, MAX_LINE, fp)) {
		printf("%s", buffer);
	}
	// Close file and recall main function
	fclose(fp);
	main();
}

// Function to search for entry by date
void selectEntry() {
	// Get user date
	char date[20];
	printf("Enter date (YYYY-MM-DD): ");
	scanf("%19s", date);
	// Open file
	FILE *fp = fopen(FILENAME, "r");
	if (!fp) return;
	// Search for lines starting with the date
	char buffer[MAX_LINE];
	int found = 0;
	while (fgets(buffer, MAX_LINE, fp)) {
		// Compare start of line with user date
		if (strncmp(buffer, date, strlen(date)) == 0) {
			printf("\nDiary Entry Found: %s", buffer);
			found = 1;
		}
	}
	// Print message if none found and cloe file
	if (!found) {
		printf("No entry exists for that date.\n");
	}
	fclose(fp);
}