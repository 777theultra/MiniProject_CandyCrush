#pragma once

#ifdef GameAPI_Exports
#define GameAPI __declspec(dllexport)
#else
#define GameAPI __declspec(dllimport)
#endif

void AppRender();
void AppAwardPoints(int);

static void (*ApplicationRender)();
static void (*ApplicationAwardPoints)(int points);

extern "C" {
	//API
	GameAPI void Initialize();
	GameAPI void Restart();
	GameAPI void ConnectRenderer(void (*f)());
	GameAPI void ConnectAwardPoints(void (*f)(int));
	GameAPI void CandyMove(int, int, int);
	GameAPI int GetCandyColor(int, int);
	GameAPI int GetCandySpecial(int, int);

	//Debug
	GameAPI void DebugBoard();
}
