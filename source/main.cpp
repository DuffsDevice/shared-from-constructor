#include "sharedptr.h"
#include <nds.h>
#include <stdio.h>
#include <map>

struct Dummy : public enable_shared_from_this<Dummy>
{
	Dummy(){
		printf("Constructed!\n");
	}
	
	~Dummy(){
		printf("Destructed!\n");
	}
};

int main(void)
{
	consoleDemoInit();
	
	std::map<unsigned int, shared_ptr<Dummy>> map;
	
	for( int i = 0; i < 30 ; ++i )
	{
		shared_ptr<Dummy> ptr1 = make_shared<Dummy>();
		map[i] = ptr1;
	}
	
	printf("Halloµ");
	
	while(1){
		swiWaitForVBlank();
	}

	return 0;
}
