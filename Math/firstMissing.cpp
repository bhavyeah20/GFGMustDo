for(all)
	if(A[A[i]-1] != A[i])
		swap(A[A[i]-1], A[i]), i--;

for(all)
	if(i != A[i])
		return i;
