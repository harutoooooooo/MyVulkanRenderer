#pragma once

#include "core/pipeline.h"
#include "core/window.h"

namespace mvr
{

class FirstApp
{
  public:
	static constexpr uint32_t WIDTH  = 800;
	static constexpr uint32_t HEIGHT = 600;

	void run();

  private:
	Window   window{WIDTH, HEIGHT, "MyVulkanRenderer"};
	Pipeline pipeline{"../shaders/simple_shader.vert.spv",
	                  "../shaders/simple_shader.frag.spv"};
};

}        // namespace mvr