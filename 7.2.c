/*2. Implement a Hash table using arrays. Perform Insert, Delete and Search operations on the hash table
using the above Hash function (S.No.1). Adopt a suitable user-defined exception handling strategy if
collision occurs while inserting data.*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
int hashTable[SIZE];
int getFamily(long sap) {
    int lastThree = sap % 1000;
    return lastThree % 10;
}
void init() {
    for (int i = 0; i < SIZE; i++){
        hashTable[i] = -1;
    }
}
int hashFunction(long sap) {
    return (sap % 1000) % 10;
}
void insert(long sap) {
    int index = hashFunction(sap);
    
    // Exception Handling for Collision
    if (hashTable[index] != -1) {
        printf("EXCEPTION: Collision Detected at Family %d! Cannot insert SAP %ld.\n", index, sap);
        printf("Current occupant: SAP %d\n", hashTable[index]);
    } else {
        hashTable[index] = sap;
        printf("SAP %ld inserted into Family %d.\n", sap, index);
    }
}

void search(long sap) {
    int index = hashFunction(sap);
    if (hashTable[index] == sap)
        printf("SAP %ld found in Family %d.\n", sap, index);
    else
        printf("SAP %ld not found.\n", sap);
}

void delete(long sap) {
    int index = hashFunction(sap);
    if (hashTable[index] == sap) {
        hashTable[index] = -1;
        printf("SAP %ld deleted from Family %d.\n", sap, index);
    } else {
        printf("SAP %ld not found in the table.\n", sap);
    }
}

int main() {
    init();
    
    insert(5000423); // Family 3
    insert(5000425); // Family 5
    insert(5000523); // Collision Exception (both end in 3)
    
    search(5000423);
    delete(5000423);
    search(5000423);
    
    return 0;
}
