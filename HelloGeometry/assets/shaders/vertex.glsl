#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 uvCor;
out vec2 uvPos;
uniform mat4 transform;
uniform mat4 viewMatrix;
uniform mat4 orthographicMatrix;
uniform mat4 perspectiveMatrix;
void main()
{
   vec4 pos = vec4(aPos.x, aPos.y, aPos.z, 1.0);
   uvPos = uvCor;
   gl_Position = perspectiveMatrix * viewMatrix * transform * pos;
}