#include <stdio.h>


int main(void){
	

	return 0;
}


void dtStat(int* array,int* temps){
	static int i=0;
	static int sum=0;
	int array_size=*(&array +1)-array;
	sum=sum+array[i];
	if(i==0){
		temps[0]=array[i];
		temps[1]=array[i];
	}
	else{
		if(array[i]>temps[0])
			temps[0]=array[i];
		if(array[i]<temps[1])
			temps[1]=array[i];
	}
	temps[2]=sum/i;
	if(array_size==i){
		i=0;
		sum=0;
	}
	i++;
}

