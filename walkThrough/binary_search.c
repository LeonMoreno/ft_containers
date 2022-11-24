#include <stdio.h>

int	binarySearch(int *arr, int begin, int end, int x)
{
	while (begin <= end )
	{
		int m = (begin + (end - 1)) / 2; // ley de signos
		printf("m =  %d arr[m] = %d\n", m, arr[m]);
		if (arr[m] == x)
			return (m);
		else if (arr[m] < x) // estaba confundido. se lee x menor que tal numero
		{
			printf("X es menor\n");
			begin = m + 1;
		}

		else
		{
			printf("X es Mayor\n");
			end = m - 1;
		}
	}
	return (-1);
}

int	main(void)
{
	int	res;

	int	arr[] = {7, 23, 36, 54, 56, 87, 99};
	res = binarySearch(arr, 0, 7, 99);
	if (res != -1)
		printf("esta presente at index %d\n", res);
	else
		printf("No esta\n");
	return (0);
}
