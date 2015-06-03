#ifndef SERIALIZE_H
#define SERIALIZE_H


#include <string>
#include <iostream>
#include <fstream>
#include "BARMatrix.h"


enum
{
	BufferDefaultSize = 16384 //16 KB by default
};



//keeps track of the chunk of data used in serialization and deserialization of classes
class SerialChunk
{
private:
	unsigned int logicalSize; //current size
	unsigned int physicalSize; //current max size
	char *activeStorage; //currently used data buffer
	char *extraStorage; //used for resizing

	//Resize the chunk to accomidate new data if needed
	void Resize(unsigned int size);

public:

	SerialChunk(void *storage, unsigned int size = 0);
	~SerialChunk();

	unsigned int GetSize(void) const
	{
		return (logicalSize);
	}

	void *GetStorage(void) const
	{
		return (activeStorage);
	}

	//reserve additional memory for the chunk and return the pointer to it
	void *Reserve(unsigned int size);
};





//Represents a output serialization stream. (Packer)
class Serializer
{
private:
	SerialChunk * outputData;
public:
	Serializer(SerialChunk * dataChunk)
	{
		outputData = dataChunk;
	}
	~Serializer();

	//write the data to file, of number of characters
	void WriteDataToDisk(const char* file)
	{	
		std::ofstream fs(file, std::ios::out | std::ios::binary | std::ios::app);//output flag, binary flag,append to end
		fs.write(reinterpret_cast<const char*>(outputData->GetStorage()), outputData->GetSize());
		fs.close();
	}

	//add arbitrary data to the serialize
	void AddData(const void *data, unsigned int size)
	{
		void *ptr = outputData->Reserve(size);
		std::memcpy(ptr, data, size);
	}

	//add an array to the serializer (does not preform a deep copy)
	template <typename type> void WriteArray(int count, const type *array)
	{
		unsigned int size = count * sizeof(type);
		void *ptr = outputData->Reserve(size);
		std::memcpy(ptr, array, size);
	}

	template <typename type> Serializer& operator <<(const type& data)
	{
		type *ptr = static_cast<type *>(outputData->Reserve(sizeof(type)));
		ptr[0] = data;
		return (*this);
	}

	Serializer& operator <<(const bool& data)
	{
		unsigned int *ptr = static_cast<unsigned int *>(outputData->Reserve(4));
		ptr[0] = data;
		return (*this);
	}

	Serializer& operator <<(const Matrix4& data)
	{
		Vector4 *ptr = static_cast<Vector4 *>(outputData->Reserve(sizeof(Matrix4)));
		ptr[0] = data[0];
		ptr[1] = data[1];
		ptr[2] = data[2];
		ptr[3] = data[3];
		return (*this);
	}

	Serializer& operator <<(const std::string& string)
	{
		return (operator <<(string.c_str()));
	}

	Serializer& operator <<(const char *string);
};


//Represents a input deserialization stream. (Unpacker)
class Deserializer
{
public:
	int endian;
	Deserializer(int end = 1);
	~Deserializer();


};

//A base class for any serializable object 
class Serializable
{
public:
	Serializable(){}
	virtual ~Serializable(){}

	virtual void serialize(Serializer& data) {};
	virtual void deserialize(Deserializer& data) {};

};

#endif