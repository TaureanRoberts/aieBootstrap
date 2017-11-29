#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <application.h>
#include "Player2D.h"


Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	m_texture = new aie::Texture("./textures/numbered_grid.tga");
	m_shipTexture = new aie::Texture("./textures/wship1.png");
	m_font = new aie::Font("./font/consolas.ttf", 32);

	m_Loser = new aie::Texture("./textures/gameOver.png");
	m_Winner = new aie::Texture("./textures/winDoge.jpg");
	m_DebrisL = new aie::Texture("./textures/rock_large.png");
	m_Background = new aie::Texture("./textures/SpaceBG.jpg");
	
	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;

	mPlayer = new Player2D;
	mDebris = new Debris[10];
	shipLived = false;
	float tick[60];
	
	//Hardsetting Debris position
    float setX = 450;
	float setY = 600;
	for (int i = 0; i < 10; i++)
	{
		mDebris[i].mPos.mX = setX;
		mDebris[i].mPos.mY = setY;
		setX += 100;
		if (setX == 950)
		{
			setX = 450;
			setY -= 100;
		}
	}
	return true;
}

void Application2D::shutdown() 
{
	delete m_font;
	delete m_texture;
	delete m_shipTexture;
	delete m_2dRenderer;
	
	delete[] mPlayer;
	delete[] mDebris;
	delete m_Background;
	delete m_Winner;
	delete m_Loser;
	delete m_DebrisL;
}

void Application2D::update(float deltaTime) {

	m_timer += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();
	Vector2 playerPos(mPlayer->mPos.mX, mPlayer->mPos.mY);
	//Calls Player Movement
	mPlayer->Update(deltaTime);

	//Debris movement + position
	mDebris->Move(deltaTime);

	//Impact rules
	for (int i = 0; i < 10; i++)
	{
		if (mDebris[i].mPos.mY < 0)
			mPlayer->isAlive = false;
		if (mDebris[i].mPos.mY > mPlayer->mPos.mY - (mPlayer->mScale.mY / 2) && mDebris[i].mPos.mY < mPlayer->mPos.mY + (mPlayer->mScale.mY / 2))
		{
			if (mDebris[i].mPos.mX > mPlayer->mPos.mX - (mPlayer->mScale.mX / 2) && mDebris[i].mPos.mX < mPlayer->mPos.mX + (mPlayer->mScale.mX / 2))
				mPlayer->isAlive = false;
		}
	}

	//Handles game run time
	for (int i = 60; i < 0; i++)
	{
		float count = 60;
		float down = 20;
		m_timer = count;
		while (m_timer / 60) m_timer--;
		if (m_timer >= 0)
		{
			std::cout << m_timer << endl;
			m_timer--;
			if (m_timer <= down)
			{
				shipLived = false;
			}
		}
	}

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Application2D::draw() 
{
	// wipe the screen to the background colour
	clearScreen();
	//aie::Input* input = aie::Input::getInstance();
	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites
	m_2dRenderer->begin();
	m_2dRenderer->drawSprite(m_Background, 640, 360, 1280, 720);

	//Player Ship
	if (mPlayer->isAlive)
		m_2dRenderer->drawSprite(m_shipTexture, mPlayer->mPos.mX, mPlayer->mPos.mY, mPlayer->mScale.mY, mPlayer->mScale.mY);

	//Debris
	for (int i = 0; i < 1; i++)
	{
		if (mDebris[i].didCrash)
		{
			m_2dRenderer->drawSprite(m_DebrisL, mDebris[i].mPos.mX, mDebris[i].mPos.mY, mDebris[i].mScale.mX, mDebris[i].mScale.mY);
		}
	}

	// demonstrate animation
	//m_2dRenderer->setUVRect(int(m_timer) % 8 / 8.0f, 0, 1.f / 8, 1.f / 8);
	//m_2dRenderer->drawSprite(m_texture, 200, 200, 100, 100);

	// demonstrate spinning sprite
	//m_2dRenderer->setUVRect(0,0,1,1);
	//m_2dRenderer->drawSprite(m_shipTexture, 600, 400, 0, 0, m_timer, 1);

	// draw a thin line
	//m_2dRenderer->drawLine(300, 300, 600, 400, 2, 1);

	// draw a moving purple circle
	//m_2dRenderer->setRenderColour(1, 0, 1, 1);
	//m_2dRenderer->drawCircle(sin(m_timer) * 100 + 600, 150, 50);

	// draw a rotating red box
	//m_2dRenderer->setRenderColour(1, 0, 0, 1);
	//m_2dRenderer->drawBox(600, 500, 60, 20, m_timer);

	// draw a slightly rotated sprite with no texture, colored yellow
	//m_2dRenderer->setRenderColour(1, 1, 0, 1);
	//m_2dRenderer->drawSprite(nullptr, 400, 400, 50, 50, 3.14159f * 0.25f, 1);

	char tick[60];
	sprintf_s(tick, 60, "Time Remaining: %f", m_timer );
	m_2dRenderer->drawText(m_font, tick, 0, 720 - 32);
	m_2dRenderer->drawText(m_font, "Press ESC to Quit" , 0, 720 - 64);

	// output some text, uses the last used colour
	/*char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
	m_2dRenderer->drawText(m_font, "Press ESC to quit!", 0, 720 - 64);*/

	//Win Conditions
	if (shipLived)
	{
		m_2dRenderer->drawSprite(m_Winner, 640, 360, 1280, 720);
	}
	if (mPlayer->isAlive == false)
	{
		m_2dRenderer->drawSprite(m_Loser, 640, 360, 1280, 720);
	}

	// done drawing sprites
	m_2dRenderer->end();
	
}