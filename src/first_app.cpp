#include "first_app.h"

namespace mvr
{

void FirstApp::run()
{
	while (!window.shouldClose()) {
		glfwPollEvents();
	}
}

}        // namespace mvr