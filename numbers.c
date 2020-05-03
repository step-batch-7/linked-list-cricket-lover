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

char read_user_choice(Char_ptr user_choice)
{
  printf("Please enter the alphabet of the operation you would like to perform\n");
  scanf("%c", user_choice);
  clear_buffer();
  return *user_choice;
}

int read_input_values(Int_ptr number)
{
  printf("Enter a number \n");
  scanf("%d", number);
  clear_buffer();
  return *number;
}

void perform_required_operation(List_ptr list, char user_choice)
{
  int number, position;
  Status status;
  switch (user_choice)
  {
  case 'a':
    number = read_input_values(&number);
    status = add_to_end(list, number);
    break;
  case 'b':
    number = read_input_values(&number);
    status = add_to_start(list, number);
    break;
  case 'c':
    number = read_input_values(&number);
    position = read_input_values(&position);
    status = insert_at(list, number, position);
    break;
  case 'd':
    number = read_input_values(&number);
    status = add_unique(list, number);
    break;
  case 'e':
    status = remove_from_start(list);
    break;
  case 'f':
    status = remove_from_end(list);
    break;
  case 'g':
    position = read_input_values(&position);
    status = remove_at(list, position);
    break;
  case 'h':
    number = read_input_values(&number);
    status = remove_first_occurrence(list, number);
    break;
  case 'i':
    number = read_input_values(&number);
    status = remove_all_occurrences(list, number);
    break;
  default:
    break;
  }
}

int main(void)
{
  List_ptr list = create_list();
  if (list == NULL)
  {
    printf("Memory not alloted!\n");
    return 1;
  }

  char user_choice;
  do
  {
    show_main_menu();
    user_choice = read_user_choice(&user_choice);
    perform_required_operation(list, user_choice);
  } while (user_choice != 'm');
  return 0;
}
