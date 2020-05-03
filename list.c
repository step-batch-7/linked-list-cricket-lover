#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void display(List_ptr list)
{
  Prev_Current_Pair node_pair;
  node_pair.current = list->head;
  while (node_pair.current != NULL)
  {
    printf("value is %d\n", node_pair.current->value);
    node_pair.current = node_pair.current->next;
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

  Prev_Current_Pair node_pair;
  node_pair.current = list->head;
  for (int i = 1; i < position; i++)
  {
    if (node_pair.current->next != NULL)
    {
      node_pair.current = node_pair.current->next;
    }
  }

  Node_ptr new_node = create_node(value, node_pair.current->next);
  if (new_node == NULL)
  {
    return Failure;
  }
  node_pair.current->next = new_node;
  list->count++;
  return Success;
}

Status add_unique(List_ptr list, int value)
{
  Prev_Current_Pair node_pair;
  node_pair.current = list->head;
  while (node_pair.current != NULL && node_pair.current->value != value)
  {
    node_pair.current = node_pair.current->next;
  }
  if (node_pair.current == NULL)
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

  Prev_Current_Pair node_pair;
  node_pair.prev = list->head;
  list->head = list->head->next;
  list->count--;
  free(node_pair.prev);
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
  Prev_Current_Pair node_pair;
  node_pair.prev = NULL;
  node_pair.current = list->head;
  while (node_pair.current != list->last)
  {
    node_pair.prev = node_pair.current;
    node_pair.current = node_pair.current->next;
  }
  list->last = node_pair.prev;
  list->last->next = NULL;
  list->count--;
  free(node_pair.current);
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
  Prev_Current_Pair node_pair;
  node_pair.prev = NULL;
  node_pair.current = list->head;
  for (int i = 0; i < position; i++)
  {
    node_pair.prev = node_pair.current;
    node_pair.current = node_pair.current->next;
  }
  node_pair.prev->next = node_pair.current->next;
  free(node_pair.current);
  list->count--;
  return Success;
}

Status remove_first_occurrence(List_ptr list, int value)
{
  Prev_Current_Pair node_pair;
  node_pair.current = list->head;
  int position = 0;
  while (node_pair.current != NULL && node_pair.current->value != value)
  {
    node_pair.current = node_pair.current->next;
    position++;
  }
  if (node_pair.current == NULL)
  {
    return Failure;
  }

  return remove_at(list, position);
}

Status remove_all_occurrences(List_ptr list, int value)
{
  Prev_Current_Pair node_pair;
  node_pair.prev = NULL;
  node_pair.current = list->head;
  int position = 0;
  Status status = Failure;
  while (node_pair.current != NULL)
  {
    if (node_pair.current->value == value)
    {
      status = remove_at(list, position);
    }
    else
    {
      node_pair.prev = node_pair.current;
      position++;
    }
    node_pair.current = node_pair.current->next;
  }

  return status;
}

Status clear_list(List_ptr list)
{
  Status status = Failure;
  while (list->count > 0)
  {
    status = remove_from_end(list);
  }
  return status;
}

Status is_number_present(List_ptr list, int value)
{
  Prev_Current_Pair node_pair;
  node_pair.current = list->head;
  while (node_pair.current != NULL && node_pair.current->value != value)
  {
    node_pair.current = node_pair.current->next;
  }
  return node_pair.current == NULL ? Failure : Success;
}

void destroy_list(List_ptr list)
{
  clear_list(list);
  free(list);
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