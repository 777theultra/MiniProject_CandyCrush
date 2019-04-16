#pragma once

#ifdef GameAPI_Exports
#define GameAPI __declspec(dllexport)
#else
#define GameAPI __declspec(dllimport)
#endif

static void (*RenderApplication)();
static void (*AwardPoints)(int points);
static void (*ObjectiveComplete)(int id);
void AppRenderApplication();
void AppAwardPoints(int);
void AppSetObjectiveCompleted(int);

extern "C" {
	//API
	GameAPI void Initialize();
	GameAPI void Restart();
	GameAPI void ConnectRenderer(void (*f)());
	GameAPI void ConnectAwardPoints(void (*f)(int));
	GameAPI void ConnectObjectiveComplete(void (*f)(int));
	GameAPI void CandyMove(int, int, int);
	GameAPI int GetCandy(int, int);
	GameAPI int GetObjectiveBColor();
	GameAPI int GetObjectiveBAmount();
	GameAPI int GetObjectiveDCombo();
	GameAPI int GetObjectiveDAmount();

	//Debug
	GameAPI void DebugBoard();
}
