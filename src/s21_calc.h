#ifndef S21_CALC_H
#define S21_CALC_H

#define MAX_NUM 2048
#define S21_EPS 1e-7

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main_function(char *string, double *output, double x);
int validation(char *string);
void delete_spaces(char *string);
void unary_support(char *string);
int parser(char *string, double *output, double x);
int get_lexem(char *string, int *i, char *lexem);
int do_the_math(char operation, double *numbers, int *last);
int priority(char c);
char function_shortname(char *string, int i);

double get_total(double amount, double months, double interest,
                 int differentiated);

#endif