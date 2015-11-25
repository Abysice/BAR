#ifndef BARBASE_H
#define BARBASE_H

#include "BARDefines.h"

//Base class for the singleton template. contains the pointer to the instance, 
//the singletons created using this template must be constructed somewhere
template <class type>
class Singleton
{
private:
	type	**singleton;

protected:
	//the constructor has protected access. The Singleton class can only exist as a base class
	Singleton(type *& instance)
	{
		instance = static_cast<type *>(this);
		singleton = &instance;
	}

	~Singleton()
	{
		*singleton = nullptr;
	}
};


//Manager class, similar to singletons but for engine manager classes
template <class type>
class Manager
{
private:
	static type	managerObject;
	static type	**managerPointer;

public:
	static void New(void);
	static void Delete(void);

};



#endif