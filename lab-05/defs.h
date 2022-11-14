#include <iostream>
#include <vector>

#ifndef DEFS
#define DEFS

int fun(int a, int b);

double max(double a, double b, double c);

void dodaj3(double &n);

void my_swap(int &a, int &b);

void print_tab(int *arr, int len);

void sort_tab(int *arr, int len);

bool is_prime(int n);

void print_vec(const std::vector<int> &v);

void fill_random_vec(std::vector<int> &v);

#endif