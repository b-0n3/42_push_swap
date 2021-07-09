#include "push_swap.h"

t_chunk *new_chunk(int *value, int index)
{
    t_chunk *chunk;

    if (value == NULL)
        return NULL;
    chunk = NULL;
    if ((chunk = (t_chunk *) malloc(sizeof(t_chunk))) != NULL)
    {
        chunk->value = value;
        chunk->index = index;
        chunk->chunk = 0;
        chunk->print  = &print_chunk;
        chunk->free = &free_chunk;
    }
    return chunk;
}

int		chunk_compare(void *v1, void *v2)
{
    t_chunk *ch1;
    t_chunk *ch2;

    if (v1 == NULL || v2 == NULL)
        return -1;
    ch1 = (t_chunk *) v1;
    ch2 = (t_chunk *) v2;
    if (*(ch1->value) > *(ch2->value))
        return 1;
    if (*(ch1->value) < *(ch2->value))
        return -1;
    return 0;
}

void print_chunk(t_chunk *this)
{
        if (this != NULL)
            ft_putnbr(*(this->value));
}

void	free_chunk(void *this)
{
    if (this != NULL)
    {
        if (((t_chunk *)this)->value != NULL)
            free(((t_chunk *)this)->value);
        free(this);
    }
}