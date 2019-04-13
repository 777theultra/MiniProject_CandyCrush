#pragma once

#ifdef GameAPI_Exports
#define GameAPI __declspec(dllexport)
#else
#define GameAPI __declspec(dllimport)
#endif

extern "C" GameAPI void Initialize();
extern "C" GameAPI void Restart();
extern "C" GameAPI int GetCandyColor(int, int);
extern "C" GameAPI int GetCandySpecial(int, int);
