#include "Application.h"

#include "ModuleGameObjects.h"

ModuleGameObjects::ModuleGameObjects(Application* app, bool start_enabled):Module(app, start_enabled)
{

}

bool ModuleGameObjects::Start()
{
	return true;
}

update_status ModuleGameObjects::PostUpdate()
{
	return UPDATE_CONTINUE;
}

update_status ModuleGameObjects::Update(float dt)
{
	return UPDATE_CONTINUE;
}

bool ModuleGameObjects::CleanUp()
{
	return true;
}


