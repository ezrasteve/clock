#pragma once

//------------------------------------------------------------------------------
//
// File Name:	Lab1.cpp
// Author(s):	Jeremy Kings (j.kings), Ezra Stevens
// Project:		Lab1
// Course:		MAT140
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#include "stdafx.h"
#include "Lab1.h"

#include "DebugDraw.h" // AddDebugLine
#include "Vector2D.h"  // Vector2D
#include "GraphicsEngine.h"  // SetBackgroundColor

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

using namespace Beta;

// Constructor: Initialize helpful variables declared in Lab1.h.
Lab1::Lab1()
	: BetaObject("Level:Lab1"), pi(static_cast<float>(M_PI)), lineLength(2.0f),
	rotationalVelocity((2.0f * pi) / 60.0f),
	angle1(pi / 2.0f), angle2(pi / 2.0f), angle3(pi / 2.0f)
{

}

// Initialize the Lab1 level.
void Lab1::Initialize()
{
	//confirm initialization
	printf("initialize boy\n");

	//set the background color to white
	EngineGetModule(Beta::GraphicsEngine)->SetBackgroundColor(Beta::Colors::White);
}

// Update the Lab1 level.
// Params:
//	 dt = Change in time (in seconds) since the last game loop.
void Lab1::Update(float dt)
{
	//store the initial position for all lines and circle
	Beta::Vector2D initialposition(0, 0);
	//get the angles that rotate based on delta time
	angle1 -= rotationalVelocity * dt;
	angle2 -= (rotationalVelocity / 60.0f) * dt;
	angle3 -= (rotationalVelocity / 720.0f) * dt;
	//store the endpoints for all lines based on their respective angles
	Beta::Vector2D end1(initialposition.x + lineLength * cosf(angle1), initialposition.y + lineLength * sinf(angle1));
	Beta::Vector2D end2(initialposition.x + lineLength * cosf(angle2), initialposition.y + lineLength * sinf(angle2));
	Beta::Vector2D end3(initialposition.x + lineLength * cosf(angle3), initialposition.y + lineLength * sinf(angle3));
	
	//draws a circle the same length as the lines
	EngineGetModule(Beta::DebugDraw)->DebugDraw::AddCircle(initialposition, lineLength, Beta::Colors::Black);

	//draw all three lines from their starts to ends
	EngineGetModule(Beta::DebugDraw)->AddLineToList(initialposition, end1, Beta::Colors::Red);
	EngineGetModule(Beta::DebugDraw)->AddLineToList(initialposition, end2, Beta::Colors::Green);
	EngineGetModule(Beta::DebugDraw)->AddLineToList(initialposition, end3, Beta::Colors::Blue);
	
	//end the line list
	EngineGetModule(Beta::DebugDraw)->EndLineList();
}

// Shut down the Lab1 level.
void Lab1::Shutdown()
{
	//print shutdown when the project closes
	printf("shutdown\n");
}
