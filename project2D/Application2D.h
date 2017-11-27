#pragma once
#include "Application.h"
#include "Renderer2D.h"
#include "Entity.h"
#include "Player2D.h"
#include "Debris.h"
#include "Enemy2D.h"
#include <time.h>

class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Texture*		m_texture;
	aie::Texture*		m_shipTexture;
	aie::Font*			m_font;

	aie::Texture*       m_Winner;
	aie::Texture*       m_Loser;
	aie::Texture*       m_Background;
	aie::Texture*       m_DebrisL;
	aie::Texture*       m_EnemyShip;

	float m_cameraX, m_cameraY;
	float m_timer;

	Player2D *mPlayer;
	Player2D *isAlive;
	Debris *mDebris; 
	Enemy2D *mEnemy;
	float timeLeft;


	//Win Condition
	bool shipLived;
};