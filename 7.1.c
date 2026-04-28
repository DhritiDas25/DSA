/*1. Implement a hash function on student SAP-ID and categorize them in to their 10 families based on the last three digits.
Example: Student with SAP-ID 5000423 belongs to family 9 and student with SAP-ID 5000425 belongs to family 2 based
on last three digits.*/
#include <stdio.h>
int getFamily(long sap) {
    int lastThree = sap % 1000;
    return lastThree % 10;
}
int main() {
    long sap1 = 5000423, sap2 = 5000425;
    printf("SAP %ld belongs to Family %d\n", sap1, getFamily(sap1));
    printf("SAP %ld belongs to Family %d\n", sap2, getFamily(sap2));
    return 0;
}