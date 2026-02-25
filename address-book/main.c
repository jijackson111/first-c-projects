#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define macros
#define MAX_LINE 1024
#define FILENAME "contacts.csv"
#define TABLE_SIZE 100

// Function prototypes
void buildTable();

// Define data structure for contact info
typedef struct Contact {
    char name[100]; // Key: "First Last"
    char phone[20];
    char email[50];
    char postcode[10];
    struct Contact *next; // Pointer to chain to next contact
} Contact;

// Array of pointers to Contact structs (Global Table)
Contact *hashTable[TABLE_SIZE] = {NULL};

// Hash function (string to index)
unsigned int hash(char *key) {
    unsigned int value = 0;
    while (*key) { // Keep the loop going until the null terminator is hit at the end of the string
        value = value * 31 + *key++;
    }
    return value % TABLE_SIZE;
}

// Main function
int main() {
    buildTable();
    printf("Hash table successfully created in memory\n");
    viewAllContacts();
    return 0;
}

// Function to build hash table
void buildTable() {
    // Set file pointer and line buffer
    FILE *fp = fopen(FILENAME, "r");
    char line[MAX_LINE];
    // Loop through
    while (fgets(line, sizeof(line), fp)) {
        line[strcspn(line, "\n")] = 0; // Remove trailing newline
        // Parse CSV columns into pointer
        char *fName = strtok(line, ",");
        char *lName = strtok(NULL, ",");
        char *phone = strtok(NULL, ",");
        char *email = strtok(NULL, ",");
        char *postcode = strtok(NULL, ",");
    // Create new hash table entry if all columns aer found
    if (fName && lName && phone && email && postcode) {
        Contact *newEntry = malloc(sizeof(Contact));
        // Format the key and copy the data over
        sprintf(newEntry->name, "%s %s", fName, lName);
        strcpy(newEntry->phone, phone);
        strcpy(newEntry->email, email);
        strcpy(newEntry->postcode, postcode);
        // Find the index and insert at the head of the list and link them together
        unsigned int index = hash(newEntry->name);
        newEntry->next = hashTable[index];
        hashTable[index] = newEntry;
    }
    }
    fclose(fp);
}
