#version 330 core
out vec4 FragColor;
in vec3 color;
in vec3 pos;
in vec2 uvPos;
uniform vec3 uniColor; // 向量形式的颜色
uniform sampler2D texture1;
uniform sampler2D texture2;
void main()
{
  // FragColor = texture(texture1, uvPos);
  FragColor = mix(texture(texture1, uvPos), texture(texture2, uvPos), 0.2);
}