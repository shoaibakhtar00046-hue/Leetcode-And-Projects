#include <stdio.h>

int main()
{
    FILE *fp;

   
    fp = fopen("Feedback.txt", "w");

    if (fp == NULL)
    {
        printf("File opening failed\n");
        return 0;
    }

    
    fprintf(fp, "About the C Programming Feedback\n");

    fprintf(fp, "1. C programming is easy to understand.\n");
    fprintf(fp, "2. The teaching method is good.\n");
    fprintf(fp, "3. Practical examples are helpful.\n");
    fprintf(fp, "4. File handling is an interesting topic.\n");
    fprintf(fp, "5. I would like to learn more programs.\n");

   
    fclose(fp);

  
    fp = fopen("Feedback.txt", "a");

    if (fp == NULL)
    {
        printf("File opening failed\n");
        return 0;
    }

  
    fprintf(fp, "\nOwn Feedback\n");
    fprintf(fp, "Sir  your teaching is very helpful.\n");
    fprintf(fp, "I understand C programming better.\n");

    
    fclose(fp);


    fp = fopen("Feedback.txt", "r");

    if (fp == NULL)
    {
        printf("File opening failed\n");
        return 0;
    }

    
    char buffer[300];

    printf("\n----- Feedback Content -----\n");

    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        printf("%s", buffer);
    }

  
    fclose(fp);

    printf("\n\nFeedback added and displayed successfully.\n");

    return 0;
}