#include "../file/file.h"
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>
#define num_red 12
#define num_green 13
#define num_blue 14
void main()
{
    FILE *fp = open_file("C:/Users/robertpaananen/aoc/day 2/input.txt");
    if (!fp)
    {
        return;
    }
    char line[256];
    int32_t game_num = 0;
    int32_t sum = 0;

    while (fgets(&line, sizeof(line), fp))
    {
        sscanf(line, "Game %d", &game_num);
        int32_t num_balls = 0;
        int32_t highest_red = 0;
        int32_t highest_green = 0;
        int32_t highest_blue = 0;
        char color[10];
        char *c = &line[8];
        while (*c != '\0')
        {
            if (sscanf(c, "%d %s", &num_balls, &color) == 2)
            {

                if (color[0] == 'r' && num_balls > highest_red)
                {

                    highest_red = num_balls;
                }
                else if (color[0] == 'g' && num_balls > highest_green)
                {

                    highest_green = num_balls;
                }
                else if (color[0] == 'b' && num_balls > highest_blue)
                {

                    highest_blue = num_balls;
                }
                c += strlen(color) + 1;
            }
            else
            {
                c++;
            }
        }
        sum += highest_red * highest_green * highest_blue;
    }
    printf("%d\n", sum);
}
