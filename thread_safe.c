/*
** thread_safe.c for malloc in /home/nasrat_v/Mouli/psu356malloc
** 
** Made by Valentin Nasraty
** Login   <valentin.nasraty@epitech.eu>
** 
** Started on  Sun Feb 12 13:05:45 2017 Valentin Nasraty
** Last update Sun Feb 12 19:58:34 2017 Valentin Nasraty
*/

#include "malloc.h"

pthread_mutex_t		mutex = PTHREAD_MUTEX_INITIALIZER;

void			*trylock_thread()
{
  if (pthread_mutex_trylock(&mutex) != 0)
    exit(0);
  return (NULL);
}

void			*unlock_thread()
{
  if (pthread_mutex_unlock(&mutex) != 0)
    exit(0);
  return (NULL);
}
