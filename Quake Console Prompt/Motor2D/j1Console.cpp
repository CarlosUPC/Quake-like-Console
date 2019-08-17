#include "j1Console.h"
#include "p2Log.h"


j1Console::j1Console() {

}

j1Console::~j1Console() {

}

bool j1Console::Awake(pugi::xml_node &config)
{
	return true;
}

bool j1Console::Start()
{
	LOG("Starting Console");
	return true;
}

bool j1Console::PreUpdate()
{
	return true;
}

bool j1Console::Update(float dt)
{
	return true;
}

bool j1Console::PostUpdate()
{
	return true;
}

bool j1Console::CleanUp()
{
	return true;
}