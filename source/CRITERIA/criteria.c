#include <limits.h>

int criteria_optimistic (double **array_matrix, int var_columns, int var_rows){
	double result = array_matrix[0][0];
	int resultIndex = 0;
	for (int i = 0; i < var_rows; i++)
		for (int j = 0; j < var_columns; j++)
			if (result < array_matrix[i][j])
			{
				result = array_matrix[i][j];
				resultIndex = i;
			}
	return resultIndex;
}

int criteria_wald(double **array_matrix, int var_columns, int var_rows) {
	double tempMin;
	double result = INT_MIN;
	int resultIndex;

	resultIndex = 0;

	for (int i = 0; i < var_rows; i++) {
		tempMin = array_matrix[i][0];
		for (int j = 0; j < var_columns; j++) {
			if (array_matrix[i][j] < tempMin)
				tempMin = array_matrix[i][j];
		}
		if (result < tempMin)
		{
			result = tempMin;
			resultIndex = i;
		}
	}
	return resultIndex;
}

int criteria_savage(double **array_matrix, int var_columns, int var_rows) {
	double **array_R;
	double *array_col_max = (double *)malloc(sizeof(double)*var_columns);
	double temp;
	double result = INT_MAX;
	int resultIndex;

	array_R = (double **)malloc(sizeof(double*)*var_rows);
	for (int i = 0; i < var_rows; i++)
	{
		array_R[i] = (double*)malloc(sizeof(double)*var_columns);
	}
	for (int i = 0; i < var_columns; i++) 
	{
		temp = array_matrix[0][i];
		for (int j = 0; j < var_rows; j++)
		{
			if (temp < array_matrix[j][i])
				temp = array_matrix[j][i];
		}
		for (int j = 0; j < var_rows; j++)
			array_R[j][i] = temp - array_matrix[j][i];
	}

	resultIndex = 0;

	for (int i = 0; i < var_rows; i++) {
		temp = array_R[i][0];
		for (int j = 0; j < var_columns; j++) {
			if (array_R[i][j] > temp)
				temp = array_R[i][j];
		}
		if (result > temp)
		{
			result = temp;
			resultIndex = i;
		}
	}
	return resultIndex;
}

int criteria_gurvitz(double **array_matrix, int var_columns, int var_rows, double lambda) {
	double tempMax;
	double tempMin;
	double *array = (double *)malloc(sizeof(double)*var_rows);
	double result;
	int resultIndex;

	for (int i = 0; i < var_rows; i++)
	{
		tempMax = tempMin = array_matrix[i][0];
		for (int j = 0; j < var_columns; j++)
		{
			if (array_matrix[i][j] > tempMax)
				tempMax = array_matrix[i][j];
			else
				if (array_matrix[i][j] < tempMin)
					tempMin = array_matrix[i][j];
		}
		array[i] = lambda * tempMin + (1 - lambda)*tempMax;
	}

	resultIndex = 0;
	result = array[resultIndex];

	for (int i = 1; i < var_rows; i++)
		if (array[i] > result)
		{
			result = array[i];
			resultIndex = i;
		}
	return resultIndex;

}

int criteria_pessimistic(double **array_matrix, int var_columns, int var_rows) {
	double result = array_matrix[0][0];
	int resultIndex = 0;
	for (int i = 0; i < var_rows; i++)
		for (int j = 0; j < var_columns; j++)
			if (result > array_matrix[i][j])
			{
				result = array_matrix[i][j];
				resultIndex = i;
			}
	return resultIndex;
}

int criteria_max_average(double **array_matrix, int var_columns, int var_rows, double *array_chance) {
	double result;
	double temp;
	int resultIndex;

	result = 0;
	for (int i = 0; i < var_rows; i++)
	{
		temp = 0;
		for (int j = 0; j < var_columns; j++)
		{
			temp += array_matrix[i][j] * array_chance[j];
		}
		if (temp > result)
		{
			result = temp;
			resultIndex = i;
		}
	}
	return resultIndex;
	
}

int criteria_optimistic_average(double **array_matrix, int var_columns, int var_rows, double *array_chance) {
	double **array_R;
	double *array_col_max = (double *)malloc(sizeof(double)*var_columns);
	double temp;
	double result;
	int resultIndex;

	array_R = (double **)malloc(sizeof(double*)*var_rows);
	for (int i = 0; i < var_rows; i++)
	{
		array_R[i] = (double*)malloc(sizeof(double)*var_columns);
	}
	for (int i = 0; i < var_columns; i++)
	{
		temp = array_matrix[0][i];
		for (int j = 0; j < var_rows; j++)
		{
			if (temp < array_matrix[j][i])
				temp = array_matrix[j][i];
		}
		for (int j = 0; j < var_rows; j++)
			array_R[j][i] = temp - array_matrix[j][i];
	}

	result = INT_MAX;
	resultIndex = 0;

	result = 0;
	for (int i = 0; i < var_rows; i++)
	{
		temp = 0;
		for (int j = 0; j < var_columns; j++)
		{
			temp += array_R[i][j] * array_chance[j];
		}
		if (temp < result)
		{
			result = temp;
			resultIndex = i;
		}
	}

	return resultIndex;
}