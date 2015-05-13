#include "BARSerialize.h"


//SerialChunk class method implementations


SerialChunk::SerialChunk(void *storage, unsigned int size)
{
	logicalSize = 0;
	physicalSize = size;

	activeStorage = static_cast<char *>(storage);
}

SerialChunk::~SerialChunk()
{
}

void SerialChunk::Resize(unsigned int size)
{
	size = Mathf::Max(Mathf::Max(physicalSize * 2, BufferDefaultSize), size + ((size / 2 + 15) & ~15));
	physicalSize = size;

	char *newStorage = new char[size];
	std::memcpy(newStorage, activeStorage, logicalSize);

	activeStorage = newStorage;
}

void *SerialChunk::Reserve(unsigned int size)
{
	unsigned int newSize = logicalSize + size;
	if (newSize > physicalSize)
	{
		Resize(newSize);
	}

	char *ptr = activeStorage + logicalSize; 
	logicalSize = newSize;
	return (ptr);
}

//Serialzer class method implementations

Serializer::~Serializer()
{
	delete outputData;
}

Serializer& Serializer::operator <<(const char *string)
{
	unsigned int length = strlen(string);
	unsigned int size = ((length + 4) & ~3);
	unsigned int *ptr = static_cast<unsigned int *>(outputData->Reserve(size + 4));

	ptr[0] = size;
	char *data = reinterpret_cast<char *>(ptr + 1);
	std::memcpy(data, string, length);

	data += length;
	int pad = size - length;
	for (int a = 0; a < pad; a++)
	{
		data[a] = 0;
	}

	return (*this);
}






//Deserializer class method implementations
Deserializer::Deserializer(int end)
{
	endian = end;
}

Deserializer::~Deserializer()
{
}




//serializable class method implementations




