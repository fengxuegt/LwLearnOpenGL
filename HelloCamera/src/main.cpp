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

#include "gamecameracontrol.h"
#include "perspectiveCamera.h"
#include "stb_image.h"
#include "texture.h"
#include "trackballcameracontrol.h"

#include "camera/camera.h"
#include "camera/cameracontrol.h"

Camera *camera = nullptr;
CameraControl *cameraControl = nullptr;

GLuint vao, pro;
GLuint texture1, texture2;
Shader* shader = nullptr;
glm::mat4 orthographicMatrix(1.0f);
glm::mat4 perspectiveMatrix(1.0f);
void onResize(int width, int height);
void OnKey(int key, int action, int mods);
void OnMouse(int button, int action, int mods);
void OnCursor(double x, double y);
void OnScroll(double y);

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
    shader->setMat4("viewMatrix", camera->getViewMatrix());

    // orthographicMatrix
    shader->setMat4("orthographicMatrix", orthographicMatrix);

    // perspectiveMatrix
    shader->setMat4("perspectiveMatrix", camera->getProjectionMatrix());

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

    // 透视投影相机
    camera = new PerspectiveCamera(
        60.0f,
        (float)lwapp->getWidth() / (float)lwapp->getHeight(),
        0.1f,
        1000.0f
    );

    // 正交投影相机
    // float size = 6.0f;
    // camera = new OrthographicCamera(-size, size, size, -size, size, -size);

    // cameraControl = new TrackBallCameraControl();
    cameraControl = new GameCameraControl();
    cameraControl->setCamera(camera);
}


int main() {
    if (!lwapp->init(800, 600, "HelloCamera")) {
        return -1;
    }
    // 设置回调函数
    lwapp->setResizeCallback(onResize);
    lwapp->setKeyBoardCallback(OnKey);
    lwapp->setMouseCallback(OnMouse);
    lwapp->setCursorCallback(OnCursor);
    lwapp->setScrollCallback(OnScroll);

    GL_LW_CALL(glClearColor(0.2f, 0.3f, 0.3f, 1.0));

    vao = prepareTriVBO();
    prepareTexture();
    prepareShaderClass();
    prepareCamera();
    
    // 主循环
    while (lwapp->update()) {
        cameraControl->update();
        render();
    }
    lwapp->destroy();
    
    return 0;
}

void onResize(int width, int height) {
    GL_LW_CALL(glViewport(0, 0, width, height));

}

void OnKey(int key, int action, int mods) {
    cameraControl->onKey(key, action, mods);
}
void OnMouse(int button, int action, int mods) {
    // if (action == GLFW_PRESS) {
    //     if (button == GLFW_MOUSE_BUTTON_LEFT) {
    //         std::cout << "Mouse Left Down" << std::endl;
    //     } else if (button == GLFW_MOUSE_BUTTON_RIGHT) {
    //         std::cout << "Mouse Right Down" << std::endl;
    //     } else if (button == GLFW_MOUSE_BUTTON_MIDDLE) {
    //         std::cout << "Mouse Middle Down" << std::endl;
    //     }
    // }
    double x, y;
    lwapp->getCursorPosition(&x, &y);
    cameraControl->onMouse(button, action, x, y);
}

void OnCursor(double x, double y) {
    cameraControl->onCursor(x, y);
}

void OnScroll(double y) {
    cameraControl->onScroll(y);
}