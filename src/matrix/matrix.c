#include "matrix.h"

/*
** 0
** 0
** 0
** 1
*/

void    clear_vector(t_vector vec)
{
    vec[0] = 0;
    vec[1] = 0;
    vec[2] = 0;
    vec[3] = 1;
}

/*
** 0 0 0 0
** 0 0 0 0
** 0 0 0 0
** 0 0 0 0
*/

void    clear_matrix(t_mat4 mat)
{
    unsigned char x;
    unsigned char y;

    y = 0;
    while (y < 4)
    {
        x = 0;
        while (x < 4)
        {
            mat[x + 4 * y] = 0;
            x++;
        }
        y++;
    }
}

/*
** 1 0 0 0
** 0 1 0 0
** 0 0 1 0
** 0 0 0 1
*/

void    identity(t_mat4 mat)
{
    unsigned char x;
    unsigned char y;

    y = 0;
    while (y < 4)
    {
        x = 0;
        while (x < 4)
        {
            if (x == y)
                mat[x + (4 * y)] = 1;
            else
                mat[x + (4 * y)] = 0;
            x++;
        }
        y++;
    }
}

void    set(t_mat4 mat, unsigned char x, unsigned char y, float value)
{
    if (x >= 4 || y >= 4)
        return ;
    mat[x + (4 * y)] = value;
}