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
    if (nb >= INT32_MAX || nb <= INT32_MIN)
        return NULL;
    if ((ptr = (int *) malloc(sizeof(int))) == NULL)
        return NULL;
    memcpy(ptr, &nb, sizeof(int));

    return ptr;
}
void print_nb(t_chunk *item)
{
   

    if (item != NULL)
    {
       item->print(item);
      
    }
}

void print_stacks(t_stacks stacks)
{
    size_t i;
    size_t j;
    int  max;

    i = stacks.stack_a.index ;
    j = stacks.stack_b.index ;
    max = j > i ? j : i;
  
    while (max >= 0)
    {
        i--;
        j--;
        print_nb(stacks.stack_a.get(&stacks.stack_a, i));
         ft_putstr(" \t\t\t");
        print_nb(stacks.stack_b.get(&stacks.stack_b, j));
        ft_putstr("\n");
        max--;
    }
    ft_putstr("_____\n");
}



void printnb(void *item)
{
    int *i;

    i = (int *) item;
    printf("%d\n", *i);
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
        if (stacks.stack_a.push(&stacks.stack_a,
         new_chunk(ft_newnb(argv[argc]), stacks.stack_a.index)
         , sizeof(t_chunk *)) == FALSE)
        {
            ft_putstr("Error\n");
            stacks.free(&stacks);
            exit(1);
        }
        argc--;
    }
    // 1 2 3 5 4 87 5
    // sort_stacks(stacks);
  //  print_stacks(stacks);
     sort_stacks(&stacks);
}