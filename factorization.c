/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factorization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryukim <ryukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 23:54:06 by ryukim            #+#    #+#             */
/*   Updated: 2020/04/02 01:06:46 by ryukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

unsigned int    save;

void            print_error()
{
    printf("error\n");
    exit(1);
}

int             check_no_num(char *argv)
{
    while (*argv)
    {
        if (*argv < '0' || *argv > '9')
            return (1);
        argv++;
    }
    return (0);
}

unsigned int    ft_atoi(char *argv)
{
    int             count;
    unsigned long   ans;

    ans = 0;
    count = 0;
    while (*argv)
    {
        ans = ans * 10 + *argv - '0';
        argv++;
        count++;
    }
    if (ans > 4294967295 || ans < 2 || count > 10)
        print_error();
    return (ans);
}

unsigned int    is_it_prime(unsigned int num)
{
    unsigned int    idx;

    idx = 2;
    while (idx <= sqrt(num))
    {
        if (num % idx == 0)
            return (idx);
        idx++;
    }
    return (0);
}

void            recursive(unsigned int num)
{
    unsigned int    div;

    
    if ((div = is_it_prime(num)))
    {
        if (div != save)
        {
            if (save != 0)
                printf(" ");
            printf("%d", div);
            save = div;
        }
        recursive(num / div);
    }
    else if (num != save)
    {
        if (save != 0)
            printf(" ");
        printf("%d", num);
    }
}

int             main(int argc, char *argv[])
{
    if (argc != 2 || argv[1] == NULL || *(argv[1]) == 0 || check_no_num(argv[1]))
        print_error();
    recursive(ft_atoi(argv[1]));
    printf("\n");
    return (0);
}