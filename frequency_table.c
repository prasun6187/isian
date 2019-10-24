/*Create a text file by typing the following numbers: 1 2 1 2 3 1 2 3 4 5 6 2 4 10 6 7
into it.Write a C program to read this file and print a frequency distribution of the
numbers in the file.*/
#include<stdio.h>
#define MAX 1000
int main(void)
{
    struct frq
    {
        int distinct;
        int count;
    };
    struct frq freq[MAX];
    int i = 0, value[MAX];
    FILE *fp;
    fp = fopen("freq.txt", "a+");
    while (!feof(fp))
    {
        fscanf(fp, "%i", &value[i]);
        i ++;
    }
    int no_of_values = i;
    for (i = 0; i < no_of_values; i++)
    {
        freq[i].count = 0;
    }
    int dist_count = 1, j;
    for (i = 1, freq[0].distinct = value[0], freq[0].count = 1; i < no_of_values; i ++)
    {
        j = 0;
        while (value[i] != freq[j].distinct && j < dist_count)
        {
            j ++;
        }
        if (j == dist_count)
        {
            dist_count ++;
            freq[dist_count - 1].distinct = value[i];
        }
        for (j = 0; j < dist_count; j++)
        {
            if (value[i] == freq[j].distinct)
            {
                freq[j].count ++;
            }
        }
    }
    fprintf(fp, "\n\nValues                       Frequency\n");
    for (i = 0; i < dist_count; i++)
    {
        fprintf(fp, "\n  %i   ----------------------   %i", freq[i].distinct, freq[i].count);
    }
    int sum = 0;
    for (i = 0; i < dist_count; i++)
    {
        sum += freq[i].count;
    }
    fprintf(fp, "\n  Total Count:   -----------  %i", sum);
    fclose(fp);
    return 0;
}
