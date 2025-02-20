#include <stdio.h>
#include <ctype.h> 

void countWordsAndLines(char filename[]) 
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) 
    {
        perror("Error opening file");
        return; 
    }
    int lineCount = 0;
    int wordCount = 0;
    char ch;
    int inWord = 0; 

    while ((ch = fgetc(fp)) != EOF) 
    {
        if (ch == '\n') {
            lineCount++;
        }
        if (isspace(ch) || ch == '\n' || ch == '\t') 
        {
            if (inWord) 
            {
                wordCount++;
                inWord = 0; 
            }
        } else 
        {
            inWord = 1; 
        }
    }
    if (inWord) 
    {
        wordCount++;
    }
    printf("Total Lines: %d\n", lineCount);
    printf("Total Words: %d\n", wordCount);
    fclose(fp);
}
int main() 
{
    char filename[100]; 
    printf("Enter filename: ");
    scanf("%99s", filename); 
    countWordsAndLines(filename);
    return 0;
}
