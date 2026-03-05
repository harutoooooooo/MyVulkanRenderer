#pragma once

#include "core/pipeline.h"
#include "core/vulkan_device.h"
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
	Window       window{WIDTH, HEIGHT, "MyVulkanRenderer"};
	VulkanDevice device{window};
	Pipeline     pipeline{
        device,
        "../shaders/simple_shader.vert.spv",
        "../shaders/simple_shader.frag.spv",
        Pipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT)};
};

}        // namespace mvr