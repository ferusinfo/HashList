#include <stdio.h>

//Hashing function
int h(int id, int i)
{
    return (id%61+i*(1+id%59))%61;
}

int main(){
	printf("%i \n\n", h(30,30));
}
