/*
** malloc.c for malloc in /home/nasrat_v/rendu/tek2/malloc
**
** Made by Valentin Nasraty
** Login   <valentin.nasraty@epitech.eu>
**
** Started on  Fri Feb  3 08:47:59 2017 Valentin Nasraty
** Last update Sun Feb 12 23:06:31 2017 Valentin Nasraty
*/

#include "malloc.h"

void		*base_bloc = NULL;

void		*malloc(size_t size)
{
  t_bloc       	*this_bloc;

  trylock_thread();
  if ((long int)size < 0)
    return (unlock_thread());
  size = __ALIGN_ADDR__(size, 16);
  if ((this_bloc = find_free_bloc(base_bloc, size)) != NULL)
    {
      if (split_bloc(this_bloc, size) == 1)
	{
	  if ((this_bloc = extend_heap(base_bloc, size)) == NULL)
	    return (unlock_thread());
	}
    }
  else
    {
      if ((this_bloc = extend_heap(base_bloc, size)) == NULL)
	return (unlock_thread());
    }
  if (base_bloc == NULL)
    base_bloc = this_bloc;
  unlock_thread();
  return (this_bloc->data);
}
