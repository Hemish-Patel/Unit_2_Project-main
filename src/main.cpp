#include "include/Config.hpp"
#include "MicProcessingAndSpectrumAnalyser.hpp"
#include <iostream>
#include <regex>
#include "include/GuitarTuner.hpp"

#ifdef TEST_MAIN

void main_menu();
int get_user_input();
void select_menu_item(int input);
void print_main_menu();
void go_back_to_main_menu();
bool is_integer(std::string num);
void menu_item_1();
void menu_item_2();
void menu_item_3();
void menu_item_4();

int main(int argc, char* argv[]) {
  main_menu();
  return 0;
}

void main_menu() {
  print_main_menu();
  int input = get_user_input();
  select_menu_item(input);
}

int get_user_input() {
  int input;
  std::string input_string;
  bool valid_input = false;
  int menu_items = 5;

  do {
    std::cout << "\nSelect item: ";
    std::cin >> input_string;
    valid_input = is_integer(input_string);
    // if input is not an integer, print an error message
    if (valid_input == false) {
      std::cout << "Enter an integer!\n";
    } else {  // if it is an int, check whether in range
      input = std::stoi(input_string);  // convert to int
      if (input >= 1 && input <= menu_items) {
        valid_input = true;
      } else {
        std::cout << "Invalid menu item!\n";
        valid_input = false;
      }
    }
  } while (valid_input == false);

  return input;
}

void select_menu_item(int input) {
  switch (input) {
    case 1:
      menu_item_1();
      break;
    case 2:
      menu_item_2();
      break;
    case 3:
      menu_item_3();
      break;
    case 4:
      menu_item_4();
      break;
    default:
      exit(1);
      break;
  }
}

void print_main_menu() {
  std::cout << "\n|---------------------------------------|\n";
  std::cout << "\n|--------- Frequency Analyser ----------|\n";
  std::cout << "\n|---------------------------------------|\n";
  std::cout << "|\t\t\t\t\t|\n";
  std::cout << "|\t1. Spectrum Analyser\t\t|\n";
  std::cout << "|\t2. Chebyshev Filter Designer\t|\n";
  std::cout << "|\t3. Export\t\t\t|\n";
  std::cout << "|\t \t\t\t\t|\n";
  std::cout << "|\t5. Exit\t\t\t\t|\n";
  std::cout << "|\t\t\t\t\t|\n";
  std::cout << "-----------------------------------------\n";
}

void go_back_to_main() {
  std::string input;
  do {
    std::cout << "\nEnter 'b' or 'B' to go back to main menu: ";
    std::cin >> input;
  } while (input != "b" && input != "B");
  main_menu();
}

bool is_integer(std::string num) {
  return std::regex_match(num, std::regex("[+-]?[0-9]+"));
}

void menu_item_1() {
  std::cout << "\n>> Spectrum Analyser\n";
  // you can call a function from here that handles menu 1
  Show_spectrum();
  main_menu();
}
void menu_item_2() {
  std::cout << "\n>> Chebyshev Filter Designer\n";
  Cheb_filter();
  // you can call a function from here that handles menu 2
  main_menu();
}
void menu_item_3() {
  std::cout << "\n>> Menu 3\n";
  std::cout << "\nSome code here does something useful\n";
  // you can call a function from here that handles menu 3
  go_back_to_main();
}
void menu_item_4() {
  std::cout << "\n>> Menu 4\n";
  std::cout << "\nSome code here does something useful\n";
  // you can call a function from here that handles menu 4
  go_back_to_main();
}

#endif
