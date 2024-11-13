/*
 * Created 2024-10-17 17:00:00
 * Author : fengxuegt
 * Email : fengxuegt@163.com
 */

#version 460 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
out vec3 color;
void main()
{
   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
   color = aColor;
}