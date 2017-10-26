/*
** manage_bloc.c for malloc in /home/nasrat_v/rendu/tek2/malloc/PSU_2020_malloc
** 
** Made by Valentin Nasraty
** Login   <valentin.nasraty@epitech.eu>
** 
** Started on  Mon Feb  6 21:23:59 2017 Valentin Nasraty
** Last update Sun Feb 12 16:44:47 2017 Valentin Nasraty
*/

#include "malloc.h"

void		*base_bloc;

t_bloc		*find_free_bloc(t_bloc *bloc, size_t size)
{
  while (bloc != NULL)
    {
      if (bloc->isFree == true && bloc->getSize >= size)
      	return (bloc);
      bloc = bloc->next;
    }
  return (NULL);
}

void            *get_bloc(void *ptr)
{
  if (ptr < sbrk(0) && ptr >= base_bloc)
    return (ptr = (char*)ptr - __HEADER_SIZE__);
  return (NULL);
}
