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
    return (i > 0);
}

int *ft_newnb(char *number)
{
    int *ptr;
    int nb;

    ptr = NULL;
    if (number == NULL || !check_digits(number))
        return NULL;
    nb = atoi(number);
    if ((ptr = (int *) malloc(sizeof(int))) == NULL)
        return NULL;
    memcpy(ptr, &nb, sizeof(int));

    return ptr;
}
void print_nb(int *item)
{
    int *i;

    if (item != NULL)
    {
         i = (int *) item;
       ft_putnbr(*i);
       ft_putstr("\t");
    }
}

void print_stacks(t_stacks stacks)
{
    size_t i;
    size_t j;
    int  max;

    i = stacks.stack_a.index;
    j = stacks.stack_b.index;
    max = j > i ? j : i;
    while (max >= 0)
    {
        i--;
        j--;
        print_nb(stacks.stack_a.get(&stacks.stack_a, i));
        print_nb(stacks.stack_b.get(&stacks.stack_b, i));
        ft_putstr("\n");
        max--;
    }
    ft_putstr("_____\n");
}
int cond(void *item1 , void *item2)
{
    int *nb1 = (int *) item1;
    int *nb2 = (int *) item2;

    if (*nb1 > *nb2)
        return 1;
    if (*nb2 > *nb1)
        return -1;
    return 0;
}
void init_pos(t_pos *pos)
{
    if (pos != NULL)
    {
        pos->index = 0;
        pos->value = NULL;
    }
}
void sort_stacks(t_stacks stacks)
{
    t_pos big;
    size_t i;

    i  = 0;
    init_pos(&pos);
    

}
int main(int argc, char **argv)
{
    t_stacks stacks;
   
    if (argc < 2)
        print_usage();
    new_stacks(&stacks);
    argc--;
    while (argc > 0)
    {
        if (stacks.stack_a.push(&stacks.stack_a, ft_newnb(argv[argc]), sizeof(int)) == FALSE)
        {
            ft_putstr("Error\n");
            stacks.free(&stacks);
        }
        argc--;
    }
    sort_stacks(stacks);
}