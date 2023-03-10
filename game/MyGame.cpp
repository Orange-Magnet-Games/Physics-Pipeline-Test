#include "stdafx.h"
#include "MyGame.h"

CMyGame::CMyGame(void) :
	ball(400, 500, 50, 50, CColor::Blue(), 0)
	// to initialise more sprites here use a comma-separated list
{
	// TODO: add initialisation here
}
CSpriteRect* CMyGame::MakeBox(CVector location, CVector scale, float angle, CColor color) {
	CSpriteRect* box = new CSpriteRect(location, scale.X(), scale.Y(), color, GetTime());
	box->SetRotation(angle);
	boxes.emplace_back(box);
	return box;

}

CMyGame::~CMyGame(void)
{
	// TODO: add destruction code here
}

/////////////////////////////////////////////////////
// Per-Frame Callback Funtions (must be implemented!)

// one time initialisation
void CMyGame::OnInitialize()
{
	auto box = MakeBox(CVector(400, 300), CVector(500, 100), 30, CColor::Green());

	box->SetOmega(50);
	//ball.Accelerate(300, 1000);
	MakeBox(CVector(0, 300), CVector(50, 700), 0, CColor::Red());;
	MakeBox(CVector(800, 300), CVector(50, 700), 0, CColor::Red());;
	MakeBox(CVector(400, 0), CVector(900, 50), 0, CColor::Red());;
	MakeBox(CVector(400, 600), CVector(900, 50), 0, CColor::Red());;
}
void BounceTest(CSpriteOval* ball, CSprite* box, float delta, float e) {
	CVector v = ball->GetVelocity() * delta / 1000;
	float a = box->GetRotation();
	a = DEG2RAD(a);
	float R = ball->GetWidth() / 2;
	float X = box->GetWidth() / 2;
	float Y = box->GetHeight() / 2;
	CVector t = box->GetPos() - ball->GetPos();
	CVector nList[4] = { CVector(sin(a), cos(a)),
						 CVector(cos(a), -sin(a)),
						 CVector(-sin(a), -cos(a)),
						 CVector(-cos(a), sin(a)) };
	int count = 0;
	/*for (CVector n : nList) {
		if (Dot(v, n) < 0) {
			float vy = Dot(v, n);

			float dif = count % 2 == 0 ? (Y) : (X) + R;
			float adif = count % 2 == 0 ? (X) : (Y) + R;
			CVector d = count <= 1 ? (t + dif * n) : (-t - dif * n);
			float ty = Dot(d, n);

			float vx = Cross(v, n);
			float tx = Cross(t, n);

			float f1 = ty / vy;


			float f2 = (tx - vx * f1) / adif;



			if (f1 >= 0 && f1 <= 1 && f2 >= -1 && f2 <= 1) ball->SetVelocity(Reflect(ball->GetVelocity() * e, n));
			count++;
			//ball.SetPos(ball.GetPos() + n * CVector(box.GetWidth()/2, box.GetHeight()/2) - n * ball.GetWidth());
			//if(n == nList[0]) ball.SetPos(box->GetTopLocal()-(ball.GetPos()-box->GetPos()).Length())
		}

	}*/
	CVector n = nList[0];
	if (Dot(v, n) < 0) {
		float vy = Dot(v, n);

		float dif = Y + R;
		float adif = X + R;
		CVector d = t + dif * n;
		float ty = Dot(d, n);

		float vx = Cross(v, n);
		float tx = Cross(t, n);

		float f1 = ty / vy;


		float f2 = (tx - vx * f1) / adif;



		if (f1 >= 0 && f1 <= 1 && f2 >= -1 && f2 <= 1) ball->SetVelocity(Reflect(ball->GetVelocity() * e, n));
		//ball.SetPos(ball.GetPos() + n * CVector(box.GetWidth()/2, box.GetHeight()/2) - n * ball.GetWidth());
		//if(n == nList[0]) ball.SetPos(box->GetTopLocal()-(ball.GetPos()-box->GetPos()).Length())
	}

	n = nList[1];
	if (Dot(v, n) < 0) {
		float vy = Dot(v, n);
		float dif = X + R;
		float adif = Y + R;
		CVector d = t + dif * n;
		float ty = Dot(d, n);

		float vx = Cross(v, n);
		float tx = Cross(t, n);

		float f1 = ty / vy;


		float f2 = (tx - vx * f1) / adif;



		if (f1 >= 0 && f1 <= 1 && f2 >= -1 && f2 <= 1) ball->SetVelocity(Reflect(ball->GetVelocity() * e, n));
		//ball.SetPos(ball.GetPos() + n * CVector(box.GetWidth()/2, box.GetHeight()/2) - n * ball.GetWidth());
		//if(n == nList[0]) ball.SetPos(box->GetTopLocal()-(ball.GetPos()-box->GetPos()).Length())
	}

	n = nList[2];
	if (Dot(v, n) < 0) {
		float vy = Dot(v, n);
		float dif = Y + R;
		float adif = X + R;
		CVector d = -t - dif * n;
		float ty = Dot(d, n);

		float vx = Cross(v, n);
		float tx = Cross(t, n);

		float f1 = ty / vy;


		float f2 = (tx + vx * f1) / adif;



		if (f1 >= -1 && f1 <= 0 && f2 >= -1 && f2 <= 1) ball->SetVelocity(Reflect(ball->GetVelocity() * e, n));
		//ball.SetPos(ball.GetPos() + n * CVector(box.GetWidth()/2, box.GetHeight()/2) - n * ball.GetWidth());
		//if(n == nList[0]) ball.SetPos(box->GetTopLocal()-(ball.GetPos()-box->GetPos()).Length())
	}


	n = nList[3];
	if (Dot(v, n) < 0) {
		float vy = Dot(v, n);
		float dif = X + R;
		float adif = Y + R;
		CVector d = -t - dif * n;
		float ty = Dot(d, n);

		float vx = Cross(v, n);
		float tx = Cross(t, n);

		float f1 = ty / vy;


		float f2 = (tx + vx * f1) / adif;



		if (f1 >= -1 && f1 <= 0 && f2 >= -1 && f2 <= 1) ball->SetVelocity(Reflect(ball->GetVelocity() * e, n));
		//ball.SetPos(ball.GetPos() + n * CVector(box.GetWidth()/2, box.GetHeight()/2) - n * ball.GetWidth());
		//if(n == nList[0]) ball.SetPos(box->GetTopLocal()-(ball.GetPos()-box->GetPos()).Length())
	}
}
void CMyGame::OnUpdate()
{
	Uint32 time = GetTime();
	ball.SetYVelocity(ball.GetYVelocity() - 9.81);
	for (auto box : boxes) {
		BounceTest(&ball, box, GetDeltaTime(), 1);
	}


	ball.Update(time);
	for (auto i : boxes) i->Update(time);

}

void CMyGame::OnDraw(CGraphics* g)
{
	// TODO: add drawing code here
	ball.Draw(g);
	for (auto i : boxes) i->Draw(g);

	// this will print the game time
	*g << bottom << left << "Time elapsed: " << timetext(GetTime());
}

/////////////////////////////////////////////////////
// Game Life Cycle



// called when a new game is requested (e.g. when F2 pressed)
// use this function to prepare a menu or a welcome screen
void CMyGame::OnDisplayMenu()
{
	StartGame();	// exits the menu mode and starts the game mode
}

// called when a new game is started
// as a second phase after a menu or a welcome screen
void CMyGame::OnStartGame()
{
}

// called when a new level started - first call for nLevel = 1
void CMyGame::OnStartLevel(Sint16 nLevel)
{
}

// called when the game is over
void CMyGame::OnGameOver()
{
}

// one time termination code
void CMyGame::OnTerminate()
{
}

/////////////////////////////////////////////////////
// Keyboard Event Handlers

void CMyGame::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode)
{
	if (sym == SDLK_F4 && (mod & (KMOD_LALT | KMOD_RALT)))
		StopGame();
	if (sym == SDLK_SPACE)
		PauseGame();
	if (sym == SDLK_F2)
		NewGame();
}

void CMyGame::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode)
{
}


/////////////////////////////////////////////////////
// Mouse Events Handlers

void CMyGame::OnMouseMove(Uint16 x, Uint16 y, Sint16 relx, Sint16 rely, bool bLeft, bool bRight, bool bMiddle)
{
}

void CMyGame::OnLButtonDown(Uint16 x, Uint16 y)
{
}

void CMyGame::OnLButtonUp(Uint16 x, Uint16 y)
{
}

void CMyGame::OnRButtonDown(Uint16 x, Uint16 y)
{
}

void CMyGame::OnRButtonUp(Uint16 x, Uint16 y)
{
}

void CMyGame::OnMButtonDown(Uint16 x, Uint16 y)
{
}

void CMyGame::OnMButtonUp(Uint16 x, Uint16 y)
{
}
