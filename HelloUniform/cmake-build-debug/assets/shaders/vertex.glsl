#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
out vec3 color;
out vec3 pos;
uniform float time;
void main()
{
   gl_Position = vec4(aPos.x + sin(time), aPos.y, aPos.z, 1.0);
   pos = aPos;
   //color = aColor;
   color = aColor * (sin(time) + 1.0) / 2.0;
}