#include "BARApplication.h"


Application *TheApplication = nullptr;




Application::Application() : Singleton<Application>(TheApplication)
{

}

Application::~Application() 
{

}