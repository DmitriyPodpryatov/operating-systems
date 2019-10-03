#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *myrealloc(void *ptr, size_t old_size, size_t new_size) {
    if (ptr == NULL) {
        return malloc(new_size);
    }
    if (new_size == 0) {
        free(ptr);
        return NULL;
    }

    void *tmp = malloc(new_size);
    memcpy(tmp, ptr, old_size);
    free(ptr);
    return ptr = tmp;
}

int main() {

    printf("Enter original array size:");
	int n1=0;
	scanf("%d",&n1);

	//Create a new array of n1 ints and fill it
	int* a1 = malloc(n1 * sizeof(int));
	int i;
	for(i=0; i<n1; i++){
		a1[i]=100;
		printf("%d ", a1[i]);
	}

	printf("\nEnter new array size: ");
	int n2=0;
	scanf("%d",&n2);

	//Dynamically change the array to size n2
	a1 = myrealloc(a1, n1 * sizeof(int), n2 * sizeof(int));

    // Initialize new elements if there are such
	if (n2 > n1) {
		for (i = n1; i < n2; i++) {
			a1[i] = 0;
		}
	}	

	for(i=0; i<n2;i++){
		//Print each element out (to make sure things look right)
		printf("%d ", a1[i]);
	}
	printf("\n");
	
	free(a1);

    return 0;

}