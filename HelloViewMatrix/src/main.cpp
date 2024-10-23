/*
 * Created 2024-10-16 09:32:14
 * Author : fengxuegt
 * Email : fengxuegt@163.com
 */

#include "core.h"
#include "check_error.h"
#include "application.h"
#include "shader.h"
#define STB_IMAGE_IMPLEMENTATION  // 这个地方定义了一个宏，如果不定义的话会报错，但是不知道什么原因
#include <iostream>
#include <ostream>

#include "stb_image.h"
#include "texture.h"

GLuint vao, pro;
GLuint texture1, texture2;
Shader* shader = nullptr;
glm::mat4 transform(1.0f);
glm::mat4 viewMatrix(1.0f);
void onResize(int width, int height);
void OnKey(int key, int action, int mods);

GLuint prepareTriVBO() {

    float posColorData[] = {
        -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, // 左下角
        -0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, // 左上角
        0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, // 右上角

        0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, // 右上角
        0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // 右下角
        -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f// 左下角
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
    GL_LW_CALL(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GL_FLOAT), (void*)0));

    // 动态获取描述位置数据
    // GLuint posLocation = glGetAttribLocation(0, "aPos"); 这里由于无法获取pro，所以先不测试了

    // 描述颜色数据
    GL_LW_CALL(glEnableVertexAttribArray(1));
    GL_LW_CALL(glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GL_FLOAT), (void*)(3 * sizeof(GL_FLOAT))));
    // glDeleteVertexArrays(1, &triVAO);

    // 描述纹理坐标
    GL_LW_CALL(glEnableVertexAttribArray(2));
    GL_LW_CALL(glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GL_FLOAT), (void*)(6 * sizeof(GL_FLOAT))));
    GL_LW_CALL(glBindVertexArray(0));
    return triVAO;
}

void prepareTexture() {
    Texture* textureObj1 = new Texture("assets/textures/container.jpg", 0);
    Texture* textureObj2 = new Texture("assets/textures/awesomeface.png", 1);
}

void prepareShaderClass() {

    shader = new Shader("assets/shaders/vertex.glsl","assets/shaders/fragment.glsl");
}

void render() {
    // 渲染指令
    GL_LW_CALL(glClear(GL_COLOR_BUFFER_BIT));
    shader->begin();
    shader->setFloat("time", glfwGetTime());

    shader->setVec3("uniColor", 0.5f, 0.5f, 0.5f);
    shader->setInt("texture1",0);
    shader->setInt("texture2",1);
    glm::mat4 transform = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    shader->setMat4("transform", transform);

    // viewMatrix
    shader->setMat4("viewMatrix", viewMatrix);

    GL_LW_CALL(glBindVertexArray(vao));
    glDrawArrays(GL_TRIANGLES, 0, 6);
    GL_LW_CALL(glBindVertexArray(0));
    
    shader->end();
}

void prepareCamera() {
    // lookat函数：生成一个matrix矩阵
    // 参数说明：
    /*
     *eye : 摄像机所在的位置
     *center： 当摄像机看向的那个点
     *up：穹顶向量
     */
    viewMatrix = glm::lookAt(glm::vec3(0.0f, 0.0f, 0.5f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

}

int main() {
    if (!lwapp->init(800, 600, "HelloViewMatrix")) {
        return -1;
    }
    // 设置回调函数
    lwapp->setResizeCallback(onResize);
    lwapp->setKeyBoardCallback(OnKey);

    GL_LW_CALL(glClearColor(0.2f, 0.3f, 0.3f, 1.0));

    vao = prepareTriVBO();
    prepareTexture();
    prepareShaderClass();
    prepareCamera();
    
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
