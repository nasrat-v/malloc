/*
** show_alloc_mem.c for malloc in /home/nasrat_v/Dev/rendu/tek2/malloc/PSU_2016_malloc
** 
** Made by Valentin Nasraty
** Login   <valentin.nasraty@epitech.eu>
** 
** Started on  Sun Feb 12 20:55:20 2017 Valentin Nasraty
** Last update Sun Feb 12 23:07:04 2017 Valentin Nasraty
*/

#include "malloc.h"

void		*base_bloc;

void		my_put_nbr(size_t nb)
{
  if (nb >= 10)
    my_put_nbr(nb / 10);
  my_putchar((nb % 10) + '0');
}

void		my_put_hex(size_t nb)
{
  size_t	res;

  if (nb >= 16)
    {
      res = nb % 16;
      nb /= 16;
      my_put_hex(nb);
    }
  else if (nb > 0)
    {
      res = nb % 16;
      nb /= 16;
    }
  if (res > 9)
    my_putchar(res + 'W');
  else
    my_putchar(res + '0');
}

void		show_alloc_mem()
{
  t_bloc	*bloc;

  bloc = base_bloc;
  my_putstr("break : 0x");
  my_put_hex((size_t)sbrk(0));
  my_putchar('\n');
  while (bloc != NULL)
    {
      if (bloc->isFree == false)
	{
	  my_putstr("0x");
	  my_put_hex((size_t)bloc->data);
	  my_putstr(" - ");
	  my_putstr("0x");
	  my_put_hex((size_t)bloc->data + bloc->getSize);
	  my_putstr(" : ");
	  my_put_nbr(bloc->getSize);
	  my_putstr(" bytes\n");
	}
      bloc = bloc->next;
    }
}
