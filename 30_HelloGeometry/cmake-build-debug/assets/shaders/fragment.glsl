#version 330 core
out vec4 FragColor;
in vec2 uvPos;

uniform sampler2D texture1;
uniform sampler2D texture2;
void main()
{
  FragColor = mix(texture(texture1, uvPos), texture(texture2, uvPos), 1.0);
}