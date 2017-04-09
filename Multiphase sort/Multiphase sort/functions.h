int find_minArr ( int *a, int n ) {
	int j;
	int min = a[0];
	j=0;
	for ( int i = 1; i < n; i++) {
		if ( a[i] != -1 && a[i] < min ) {
			min = a[i];
			j=i;
		}
	}
	return j;
} 

bool check_0 ( int *a, int n ) {
	for ( int i = 0; i < n; i++) {
		if ( a[i] != 0 ) {
			return false;
		}
	}
	return true;
}
bool check_minus_1 ( int *a, int n ) {
	for ( int i = 0; i < n; i++) {
		if ( a[i] != -1 ) {
			return false;
		}
		return true;
	}
}