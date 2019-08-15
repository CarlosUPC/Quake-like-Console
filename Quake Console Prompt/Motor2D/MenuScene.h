#ifndef _MAINSCENE_
#define _MAINSCENE_

#include "j1App.h"
#include "j1Render.h"
#include "PugiXml\src\pugixml.hpp"

#include <string>
#include <list>

#include "Scene.h"

class MenuScene : public Scene
{
public:
	MenuScene();

	virtual ~MenuScene() {};

	bool Start();
	bool PreUpdate();
	bool Update(float dt);
	bool PostUpdate();
	bool CleanUp();

	bool Load(pugi::xml_node&);

	bool Save(pugi::xml_node&) const;

	
};

#endif