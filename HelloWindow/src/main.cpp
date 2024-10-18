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

void onResize(int width, int height);
void OnKey(int key, int action, int mods);


int main() {
    if (!lwapp->init(800, 600, "LWAPP")) {
        return -1;
    }

    lwapp->sayHello();
    lwapp->setResizeCallback(onResize);
    lwapp->setKeyBoardCallback(OnKey);

    GL_LW_CALL(glClearColor(0.2f, 0.3f, 0.3f, 1.0));

    // 主循环
    while (lwapp->update()) {
        // 渲染指令
        GL_LW_CALL(glClear(GL_COLOR_BUFFER_BIT));
    }

    
    return 0;
}

void onResize(int width, int height) {
    GL_LW_CALL(glViewport(0, 0, width, height));
    std::cout << "onResize" << std::endl;
}

void OnKey(int key, int action, int mods) {
    std::cout << "onKey()" << std::endl;
	std::cout << key << std::endl;
}
