#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define TABLE_SIZE 100

typedef struct {
    char word[50];
    bool isOccupied;
} Entry;

int hashFunction(char *word) {
    int sum = 0;
    for (int i = 0; i < strlen(word); i++) {
        sum += word[i];
    }
    return sum % TABLE_SIZE;
}

void insertWord(Entry hashTable[], char *word) {
    int hashValue = hashFunction(word);
    int probeCount = 0;
    while (hashTable[hashValue].isOccupied) {
        if (strcmp(hashTable[hashValue].word, word) == 0) {
            printf("%s is already in the dictionary.\n", word);
            return;
        }
        hashValue = (hashValue + 1) % TABLE_SIZE;
        probeCount++;
        if (probeCount >= TABLE_SIZE) {
            printf("Hash table is full. Cannot insert %s.\n", word);
            return;
        }
    }
    strcpy(hashTable[hashValue].word, word);
    hashTable[hashValue].isOccupied = true;
    printf("%s inserted into the dictionary.\n", word);
}

bool searchWord(Entry hashTable[], char *word) {
    int hashValue = hashFunction(word);
    int probeCount = 0;
    while (hashTable[hashValue].isOccupied) {
        if (strcmp(hashTable[hashValue].word, word) == 0) {
            return true;
        }
        hashValue = (hashValue + 1) % TABLE_SIZE;
        probeCount++;
        if (probeCount >= TABLE_SIZE) {
            break;
        }
    }
    return false;
}

int main() {
    Entry hashTable[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i].isOccupied = false;
    }

    char word[50];
    char input[10];

    printf("Spelling check program\n");
    printf("----------------------\n");

    while (1) {
        printf("\nEnter a word (or 'q' to quit): ");
        scanf("%s", input);
        if (strcmp(input, "q") == 0) {
            break;
        }
        strcpy(word, input);
        insertWord(hashTable, word);
    }

    printf("\nSpelling check:\n");
    while (1) {
        printf("\nEnter a word to check (or 'q' to quit): ");
        scanf("%s", input);
        if (strcmp(input, "q") == 0) {
            break;
        }
        strcpy(word, input);
        printf("Is '%s' in the dictionary? %s\n", word, searchWord(hashTable, word) ? "Yes" : "No");
    }

    return 0;
}
