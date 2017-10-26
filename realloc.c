/*
** realloc.c for realloc in /home/nasrat_v/rendu/tek2/malloc/PSU_2020_malloc
** 
** Made by Valentin Nasraty
** Login   <valentin.nasraty@epitech.eu>
** 
** Started on  Mon Feb  6 17:34:49 2017 Valentin Nasraty
** Last update Sun Feb 12 20:28:29 2017 Valentin Nasraty
*/

#include "malloc.h"

void		*base_bloc;

void		*realloc_func(t_bloc *bloc, void *ptr, size_t size)
{
  if (bloc->data == ptr)
    {
      if (size == bloc->getSize)
	{
	  unlock_thread();
	  return (ptr);
	}
      if (split_bloc(bloc, size) == 1)
      	{
      	  fusion_free_bloc(bloc);
      	  if (split_bloc(bloc, size) == 1)
      	    {
	      if ((ptr = copy_bloc(bloc, size)) == NULL)
		return (malloc(size));
	    }
	}
      unlock_thread();
      return (ptr);
    }
  unlock_thread();
  return (malloc(size));
}

void	       	*realloc(void *ptr, size_t size)
{
  t_bloc       	*bloc;

  trylock_thread();
  if ((long int)size < 0)
    return (unlock_thread());
  size = __ALIGN_ADDR__(size, 16);
  if ((ptr == NULL) || ((bloc = get_bloc(ptr)) == NULL))
    {
      unlock_thread();
      return (malloc(size));
    }
  else if (size == 0)
    {
      unlock_thread();
      free(ptr);
      return (NULL);
    }
  return (realloc_func(bloc, ptr, size));
}
