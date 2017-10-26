/*
** copy.c for copy in /home/nasrat_v/Dev/rendu/tek2/malloc/PSU_2016_malloc
** 
** Made by Valentin Nasraty
** Login   <valentin.nasraty@epitech.eu>
** 
** Started on  Sun Feb 12 16:19:19 2017 Valentin Nasraty
** Last update Sun Feb 12 19:08:25 2017 Valentin Nasraty
*/

#include "malloc.h"

void		copy_data(t_bloc *bloc, t_bloc *new_bloc)
{
  size_t       	i;
  void     	*src;
  void		*dest;

  i = 0;
  src = bloc->data;
  dest = new_bloc->data;
  while ((i * 8) < new_bloc->getSize)
    {
      ((long*)dest)[i] = ((long*)src)[i];
      i += 1;
    }
}

t_bloc		*copy_bloc(t_bloc *bloc, size_t size)
{
  void		*new_ptr;
  t_bloc	*new_bloc;

  unlock_thread();
  if ((new_ptr = malloc(size)) == NULL)
      return (NULL);
  trylock_thread();
  if ((new_bloc = get_bloc(new_ptr)) == NULL)
    return (NULL);
  copy_data(bloc, new_bloc);
  return (new_ptr);
}
