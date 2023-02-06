extern "C"
{
	int getmin(int* arr, int length)
	{
		int min = *arr;

		for (int i = 1; i < length; i++)
		{
			if (min > arr[i]) min = arr[i];
		}

		return min;
	}

	int getmax(int* arr, int length)
	{
		int max = *arr;

		for (int i = 1; i < length; i++)
		{
			if (max < arr[i]) max = arr[i];
		}

		return max;
	}
}

