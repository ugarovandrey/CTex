#include "criteria.c"

int criteria_optimistic (double **array_matrix, int var_columns, int var_rows);
int criteria_wald (double **array_matrix, int var_columns, int var_rows);
int criteria_savage (double **array_matrix, int var_columns, int var_rows);
int criteria_gurvitz(double **array_matrix, int var_columns, int var_rows, double lambda);
int criteria_pessimistic (double **array_matrix, int var_columns, int var_rows);
int criteria_max_average(double **array_matrix, int var_columns, int var_rows, double *array_chance);
int criteria_optimistic_average(double **array_matrix, int var_columns, int var_rows, double *array_chance);