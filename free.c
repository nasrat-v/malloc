/*
** free.c for free in /home/nasrat_v/rendu/tek2/malloc/PSU_2020_malloc
** 
** Made by Valentin Nasraty
** Login   <valentin.nasraty@epitech.eu>
** 
** Started on  Sun Feb  5 17:28:11 2017 Valentin Nasraty
** Last update Sun Feb 12 14:57:28 2017 Valentin Nasraty
*/

#include "malloc.h"

void		*base_bloc;

void		free(void *ptr)
{
  t_bloc	*bloc;

  trylock_thread();
  if (ptr == NULL || (bloc = get_bloc(ptr)) == NULL)
    {
      unlock_thread();
      return;
    }
  if (bloc->data == ptr && bloc->isFree == false)
    {
      bloc->isFree = true;
      bloc = fusion_free_bloc(bloc);
      if (bloc == base_bloc && bloc->next == NULL)
	{
	  brk((char*)bloc + getpagesize());
	  base_bloc = NULL;
	}
    }
  unlock_thread();
}
