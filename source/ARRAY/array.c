double func_array_minimal_index (double* array, int n){
	int min_index = 0;
	for (int i = 0; i < n; i++)
	{
		if (array [i] < array [min_index]){
			min_index = i;
		}
	}
	return min_index;
}

double func_array_maximal_index (double* array, int n){
	int max_index = 0;
	for (int i = 0; i < n; i++)
	{
		if (array [i] > array[max_index]){
			max_index = i;
		}
	}
	return max_index;
}