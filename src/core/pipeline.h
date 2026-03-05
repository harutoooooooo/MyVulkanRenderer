#pragma once

#include "vulkan_device.h"

// std
#include <string>
#include <vector>
#include <vulkan/vulkan_core.h>

namespace mvr
{

struct PipelineConfigInfo {
};

class Pipeline
{
  public:
	Pipeline(
	    VulkanDevice             &device,
	    const std::string        &vertFilePath,
	    const std::string        &fragFilePath,
	    const PipelineConfigInfo &configInfo);
	~Pipeline()
	{}

	Pipeline(const Pipeline &)            = delete;
	Pipeline &operator=(const Pipeline &) = delete;

	static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width, uint32_t height);

  private:
	static std::vector<char> readFile(const std::string &filePath);
	void                     createGraphicsPipeline(const std::string        &vertFilePath,
	                                                const std::string        &fragFilePath,
	                                                const PipelineConfigInfo &configInfo);
	void                     createShaderModule(const std::vector<char> &code, VkShaderModule *shaderModule);

	VulkanDevice  &device;
	VkPipeline     graphicsPipeline;
	VkShaderModule vertexShaderModule;
	VkShaderModule fragmentShaderModule;
};

}        // namespace mvr