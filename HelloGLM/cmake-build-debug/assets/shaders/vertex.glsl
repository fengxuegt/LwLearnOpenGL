#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 uvCor;
out vec2 uvPos;
uniform mat4 transform;
uniform float time;
void main()
{
   vec4 pos = vec4(aPos.x, aPos.y, aPos.z, 1.0);
   uvPos = uvCor;
   gl_Position = transform * pos;
}