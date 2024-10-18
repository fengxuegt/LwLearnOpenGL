/*
 * Created 2024-10-17 16:59:53
 * Author : fengxuegt
 * Email : fengxuegt@163.com
 */

#version 460 core
out vec4 FragColor;
in vec3 color;
void main()
{
   FragColor = vec4(color, 1.0f);
}