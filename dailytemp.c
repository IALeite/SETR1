#include <stdio.h>

/** Inicializes a vector to store tempratures during a day*/
void dtInit(int* dayTemp);
void dtStat(int* array,int* temps);



int main(void){

	int values[3];
	int dTemp[24];
	
	dtInit(dTemp);
	
	for(int i = 0; i<24; i++)
	{
		dtAdd(&dTemp);
		dtStat(&dTemp, &values);
		printf("Máx: %d Min: %d Average: %d \n",values[0], values[1], values[2]); /// Display current stats values	
	}
	
	return 0;
}


void dtInit(int* dTemp)
{
	for(int i = 0 ; i<24; i++)
	{
		dTemp[i] = 100;
	}

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
	else
		i++;
}
