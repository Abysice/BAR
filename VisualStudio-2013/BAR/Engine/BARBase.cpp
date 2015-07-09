#include "BARBase.h"



template <class type> 
void Manager<type>::New(void)
{
	*managerPointer = &managerObject;

	return;
}

template <class type> 
void Manager<type>::Delete(void)
{
	if (*managerPointer)
	{
		managerObject.Destruct();
		*managerPointer = nullptr;
	}
}
