int lowerBound(long long number, int left, int right) {
	int middle;
	while (left < right) {
		middle = (left + right) / 2;
		if (b[middle] < number) {
			left = middle + 1;
		}
		else right = middle;
	}
	return right;
}

int upperBound(long long number, int left, int right) {
	int middle;
	while (left < right) {
		middle = (left + right) / 2;
		if (b[middle] < number) {
			left = middle + 1;
		}
		else right = middle;
	}
	return right;
}