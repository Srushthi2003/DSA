#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// Hash table structure
struct HashTable {
    int data[SIZE];
    int status[SIZE];  // 0 for empty, 1 for occupied, -1 for deleted
};

// Hash function
int hash(int key) {
    return key % SIZE;
}

// Insert a value into the hash table
void insert(struct HashTable *hashTable, int value) {
    int index = hash(value);
    int i = 1;

    while (hashTable->status[index] == 1) {
        index = (index + i * i) % SIZE;
        i++;
    }

    hashTable->data[index] = value;
    hashTable->status[index] = 1;
}

// Search for a value in the hash table
int search(struct HashTable hashTable, int value) {
    int index = hash(value);
    int i = 1;

    while (hashTable.status[index] != 0) {
        if (hashTable.status[index] == 1 && hashTable.data[index] == value)
            return index;

        index = (index + i * i) % SIZE;
        i++;
    }

    return -1;  // Value not found
}

// Delete a value from the hash table
void delete(struct HashTable *hashTable, int value) {
    int index = search(*hashTable, value);

    if (index != -1) {
        hashTable->status[index] = -1;
        printf("%d deleted from the hash table.\n", value);
    } else {
        printf("%d not found in the hash table.\n", value);
    }
}

// Display the contents of the hash table
void display(struct HashTable hashTable) {
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable.status[i] == 1)
            printf("Index %d: %d\n", i, hashTable.data[i]);
        else
            printf("Index %d: Empty\n", i);
    }
}

int main() {
    struct HashTable hashTable;

    // Initialize hash table
    for (int i = 0; i < SIZE; i++)
        hashTable.status[i] = 0;

    int choice, value;

    do {
        printf("\n======= Hash Table Operations =======\n");
        printf("1. Insert a value\n");
        printf("2. Search a value\n");
        printf("3. Delete a value\n");
        printf("4. Display the hash table\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insert(&hashTable, value);
                printf("%d inserted into the hash table.\n", value);
                break;
            case 2:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                int index = search(hashTable, value);
                if (index != -1)
                    printf("%d found at index %d.\n", value, index);
                else
                    printf("%d not found in the hash table.\n", value);
                break;
            case 3:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                delete(&hashTable, value);
                break;
            case 4:
                display(hashTable);
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (1);

    return 0;
}
