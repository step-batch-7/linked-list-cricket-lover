#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void display_list(List_ptr list)
{
  Node_ptr current = list->head;
  while (current != NULL)
  {
    printf("value is %d\n", current->value);
    current = current->next;
  }
  printf("total number of nodes are %d\n", list->count);
}

Node_ptr create_node(int value, Node_ptr next_reference)
{
  Node_ptr new_node = malloc(sizeof(Node));
  if (new_node == NULL)
  {
    return new_node;
  }
  new_node->value = value;
  new_node->next = next_reference;
  return new_node;
}

Status add_to_end(List_ptr list, int value)
{
  Node_ptr new_node = create_node(value, NULL);
  if (new_node == NULL)
  {
    return Failure;
  }
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
  if (new_node == NULL)
  {
    return Failure;
  }
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

  Node_ptr current = list->head;
  for (int i = 1; i < position; i++)
  {
    if (current->next != NULL)
    {
      current = current->next;
    }
  }

  Node_ptr new_node = create_node(value, current->next);
  if (new_node == NULL)
  {
    return Failure;
  }
  current->next = new_node;
  list->count++;
  return Success;
}

Status add_unique(List_ptr list, int value)
{
  Node_ptr current = list->head;
  while (current != NULL && current->value != value)
  {
    current = current->next;
  }
  if (current == NULL)
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
  if (list->count == 1)
  {
    list->last = NULL;
  }

  Node_ptr prev = list->head;
  list->head = list->head->next;
  list->count--;
  free(prev);
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
  Node_ptr prev = NULL;
  Node_ptr current = list->head;
  while (current != list->last)
  {
    prev = current;
    current = current->next;
  }
  list->last = prev;
  list->last->next = NULL;
  list->count--;
  free(current);
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
  if (position == list->count - 1)
  {
    return remove_from_end(list);
  }
  Node_ptr prev = NULL;
  Node_ptr current = list->head;
  for (int i = 0; i < position; i++)
  {
    prev = current;
    current = current->next;
  }
  prev->next = current->next;
  free(current);
  list->count--;
  return Success;
}

Status remove_first_occurrence(List_ptr list, int value)
{
  Node_ptr current = list->head;
  int position = 0;
  while (current != NULL && current->value != value)
  {
    current = current->next;
    position++;
  }
  if (current == NULL)
  {
    return Failure;
  }

  return remove_at(list, position);
}

Status remove_all_occurrences(List_ptr list, int value)
{
  Node_ptr prev = NULL;
  Node_ptr current = list->head;
  int position = 0;
  Status status = Success;
  while (current != NULL)
  {
    if (current->value == value)
    {
      status = remove_at(list, position);
    }
    else
    {
      prev = current;
      position++;
    }
    current = current->next;
  }

  return status;
}

List_ptr create_list()
{
  List_ptr new_list = malloc(sizeof(List));
  if (new_list == NULL)
  {
    return new_list;
  }
  new_list->head = NULL;
  new_list->last = NULL;
  new_list->count = 0;
  return new_list;
}