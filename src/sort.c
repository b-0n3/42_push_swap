#include "push_swap.h"
void *clone_chunk(void *item)
{
    t_chunk *chunk;
    int *ptr;

    if (item == NULL)
        return NULL;
    if ((ptr = malloc(sizeof(int))) == NULL)
        return NULL;
    memcpy(ptr, ((t_chunk *)item)->value, sizeof(int));
    chunk =  new_chunk(ptr, ((t_chunk *)item)->index);
    if (chunk == NULL)
    {
        free(ptr);
        return NULL;
    }
    chunk->chunk = ((t_chunk *)item)->chunk;
    return chunk;
}

void sort_stacks(t_stacks *stacks, t_array_list clone)
{
    t_array_list *clone;

    if (!stacks->a_is_sorted(stacks) && !stacks->a_is_empty(stacks))
    {

    }
    else if (!stacks->a_is_sorted(stacks) && !stacks->a_is_empty(stacks))
    {

    }
}