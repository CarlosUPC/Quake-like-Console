#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Input.h"
#include "j1Textures.h"
#include "j1Audio.h"
#include "j1Render.h"
#include "j1Window.h"

#include "j1SceneManager.h"
#include "MenuScene.h"

#define NUMBER_OF_PLAYERS 4

j1SceneManager::j1SceneManager() : j1Module()
{
	name = "scene";
}

// Destructor
j1SceneManager::~j1SceneManager()
{

}

// Called before render is available
bool j1SceneManager::Awake()
{
	bool ret = true;

	LOG("Loading SceneManager");

	return ret;
}

// Called before the first frame
bool j1SceneManager::Start()
{
	bool ret = false;

	LOG("Start module scene");

	// Creating scenes
	menu_scene = new MenuScene();
	// -------------

	// Starting scene
	current_scene = menu_scene;

	// Start scene
	if (current_scene != nullptr)
		ret = current_scene->Start();


	return ret;
}

// Called each loop iteration
bool j1SceneManager::PreUpdate()
{
	bool ret = false;

	if (current_scene != nullptr)
		ret = current_scene->PreUpdate();

	return ret;
}

// Called each loop iteration
bool j1SceneManager::Update(float dt)
{
	bool ret = false;

	if (current_scene != nullptr)
		ret = current_scene->Update(dt);

	return ret;
}

// Called each loop iteration
bool j1SceneManager::PostUpdate()
{
	bool ret = false;

	if (current_scene != nullptr)
		ret = current_scene->PostUpdate();

	if (App->input->GetKey(SDL_SCANCODE_ESCAPE) == KEY_DOWN)
		ret = false;

	return ret;
}

// Called before quitting
bool j1SceneManager::CleanUp()
{
	LOG("Freeing scene");

	bool ret = false;
	if (current_scene != nullptr)
		ret = current_scene->CleanUp();

	return ret;
}

void j1SceneManager::ChangeScene(Scene * new_scene)
{
	LOG("Changing current scene");

	Scene* last_scene = current_scene;
	current_scene = new_scene;
	last_scene->CleanUp();
	current_scene->Start();
}

Scene * j1SceneManager::GetCurrentScene()
{
	return current_scene;
}

