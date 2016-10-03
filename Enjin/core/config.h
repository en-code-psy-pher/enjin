#ifndef CONFIG_H
#define CONFIG_H

// GLEW
#define GLEW_STATIC
#include "glew.h"

// GLFW
#include "glfw3.h"

#include <iostream>
#include <cassert>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

// GLM
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/quaternion.hpp"
#include "glm/gtx/quaternion.hpp"
#include "glm/gtc/type_ptr.hpp"

// Define Constants
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

// Debug Macros
#define DEBUG(x) do { std::cerr << x; } while (0)

// Langauage Specific typedef's
typedef unsigned short	ushort;
typedef unsigned char	uchar;

// OGL API Specific typedef's

// GLM Library Specific typedef's
typedef glm::vec2		vec2;
typedef glm::vec3		vec3;
typedef glm::vec4		vec4;
typedef glm::mat3		mat3;
typedef glm::mat4		mat4;
typedef glm::quat		quat;
typedef glm::dquat		dquat;

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;

#endif // CONFIG_H