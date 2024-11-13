/*
 * Created 2024-10-16 09:32:14
 * Author : fengxuegt
 * Email : fengxuegt@163.com
 */

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "check_error.h"
#include "application.h"

GLuint vao, pro;
void onResize(int width, int height);
void OnKey(int key, int action, int mods);
void prepareVBO() {
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f
    };

    GLuint vbo;
    GL_LW_CALL(glGenBuffers(1, &vbo));
    //2 绑定当前vbo，到opengl状态机的当前vbo插槽上
	//GL_ARRAY_BUFFER:表示当前vbo这个插槽
    GL_LW_CALL(glBindBuffer(GL_ARRAY_BUFFER, vbo));
    //3 向当前vbo传输数据，也是在开辟显存
    GL_LW_CALL(glBufferData(GL_ARRAY_BUFFER, sizeof(vertices),vertices, GL_STATIC_DRAW));
    GL_LW_CALL(glDeleteBuffers(1, &vbo));

    GLuint vboArr[3];// = {0, 0, 3};
    GL_LW_CALL(glGenBuffers(3, vboArr));
    GL_LW_CALL(glBindBuffer(GL_ARRAY_BUFFER, vboArr[0]));
    GL_LW_CALL(glBufferData(GL_ARRAY_BUFFER, sizeof(vertices),vertices, GL_STATIC_DRAW));
    GL_LW_CALL(glDeleteBuffers(3, &vbo));

}

GLuint prepareTriVBO() {

    float posColorData[] = {
        -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
        0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
        0.0f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f
    };

    // 创建VAO
    GLuint triVAO = 0;
    glGenVertexArrays(1, &triVAO);
    glBindVertexArray(triVAO);

    // 创建并绑定VBO
    GLuint triVBO = 0;
    GL_LW_CALL(glGenBuffers(1, &triVBO));
    GL_LW_CALL(glBindBuffer(GL_ARRAY_BUFFER, triVBO));
    GL_LW_CALL(glBufferData(GL_ARRAY_BUFFER, sizeof(posColorData), posColorData, GL_STATIC_DRAW));

    // 描述位置数据
    GL_LW_CALL(glEnableVertexAttribArray(0));
    GL_LW_CALL(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GL_FLOAT), (void*)0));

    // 描述颜色数据
    GL_LW_CALL(glEnableVertexAttribArray(1));
    GL_LW_CALL(glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GL_FLOAT), (void*)(3 * sizeof(GL_FLOAT))));
    std::cout << "777" << std::endl;
    // glDeleteVertexArrays(1, &triVAO);
    GL_LW_CALL(glBindVertexArray(0));
    std::cout << "777" << std::endl;
    return triVAO;
}

GLuint prepareShader() {
    //1 完成vs与fs的源代码，并且装入字符串
    const char* vertexShaderSource =
        "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "layout (location = 1) in vec3 aColor;\n"
        "out vec3 outColor;"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "   outColor = aColor;\n"
        "}\0";
    const char* fragmentShaderSource =
        "#version 330 core\n"
        "out vec4 FragColor;\n"
        "in vec3 outColor;\n"
        "void main()\n"
        "{\n"
        "   FragColor = vec4(outColor, 1.0f);\n"
        "}\n\0";
    GLuint vs =  glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &vertexShaderSource, NULL);
    GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, &fragmentShaderSource, NULL);
    glCompileShader(vs);
    //检查vertex编译结果
    int success = 0;
    char infoLog[1024];
    glGetShaderiv(vs, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vs, 1024, NULL, infoLog);
        std::cout << "Error: SHADER COMPILE ERROR --VERTEX" << "\n" << infoLog << std::endl;
    }
    glCompileShader(fs);
    //检查fragment编译结果
    glGetShaderiv(fs, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fs, 1024, NULL, infoLog);
        std::cout << "Error: SHADER COMPILE ERROR --Fragment" << "\n" << infoLog << std::endl;
    }

    GLuint pro =  glCreateProgram();
    glAttachShader(pro, vs);
    glAttachShader(pro, fs);

    glLinkProgram(pro);
    return pro;

}

void render() {
    // 渲染指令
    GL_LW_CALL(glClear(GL_COLOR_BUFFER_BIT));
    glUseProgram(pro);
    GL_LW_CALL(glBindVertexArray(vao));
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

int main() {
    if (!lwapp->init(800, 600, "HelloTriangle")) {
        return -1;
    }
    // 设置回调函数
    lwapp->setResizeCallback(onResize);
    lwapp->setKeyBoardCallback(OnKey);

    GL_LW_CALL(glClearColor(0.2f, 0.3f, 0.3f, 1.0));
    // prepareVBO();

    vao = prepareTriVBO();
    pro = prepareShader();

    // 主循环
    while (lwapp->update()) {
        render();
    }

    
    return 0;
}

void onResize(int width, int height) {
    GL_LW_CALL(glViewport(0, 0, width, height));
}

void OnKey(int key, int action, int mods) {
}
