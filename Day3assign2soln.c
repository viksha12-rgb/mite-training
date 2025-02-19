#include <stdio.h>
#include <string.h>

int countPatternOccurrences(char dna[], char pattern[]) 
{
    int count = 0;
    char *ptr = dna;
    while ((ptr = strstr(ptr, pattern)) != NULL) 
    { 
        count++;
        ptr++; 
    }
    return count;
}
int main() 
{
    char dna[100], pattern[20];
    printf("Enter DNA Sequence: ");
    scanf("%s", dna);
    printf("Enter pattern to search: ");
    scanf("%s", pattern);
    int occurrences = countPatternOccurrences(dna, pattern);
    printf("Pattern found %d time(s) in the DNA sequence.\n", occurrences);
    return 0;
}
