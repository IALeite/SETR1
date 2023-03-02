#include <stdio.h>

/** Inicializes a vector to store tempratures during a day*/
void dtInit(int* dayTemp);



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



