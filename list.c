#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void display_list(List_ptr list)
{
  Node_ptr p_walk = list->head;
  while (p_walk != NULL)
  {
    printf("value is %d\n", p_walk->value);
    p_walk = p_walk->next;
  }
  printf("total number of nodes are %d\n", list->count);
}

Node_ptr create_node(int value, Node_ptr next_reference)
{
  Node_ptr new_node = malloc(sizeof(Node));
  new_node->value = value;
  new_node->next = next_reference;
  return new_node;
}

Status add_to_end(List_ptr list, int value)
{
  Node_ptr new_node = create_node(value, NULL);
  if (list->head == NULL)
  {
    list->head = new_node;
  }
  else
  {
    list->last->next = new_node;
  }
  list->last = new_node;
  list->count++;
  return Success;
}

Status add_to_start(List_ptr list, int value)
{
  Node_ptr new_node = create_node(value, list->head);
  if (list->head == NULL)
  {
    list->last = new_node;
  }

  list->head = new_node;
  list->count++;
  return Success;
}

Status insert_at(List_ptr list, int value, int position)
{
  if (position > list->count || position < 0)
  {
    return Failure;
  }
  if (position == 0)
  {
    return add_to_start(list, value);
  }
  if (position == list->count)
  {
    return add_to_end(list, value);
  }

  Node_ptr p_walk = list->head;
  for (int i = 1; i < position; i++)
  {
    if (p_walk->next != NULL)
    {
      p_walk = p_walk->next;
    }
  }

  Node_ptr new_node = create_node(value, p_walk->next);
  p_walk->next = new_node;
  list->count++;
  return Success;
}

Status add_unique(List_ptr list, int value)
{
  Node_ptr p_walk = list->head;
  while (p_walk != NULL && p_walk->value != value)
  {
    p_walk = p_walk->next;
  }
  if (p_walk == NULL)
  {
    return add_to_end(list, value);
  }
  return Success;
}

Status remove_from_start(List_ptr list)
{
  if (list->count == 0)
  {
    return Failure;
  }

  Node_ptr temp = list->head;
  list->head = list->head->next;
  list->count--;
  free(temp);
  return Success;
}

Status remove_from_end(List_ptr list)
{
  if (list->count == 0)
  {
    return Failure;
  }
  if (list->count == 1)
  {
    return remove_from_start(list);
  }
  Node_ptr temp = NULL;
  Node_ptr p_walk = list->head;
  while (p_walk != list->last)
  {
    temp = p_walk;
    p_walk = p_walk->next;
  }
  list->last->next = NULL;
  list->count--;
  free(temp);
  return Success;
}

Status remove_at(List_ptr list, int position)
{
  if (position > list->count || position < 0)
  {
    return Failure;
  }
  if (position == 0)
  {
    return remove_from_start(list);
  }
  if (position == list->count)
  {
    return remove_from_end(list);
  }
  Node *p_walk = list->head;
  Node *temp = p_walk->next;
  for (int i = 1; i < position; i++)
  {
    p_walk = p_walk->next;
    Node *temp = p_walk->next;
  }
  p_walk->next = p_walk->next->next;
  free(temp);
  list->count--;
  return Success;
}

List_ptr create_list()
{
  List_ptr new_list = malloc(sizeof(List));
  new_list->head = NULL;
  new_list->last = NULL;
  new_list->count = 0;
  return new_list;
}