//I'm just using this to test my code, if anything is left here just delete it and write whatever you need for the project ^-^

#include "Money.h"

int main(){
	Money m(100,10);
	Money n(200,20);

	if(m==n){
		std::cout << m << " code is not working " << n << std::endl;
	}
	else{
		std::cout << n << " code is working " << m << std::endl;
	}

	return 0;
}


