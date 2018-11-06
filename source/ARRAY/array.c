int func_array_minimal_index (double* array, int n){
	int min_index = 0;
	for (int i = 0; i < n; i++)
	{
		if (array [i] < array [min_index]){
			min_index = i;
		}
	}
	return min_index;
}

int func_array_maximal_index (double* array, int n){
	int max_index = 0;
	for (int i = 0; i < n; i++)
	{
		if (array [i] > array[max_index]){
			max_index = i;
		}
	}
	return max_index;
}

double func_array_minimal(double* array, int n) {
	int min = array [0];
	for (int i = 1; i < n; i++)
	{
		if (array[i] < array[min]) {
			min = array [i];
		}
	}
	return min;
}

double func_array_maximal(double* array, int n) {
	int max = array[0];
	for (int i = 1; i < n; i++)
	{
		if (array[i] > array[max]) {
			max= array [i];
		}
	}
	return max;
}