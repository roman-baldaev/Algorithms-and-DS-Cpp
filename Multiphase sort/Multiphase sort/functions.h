int find_minArr ( int *a, int n ) {
	int j=0;
	while ( a[j]==-1 ) j++;
	int min = j;
	for ( ; j < n; j++) {
		if ( a[j] != -1 && a[j] < a[min] ) {
			min = j;
			
		}
	}
	return min;
} 

bool check_0 ( int *a, int n ) {
	for ( int i = 0; i < n; i++) {
		if ( a[i] == 0 ) {
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
		
	}
	return true;
}