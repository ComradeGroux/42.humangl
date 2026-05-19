#version 460 core

layout (location = 0) in vec3 aPosition;

uniform mat4 uMVP_matrix;

void	main()
{
	gl_Position = uMVP_matrix * vec4(aPosition, 1.0);
}
