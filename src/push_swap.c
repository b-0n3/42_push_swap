#include "push_swap.h"
void print_usage(void)
{
    ft_putstr("usage:\n\t ./push_swap <list of number>\n");
    exit(1);
}
t_bool check_digits(char *item)
{
    int i;
    int signe;

    signe = 0;
    i = 0;
    while (item[i] != '\0')
    {
        if (signe == 0 && item[i] == '-')
        {
            signe = 1;
            i++;
            continue;
        }
        if ((item[i] < '0' || item[i] > '9'))
            return FALSE;
        i++;
    }
    return (i != 0);
}

int *ft_newnb(char *number)
{
    int *ptr;

    ptr = NULL;
    if (number == NULL || check_digits(number))
        return NULL;

}

int main(int argc, char **argv)
{
    t_stacks stacks;
    int nb;

    if (argc < 2)
        print_usage();
    new_stacks(&stacks);
    argc--;
    while (argc > 1)
    {
        if (stacks.stack_a.push(&stacks.stack_a, ft_newnb(argv[argc]), sizeof(int)) == FALSE)
        {
            ft_putstr("error: \n invalid number\n");
            
        }
    }
    stacks.rb(&stacks, TRUE);
}