#pragma once
#include "glut.h"

static GLboolean lightSwitch = GL_TRUE;
static int directionalLight = 0;

/* Time varying or user-controled variables. */

static float lightAngle = 180.0;

static GLfloat lightPosition[4];
static GLfloat lightColor[] = { 1.0f, 1.0f, 0.8f }; // green-tinted
