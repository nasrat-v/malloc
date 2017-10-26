/*
** basic_func.c for malloc in /home/nasrat_v/Dev/rendu/tek2/malloc/PSU_2016_malloc
** 
** Made by Valentin Nasraty
** Login   <valentin.nasraty@epitech.eu>
** 
** Started on  Sun Feb 12 23:02:33 2017 Valentin Nasraty
** Last update Sun Feb 12 23:04:42 2017 Valentin Nasraty
*/

#include "malloc.h"

void		my_putchar(char c)
{
  write(1, &c, 1);
}

int		my_strlen(char *str)
{
  int		i;

  i = -1;
  while (str[++i]);
  return (i);
}

void		my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}
