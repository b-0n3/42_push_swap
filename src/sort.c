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


void clone_a_first_chunks_and_sort_it(
    t_stacks *stacks,
    t_array_list *clone
)
{

}

void clone_b_first_chunks_and_sort_it(
    t_stacks *stacks,
    t_array_list *clone
)
{

}

// please pass a valid clone 
void sort_stacks(t_stacks *stacks)
{
    const t_array_list clone;

    new_array_list(&clone ,  10 , sizeof(chunk *));
    if (!stacks->a_is_sorted(stacks) && !stacks->a_is_empty(stacks))
    {
        // TODO: start clone first chunk and sort
        clone_a_first_chunks_and_sort_it(stacks ,&clone);
        clone.free(&clone , &free_chunk);
        sort_stacks(stacks);
    }
    else if (!stacks->a_is_empty(stacks))
    {
        clone_b_first_chunks_and_sort_it(stacks ,&clone);
       clone.free(&clone , &free_chunk);
        sort_stacks(stacks);
    }
}