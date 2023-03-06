#include <stdio.h>
#include <stdlib.h>

/** Inicializes a vector to store temperatures during a day*/
void dtInit(int* dayTemp);
void dtStat(int* array,int* temps,int size);
void dtAdd(int *temp,int i);


int main(void){
	int size=24;
	int values[3];
	int dTemp[size];
	
	dtInit(dTemp);
	
	for(int i = 0; i<size; i++)
	{
		dtAdd(dTemp,i);
		dtStat(dTemp, values,size);
		printf("Hour: %d\nTemp: %d\nMáx: %d\nMin: %d\nAverage: %d\n--------------\n",i,dTemp[i],values[0], values[1], values[2]); /// Display current stats values	
	}
	
	return 0;
}

void dtAdd(int *Temp,int i)///Adds a random value between [-50,50] to the current array position;
{
	Temp[i]=(rand() % 100) - 50;
}

void dtInit(int* dTemp)///Inicializes Temperature array
{
	for(int i = 0 ; i<24; i++)
	{
		dTemp[i] = 100;
	}

}

void dtStat(int *array,int *temps,int size)///Compares previous Values with the atual,updates the maximum and minimum value and calculates average
{
	static int i=0;
	static int sum=0;
	if(i==0){
		temps[0]=array[i];
		temps[1]=array[i];
		sum=array[i];
	}
	else{
		sum=sum+array[i];
		if(array[i]>temps[0])
			temps[0]=array[i];
		
		if(array[i]<temps[1])
			temps[1]=array[i];
	}
	i++;
	temps[2]=sum/i;
	if(size==i)
		i=0;
}

