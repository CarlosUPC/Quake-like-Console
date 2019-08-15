#ifndef __SCENEMANAGER_H__
#define __SCENEMANAGER_H__

#include "j1Module.h"
#include "j1Gui.h"
#include "Scene.h"

struct SDL_Texture;

class MenuScene;

class j1SceneManager : public j1Module
{
public:

	j1SceneManager();

	// Destructor
	virtual ~j1SceneManager();

	// Called before render is available
	bool Awake();

	// Called before the first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	// Called each loop iteration
	bool Update(float dt);

	// Called before all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

	// Change scene
	void ChangeScene(Scene* new_scene);
	Scene* GetCurrentScene();



public:
	// Scenes
	MenuScene*   menu_scene = nullptr;

private:
	// Scenes list
	list<Scene*> scenes;

	// Current scene
	Scene*		 current_scene = nullptr;
};

#endif // __SceneManager_H__
