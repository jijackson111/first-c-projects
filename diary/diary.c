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
		case 3: addEntry();
		case 4: deleteEntry();
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
		main();
	}
	fclose(fp);
}

// Function to add entry
void addEntry() {
	// Set variables for date and diary entry
	char date[20];
	char content[MAX_LINE];
	// Get user date
	printf("Enter date (YYYY-MM-DD): ");
	scanf("%19s", date);
	clearInputBuffer();
	// Get user diary entry
	printf("Enter your thoughts: ");
	fgets(content, MAX_LINE, stdin);
	// Remove the trailing newline that fgets automatically ads
	content[strcspn(content, "\n")] = 0;
	// Ad input to file
	FILE *fp = fopen(FILENAME, "a");
	if (fp) {
		fprintf(fp, "\n%s: %s", date, content);
		fclose(fp);
		printf("Entry saved\n");
		main();
	}
}

// Function to delete entry
void deleteEntry() {
	// Get the date of the entry the user wants to delete
	char date[20];
	printf("Enter the date you wish to delete: ");
	scanf("%19s", date);
	// Pointers for source file and temporary storage file
	FILE *fp = fopen(FILENAME, "r");
	FILE *temp = fopen("temp.txt", "w");
	// Check files can be accessed
	if (!fp || !temp) {
		printf("Error accessing files \n");
		return;
	}
	// Copy every line except the one that we want to delete to the temp file
	char buffer[MAX_LINE];
	int deleted = 0;
	while (fgets(buffer, MAX_LINE, fp)) {
		if (strncmp(buffer, date, strlen(date)) != 0) {
			fputs(buffer, temp);
		} else {
			deleted = 1;
		}
	}
	// Close the files and delete the temp file
	fclose(fp);
	fclose(temp);
	remove(FILENAME);
	rename("temp.txt", FILENAME);
	// Print success or error message
	if (deleted) printf("Entry removed\n");
	else printf("Entry not found\n");
	main();
}

// Clears buffer
void clearInputBuffer() {
	int c;
	while ((c = getchar()) != '\n' && EOF);
}