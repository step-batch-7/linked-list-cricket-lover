#include <stdio.h>
#include "list.h"

void clear_buffer()
{
  while ((getchar()) != '\n')
  {
  };
}

void show_main_menu()
{
  printf("Main Menu\n---------\n\n");
  printf("(a) add a number to the end of the list\n");
  printf("(b) add a number to the start of the list\n");
  printf("(c) insert a number at a given position in the list\n");
  printf("(d) add a unique item on the list at the end(if it already exists, do not insert)\n");
  printf("(e) remove a number from the beginning of the list\n");
  printf("(f) remove a number from the end of the list\n");
  printf("(g) remove a number from a given position in the list\n");
  printf("(h) remove first occurrence of a number\n");
  printf("(i) remove all occurrences of a number\n");
  printf("(j) clear the whole list\n");
  printf("(k) check if a number exists in the list\n");
  printf("(l) display the list of numbers\n");
  printf("(m) exit\n\n");
}

char take_user_choice(char user_choice)
{
  printf("Choose an option\n");
  scanf("%c", &user_choice);
  clear_buffer();
  return user_choice;
}

void perform_required_operation(List_ptr list, char user_choice, int number)
{
  Status status;
  switch (user_choice)
  {
  case 'a':
    printf("Enter a number \n");
    scanf("%d", &number);
    clear_buffer();
    status = add_to_end(list, number);
    break;
  case 'b':
    printf("Enter a number \n");
    scanf("%d", &number);
    clear_buffer();
    status = add_to_start(list, number);
    break;

  default:
    break;
  }
}

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

int main(void)
{
  List_ptr list = create_list();
  char user_choice;
  int number;
  do
  {
    show_main_menu();
    user_choice = take_user_choice(user_choice);
    perform_required_operation(list, user_choice, number);
  } while (user_choice != 'm');
  display_list(list);
  return 0;
}
