#ifndef DATE_H
#define DATE_H


#include <stdio.h>
#include <math.h>

#include <fstream>
#include <iostream>

#include <sstream>
#include <string>
#include <stdexcept>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>

#include <string>


class ToolsC
{
    public:

    // VBOs and VAOs to store vertex buffers
    GLuint m_VBOs[4], m_VAOs[4];

    // texture ids
    GLuint m_textures[4];

	std::string BASE_PATH;

	const unsigned int SCR_WIDTH = 1280;
	const unsigned int SCR_HEIGHT = 720;

	ToolsC(std::string);

	void loadTextures();

	void initRenderData();

};

#endif
