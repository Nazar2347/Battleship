#pragma once
#include "VisualConfigs.h"
#include <raylib.h>
#include "GameRules.h"

bool isMouseOverEnemyBoard(Vector2 mousePos);
bool isMouseOverPlayerBoard(Vector2 mousePos);

void DrawHitMark(const Coordinate& coord, Vector2 boardOrigin);
void DrawMissMark(const Coordinate& coord, Vector2 boardOrigin);

void DrawWinMessage();
void DrawLoseMessage();
void DrawInitializationMessage();
void DrawFightMessage();
void DrawChangeOrientationMessage();