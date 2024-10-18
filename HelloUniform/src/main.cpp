/*
 * Created 2024-10-16 09:32:14
 * Author : fengxuegt
 * Email : fengxuegt@163.com
 */

#include "core.h"
#include <iostream>
#include "check_error.h"
#include "application.h"
#include "shader.h"

GLuint vao, pro;

Shader* shader = nullptr;
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

    // 动态获取描述位置数据
    // GLuint posLocation = glGetAttribLocation(0, "aPos"); 这里由于无法获取pro，所以先不测试了

    // 描述颜色数据
    GL_LW_CALL(glEnableVertexAttribArray(1));
    GL_LW_CALL(glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GL_FLOAT), (void*)(3 * sizeof(GL_FLOAT))));
    // glDeleteVertexArrays(1, &triVAO);
    GL_LW_CALL(glBindVertexArray(0));
    return triVAO;
}


void prepareShaderClass() {
    shader = new Shader("assets/shaders/vertex.glsl","assets/shaders/fragment.glsl");
}
void render() {
    // 渲染指令
    GL_LW_CALL(glClear(GL_COLOR_BUFFER_BIT));
    shader->begin();

    shader->setFloat("time", glfwGetTime());
    std::cout << glfwGetTime() << std::endl;

    GL_LW_CALL(glBindVertexArray(vao));
    glDrawArrays(GL_TRIANGLES, 0, 3);
    GL_LW_CALL(glBindVertexArray(0));
    
    shader->end();
}

int main() {
    if (!lwapp->init(800, 600, "HelloUniform")) {
        return -1;
    }
    // 设置回调函数
    lwapp->setResizeCallback(onResize);
    lwapp->setKeyBoardCallback(OnKey);

    GL_LW_CALL(glClearColor(0.2f, 0.3f, 0.3f, 1.0));
    // prepareVBO();

    vao = prepareTriVBO();
    prepareShaderClass();
    
    // 主循环
    while (lwapp->update()) {
        render();
    }
    lwapp->destroy();
    
    return 0;
}

void onResize(int width, int height) {
    GL_LW_CALL(glViewport(0, 0, width, height));
}

void OnKey(int key, int action, int mods) {
}
