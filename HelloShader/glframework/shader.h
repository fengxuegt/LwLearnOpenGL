/*
 * Created 2024-10-17 16:19:42
 * Author : fengxuegt
 * Email : fengxuegt@163.com
 */
#pragma once
#include "core.h"
#include <string>
class Shader
{

private:
    GLuint pro{0};
    void checkShaderErrors(GLuint targert, std::string type);
    
public:
    Shader(const char *vertexPath, const char *fragmentPath);
    ~Shader();
    void begin(); // 开始使用当前Shader
    void end(); // 停止使用当前Shader
};



