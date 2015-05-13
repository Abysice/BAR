#include "BARSerialize.h"


struct TestStruct
{
	int a;
	float b;
	char * c;
};


int main(int argc, const char** argv)
{
	TestStruct test;
	test.a = 5;
	test.b = 2.2F;
	//test.c = "HelloTest!";

	char * TestStreamStorage = new char[100];
	SerialChunk * chunk = new SerialChunk(TestStreamStorage,100);
	Serializer cereal(chunk);

	cereal << test.a;
	cereal << test.b;
	cereal.WriteDataToDisk("test.dat");

	return 0;
}