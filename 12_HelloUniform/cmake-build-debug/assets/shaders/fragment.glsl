#version 330 core
out vec4 FragColor;
in vec3 color;
in vec3 pos;
uniform vec3 uniColor; // 向量形式的颜色
void main()
{
  // FragColor = vec4(color, 1.0f);
  // FragColor = vec4(pos, 1.0f);
  FragColor = vec4(uniColor, 1.0f);

}