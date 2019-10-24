#include<stdio.h>
#define max_row 100
#define max_col 100
float approx (float x);
int main(void)
{
    int m, n, i, j, k, l;
    typedef struct mtrx
    {
        float col[max_col];
    }
    matrix;
    matrix row[max_row];
    printf("Number of Equations: ");
    scanf("%i", &m);
    printf("Number of variables: ");
    scanf("%i", &n);
    n = n + 1;
    float temp[n], cursor, multiplier;
    printf("Enter the augmented matrix: \n");
    for (i = 0; i < m; i ++)
    {
        for (j = 0; j < n; j ++)
        {
            scanf("%f", &row[i].col[j]);
        }
    }
    j = 0;
    int cursor_row = 0, cursor_col = 0;
    while (j < n - 1)
    {
        i = cursor_row;
        while (row[i].col[j] < 0.00001 && row[i].col[j] > -0.00001 && i < m)
        {
            i ++;
        }
        if (i >= cursor_row && i < m)
        {
            cursor = row[i].col[j];
            for (k = 0; k < n; k++)
            {
                temp[k] = row[i].col[k];
                row[i].col[k] = row[cursor_row].col[k];
                row[cursor_row].col[k] = temp[k] / cursor;
            }
            for (k = 0; k < m; k ++)
            {
                if (k != cursor_row)
                {
                    multiplier = row[k].col[j];
                    for (l = j; l < n; l ++)
                    {
                        row[k].col[l] -= multiplier * row[cursor_row].col[l];
                    }
                }
            }
            cursor_row ++;
        }
        cursor_col ++;
        j = cursor_col;
    }
    printf("The row reduced echelon form is: \n");
    for (i = 0; i < m; i ++)
    {
        for (j = 0; j < n; j ++)
        {
            printf("%0.2f     ", approx(row[i].col[j]));
        }
        printf("\n\n");
    }
    return 0;
}
float approx (float x)
{
    if (x > -0.00001 && x < 0.00001)
    {
        return 0;
    }
    else if (x > 0.99999 && x < 1.00001)
    {
        return 1;
    }
    return x;
}


