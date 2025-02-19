#include <stdio.h>
#include <string.h>
int findSubstring(char str[], char sub[]);

int main() 
{
    char str[100], sub[100];
    printf("Enter main string: ");
    fgets(str, sizeof(str), stdin);
    printf("Enter substring: ");
    fgets(sub, sizeof(sub), stdin);
    str[strcspn(str, "\n")] = '\0';
    sub[strcspn(sub, "\n")] = '\0';
    int index = findSubstring(str, sub);
   
    if (index != -1) 
    {
        printf("Substring found at index: %d\n", index);
    } else 
    {
        printf("Substring not found.\n");
    }
    return 0;
}
int findSubstring(char str[], char sub[]) 
{
    char *pos = strstr(str, sub);
    if (pos != NULL) 
    {
        return pos - str;
    } else 
    {
        return -1;
    }
}
