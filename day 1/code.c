#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "../file/file.h"
char *nums[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
void parse_data(FILE *fp)
{
    char line[256];
    int32_t sum = 0;
    while (fgets(&line, sizeof(line), fp))
    {
        // find the first number
        char *ptr = line;
        int32_t first = -1;
        int32_t second = -1;
        while (*ptr != '\0')
        {
            for (int i = 0; i < 9; i++)
            {
                if (ptr == strstr(ptr, nums[i]))
                {
                    if (first == -1)
                    {
                        first = i + 1;
                    }
                    else
                    {
                        second = i + 1;
                    }
                }
            }
            if (*ptr >= '0' && *ptr <= '9')
            {

                if (first == -1)
                {

                    first = (*ptr - '0');
                }
                else
                {
                    second = (*ptr - '0');
                }
            }
            ptr++;
        }
        if (first != -1 && second != -1)
        {
            sum += first * 10 + second;
        }
        else if (first != -1)
        {
            sum += first * 10 + first;
        }
    }
    printf("sum: %d\n", sum);
}

void main()
{
    FILE *fp = open_file("C:/Users/robertpaananen/aoc/day 1/input.txt");
    parse_data(fp);
}