#include "ViewPlane.h"

USING_RDPS
USING_FRWK

ViewPlane::ViewPlane(const int _width, 
				     const int _height) :
		   width(_width),
		   height(_height),
		   sp(RT::Vec2f(1.0f, 1.0f))
{}

ViewPlane::~ViewPlane()
{}

int ViewPlane::GetWidth() const
{
	return width;
}

int ViewPlane::GetHeight() const
{
	return height;
}

RT::Vec2f ViewPlane::GetSizePixel() const
{
	return sp;
}
