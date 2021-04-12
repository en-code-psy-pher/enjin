#ifndef POINTRENDER_H
#define POINTRENDER_H

#include "../core/config.h"
#include "../renderer/renderObject.h"

class PointRender
{
public:
	PointRender();
	~PointRender();

	void Update();
	void Render();

private:
	RenderObject	m_renderObject;
};

#endif	// POINTRENDER_H
