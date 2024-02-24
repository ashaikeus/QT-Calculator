#include "s21_calc.h"

/**
 * @file s21_calc.c
 * @brief Main file for basic calculation.
 */

/**
 * @brief Entry point for the calculator.
 *
 * Validation and some support functions happen here. Then it calls for the
 * parser.
 *
 * @param string The string with the expression needed to evaluate
 * @param output The result of the evaluation
 * @param x The value of x (default is 0)
 *
 * @return 0: OK
 * @return Error 1: wrong number of brackets
 * @return Error 2: mismatched brackets
 * @return Error 3: too many dots in number
 * @return Error 4: no number with operator / stack error
 */
int main_function(char *string, double *output, double x) {
  int ret = validation(string);
  if (!ret) {
    delete_spaces(string);
    unary_support(string);
    delete_spaces(string);
    ret = parser(string, output, x);
  }

  return ret;
}

/**
 * Checks whether the expression is mathematically correct.
 *
 * @param string The string with the expression being validated
 *
 * @return 0: OK
 * @return Error 1: wrong number of brackets
 * @return Error 2: mismatched brackets
 * @return Error 3: too many dots in number
 * @return Error 4: no number with operator / stack error
 */
int validation(char *string) {
  int error = 0;

  int num = 0;
  double op = 0;
  int skobk_l = 0, skobk_r = 0;
  int last = 0;  // 0 for ')', 1 for '('
  int is_number_last = 0;
  char c[10] = {0};
  for (int i = 0; i < (int)strlen(string); i++) {
    if (string[i] == '(') {
      skobk_l++;
      last = 1;
    } else if (string[i] == ')') {
      skobk_r++;
      last = 0;
    } else if (isdigit(string[i]) || string[i] == 'x') {
      if (string[i] == 'x' || !is_number_last ||
          (isdigit(string[i]) && i > 0 && string[i - 1] == 'x'))
        num += 1;
      is_number_last = 1;
    } else {
      get_lexem(string, &i, c);
      if (priority(c[0]) != -1 && priority(c[0]) != 5) {
        op += 1;
        is_number_last = 0;
      } else if (priority(c[0]) == 5) {
        op += 0.5;
        is_number_last = 0;
      }
      i--;
    }
  }

  if (skobk_l != skobk_r)
    error = 1;
  else if (last == 1)
    error = 2;
  else if (!num)
    error = 4;
  else if (!is_number_last)
    error = 4;
  else if (num - op > 1) {
    error = 4;
  }

  return error;
}

/**
 * Deletes spaces in any given string.
 * @param string The string with the expression
 */
void delete_spaces(char *string) {
  int valid_chars = 0;
  for (int i = 0; i < (int)strlen(string); i++) {
    if (string[i] != ' ') string[valid_chars++] = string[i];
  }
  string[valid_chars] = '\0';
}

/**
 * @brief Turns combinations of +-~ signs into one sign, so it's easier to
 * evaluate.
 *
 * -- turn to +, ++ turn to +, -+ turn to -, and such.
 *
 * @param string The string with the expression
 */
void unary_support(char *string) {
  for (int i = 0; i < (int)strlen(string) && i + 1 < (int)strlen(string); i++) {
    if (((string[i] == '-' && string[i + 1] == '-') ||
         (string[i] == '-' && string[i + 1] == '~') ||
         (string[i] == '~' && string[i + 1] == '~') ||
         (string[i] == '~' && string[i + 1] == '-'))) {
      string[i] = '+';
      string[i + 1] = ' ';
    }

    if ((string[i] == '-' && string[i + 1] == '+') ||
        (string[i] == '+' && string[i + 1] == '-') ||
        (string[i] == '~' && string[i + 1] == '+') ||
        (string[i] == '+' && string[i + 1] == '~')) {
      string[i] = '-';
      string[i + 1] = ' ';
    }

    if (string[i] == '+' && string[i + 1] == '+') {
      string[i] = '+';
      string[i + 1] = ' ';
    }

    if (priority(string[i]) != -1 && string[i + 1] == '-') string[i + 1] = '~';
    if (string[i] == '(' && string[i + 1] == '-') string[i + 1] = '~';
    if (priority(string[i]) != -1 && string[i + 1] == '+') string[i + 1] = ' ';
    if (string[i] == '(' && string[i + 1] == '+') string[i + 1] = ' ';
  }
}

/**
 * @brief Main processing function.
 *
 * Creates two stacks, for numbers and operators.
 * Starts as RPN, but when it's time to push to output string, evaluates it
 * instead.
 *
 * @param string The string with the expression needed to evaluate
 * @param output The result of the evaluation
 * @param x The value of x (default is 0)
 *
 * @return 0: OK
 * @return Error 1: wrong number of brackets
 * @return Error 3: too many dots in number
 * @return Error 4: no number with operator / stack error
 */
int parser(char *string, double *output, double x) {
  int error = 0;

  char *stack;
  stack = calloc(MAX_NUM, sizeof(char));
  int last_s = 0;

  double numbers[MAX_NUM] = {0};
  int last_n = 0;

  for (int i = 0; i < (int)strlen(string) && !error;) {
    char *cur_lex;
    cur_lex = (char *)malloc(MAX_NUM * sizeof(char));

    int isnumber = get_lexem(string, &i, cur_lex);
    if (isnumber == -1) {
      free(cur_lex);
      error = 3;
      break;
    }
    if (cur_lex[0] == 'x') {
      numbers[last_n++] = x;
    } else if (cur_lex[0] == ')') {
      if (last_s > 0)
        while (stack[last_s] != '(') {
          if (last_s < 0) error = 2;
          if (do_the_math(stack[--last_s], numbers, &last_n)) error = 4;
        }
    } else if (isnumber)
      numbers[last_n++] = atof(cur_lex);
    else {
      while (last_s > 0 && priority(cur_lex[0]) > 0 &&
             priority(cur_lex[0]) <= priority(stack[last_s - 1])) {
        if (do_the_math(stack[--last_s], numbers, &last_n)) error = 4;
        stack[last_s + 1] = 0;
      }
      stack[last_s++] = cur_lex[0];
    }

    free(cur_lex);
  }

  if (!error)
    while (last_s > 0 && last_n >= 1)
      if (do_the_math(stack[--last_s], numbers, &last_n)) error = 4;
  if (!error && last_s > 0) error = 1;

  free(stack);

  if (last_n > 0) *output = numbers[0];

  return error;
}

/**
 * @brief Breaks the string into lexems.
 *
 * Gets an index, starts reading the string from it.
 * If the lexem is a number, puts its every digit in the string.
 * If it's an operator, puts it into string[0].
 * If it's a function, gets its shortname.
 *
 * @param string The string with the expression needed to evaluate
 * @param i The starting index in the string
 * @param lexem The final lexem (or its shortname)
 *
 * @return 0: OK
 * @return Error 3: too many dots in number
 */
int get_lexem(char *string, int *i, char *lexem) {
  int isnumber = 0;
  int lex_i = 0;
  if (isdigit(string[*i])) {
    isnumber = 1;
    int dotcount = 0;
    while (isdigit(string[*i]) || string[*i] == '.') {
      if (string[*i] == '.') dotcount++;
      if (dotcount > 1) {
        isnumber = -1;
        break;
      }
      lexem[lex_i++] = string[*i];
      *i = *i + 1;
    }
    lexem[lex_i] = '\0';
  } else if (string[*i] == 'x') {
    lexem[lex_i] = 'x';
    *i = *i + 1;
  } else {
    if (priority(string[*i]) > 0 && priority(string[*i]) < 5)
      lexem[lex_i] = string[*i];
    else if (string[*i] == '(' || string[*i] == ')')
      lexem[lex_i] = string[*i];
    else
      lexem[lex_i] = function_shortname(string, *i);

    if (lexem[lex_i] == 'i' || lexem[lex_i] == 'o' || lexem[lex_i] == 'a' ||
        lexem[lex_i] == 'r')
      *i = *i + 3;
    else if (lexem[lex_i] == 's' || lexem[lex_i] == 'c' ||
             lexem[lex_i] == 't' || lexem[lex_i] == 'l')
      *i = *i + 2;
    else if (lexem[lex_i] == 'n')
      *i = *i + 1;
    *i = *i + 1;
  }

  return isnumber;
}

/**
 * @brief The calculation function.
 *
 * Gets number stack and its length.
 * If the operation is binary, applies it to two last numbers and reduces the
 * stack length by 1. If the operation is unary or is a function, applies it to
 * last number.
 *
 * @param operation Operation or a function shortname
 * @param numbers Number stack (double array)
 * @param last Count of numbers in stack
 *
 * @return 0: OK
 * @return Error 4: no number with operator / stack error
 */
int do_the_math(char operation, double *numbers, int *last) {
  int ret = 0;
  if (*last - 1 < 0 ||
      ((priority(operation) == 2 || priority(operation) == 3) &&
       (*last - 2 < 0)))
    ret = 4;
  else if (operation == '~') {
    numbers[*last - 1] = -numbers[*last - 1];
    operation = ' ';
  }
  if (priority(operation) > 0 && priority(operation) < 4) {
    if (*last - 2 >= 0) {
      double right = numbers[*last - 1];
      double left = numbers[*last - 2];
      numbers[*last - 1] = 0.0;
      numbers[*last - 2] = 0.0;

      if (operation == '+')
        numbers[*last - 2] = left + right;
      else if (operation == '-')
        numbers[*last - 2] = left - right;
      else if (operation == '*')
        numbers[*last - 2] = left * right;
      else if (operation == '/')
        numbers[*last - 2] = left / right;
      else if (operation == '^')
        numbers[*last - 2] = pow(left, right);

      *last = *last - 1;
    } else if (operation == '-') {
      numbers[*last - 1] = -numbers[*last - 1];
    }
  } else {
    *last = *last - 1;
    switch (operation) {
      case 'n':
        numbers[*last] = log(numbers[*last]);
        break;
      case 's':
        numbers[*last] = sin(numbers[*last]);
        break;
      case 'c':
        numbers[*last] = cos(numbers[*last]);
        break;
      case 't':
        numbers[*last] = tan(numbers[*last]);
        break;
      case 'l':
        numbers[*last] = log10(numbers[*last]);
        break;
      case 'i':
        numbers[*last] = asin(numbers[*last]);
        break;
      case 'o':
        numbers[*last] = acos(numbers[*last]);
        break;
      case 'a':
        numbers[*last] = atan(numbers[*last]);
        break;
      case 'r':
        numbers[*last] = sqrt(numbers[*last]);
        break;
    }
    *last = *last + 1;
  }
  return ret;
}

/**
 * Returns the priority of the given operator / function shortname.
 * @param c Given operator / function
 * @return -1: Not an operator / function
 * @return 1: + or -
 * @return 2: * or /
 * @return 3: ^
 * @return 4: ~ (unary minus)
 * @return 5: Supported functions (ln, log, sin, cos, tan, asin, acos, atan,
 * sqrt)
 */
int priority(char c) {
  int ret = -1;
  for (int i = 0; i < 9; i++)
    if (c == "nsctlioar"[i]) ret = 5;
  if (c == '~')
    ret = 4;
  else if (c == '^')
    ret = 3;
  else if (c == '*' || c == '/')
    ret = 2;
  else if (c == '+' || c == '-')
    ret = 1;
  return ret;
}

/**
 * @brief Turns functions into shortnames.
 *
 * Goes through a function, searches for function names.
 *
 * @param string The string with the expression
 * @param i The starting index in the string
 * @return ln -> n
 * @return log -> l
 * @return sin -> s
 * @return cos -> c
 * @return tan -> t
 * @return atan -> a
 * @return asin -> i
 * @return acos -> o
 * @return sqrt -> r
 */
char function_shortname(char *string, int i) {
  char c = 0;

  if ((i + 2) < (int)strlen(string)) {
    if (string[i] == 'l' && string[i + 1] == 'n' && string[i + 2] == '(')
      c = 'n';
    else if (i + 3 < (int)strlen(string) && string[i + 3] == '(') {
      if (string[i] == 's' && string[i + 1] == 'i' && string[i + 2] == 'n')
        c = 's';
      if (string[i] == 'c' && string[i + 1] == 'o' && string[i + 2] == 's')
        c = 'c';
      if (string[i] == 't' && string[i + 1] == 'a' && string[i + 2] == 'n')
        c = 't';
      if (string[i] == 'l' && string[i + 1] == 'o' && string[i + 2] == 'g')
        c = 'l';
    } else if (i + 4 < (int)strlen(string) && string[i + 4] == '(') {
      if (string[i] == 'a' && string[i + 1] == 's' && string[i + 2] == 'i' &&
          string[i + 3] == 'n')
        c = 'i';
      if (string[i] == 'a' && string[i + 1] == 'c' && string[i + 2] == 'o' &&
          string[i + 3] == 's')
        c = 'o';
      if (string[i] == 'a' && string[i + 1] == 't' && string[i + 2] == 'a' &&
          string[i + 3] == 'n')
        c = 'a';
      if (string[i] == 's' && string[i + 1] == 'q' && string[i + 2] == 'r' &&
          string[i + 3] == 't')
        c = 'r';
    }
  }
  return c;
}

/**
 * @brief Calculator of total credit payment.
 *
 * Supports both annuity and differentiated payments.
 *
 * @param amount Base credit amount
 * @param months Months to pay the credit amount
 * @param interest Yearly interest rate
 * @param differentiated Flag indicatind whether the payments are differentiated
 */
double get_total(double amount, double months, double interest,
                 int differentiated) {
  double total = 0.0;
  if (differentiated) {
    double start_sum = amount;
    double main_payment = amount / months;
    while (amount > 0) {
      double percents = amount * interest / 100 * 30.5 /
                        365;  // 30 days in a month, 365 days in a year
      double monthly_payment = main_payment + percents;
      amount -= monthly_payment;
    }
    total = -amount + start_sum;
  } else {
    double monthly_rate = interest / 1200;
    total =
        months * amount * (monthly_rate) / (1 - pow(1 + monthly_rate, -months));
  }
  return total;
}
