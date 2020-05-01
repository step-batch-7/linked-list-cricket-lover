#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void display_list(List_ptr list)
{
  Node *p_walk = list->head;
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
  list->head = new_node;
  list->count++;
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
