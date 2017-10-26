/*
** manage_bloc.c for malloc in /home/nasrat_v/rendu/tek2/malloc/PSU_2020_malloc
** 
** Made by Valentin Nasraty
** Login   <valentin.nasraty@epitech.eu>
** 
** Started on  Mon Feb  6 21:23:59 2017 Valentin Nasraty
** Last update Sun Feb 12 16:56:18 2017 Valentin Nasraty
*/

#include "malloc.h"

void		*base_bloc;

void		create_rest_bloc(t_bloc *bloc, size_t size, int pagesize)
{
  t_bloc	*rest;

  rest = (t_bloc*)((size_t)bloc->data + bloc->getSize);
  rest->getSize = (__ALIGN_ADDR__(size + __HEADER_SIZE__, pagesize)
		   - bloc->getSize - (__HEADER_SIZE__ * 2));
  rest->isFree = true;
  rest->data = (char*)rest + __HEADER_SIZE__;
  rest->next = NULL;
  rest->prev = bloc;
  bloc->next = rest;
}

t_bloc          *extend_heap(t_bloc *last_bloc, size_t size)
{
  t_bloc        *bloc;
  int		pagesize;

  pagesize = getpagesize();
  if ((bloc =
       sbrk(__ALIGN_ADDR__(size + __HEADER_SIZE__, pagesize))) == (void*)-1)
    return (NULL);
  if (last_bloc != NULL)
    {
      last_bloc->next = bloc;
      bloc->prev = last_bloc;
    }
  else
    bloc->prev = NULL;
  bloc->getSize = size;
  bloc->isFree = false;
  bloc->data = (char*)bloc + __HEADER_SIZE__;
  create_rest_bloc(bloc, size, pagesize);
  return (bloc);
}

int		split_bloc(t_bloc *this_bloc, size_t size)
{
  t_bloc	*half_bloc;

  if (this_bloc->getSize <= (size + __HEADER_SIZE__))
    return (1);
  half_bloc = (t_bloc*)((char*)this_bloc + __HEADER_SIZE__ + size);
  half_bloc->getSize = this_bloc->getSize - size - __HEADER_SIZE__;
  half_bloc->next = this_bloc->next;
  half_bloc->prev = this_bloc;
  half_bloc->isFree = true;
  half_bloc->data = (char*)half_bloc + __HEADER_SIZE__;
  this_bloc->getSize = size;
  this_bloc->next = half_bloc;
  this_bloc->isFree = false;
  return (0);
}

t_bloc          *fusion_free_bloc(t_bloc *bloc)
{
  t_bloc	*tmp;

  tmp = bloc;
  if (bloc->prev != NULL && bloc->prev->isFree == true)
    {
      bloc->prev->next = bloc->next;
      bloc->next->prev = bloc->prev;
      bloc->getSize += bloc->prev->getSize + __HEADER_SIZE__;
      tmp = bloc->prev;
    }
  if (tmp->next != NULL && tmp->next->isFree == true)
    {
      tmp->getSize += tmp->next->getSize + __HEADER_SIZE__;
      tmp->next = tmp->next->next;
    }
  return (tmp);
}
