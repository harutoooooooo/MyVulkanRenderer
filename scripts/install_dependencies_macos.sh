#!/bin/bash

# Ensure Homebrew is installed
if ! command -v brew &> /dev/null; then
    echo "Homebrew not found. Please install it from https://brew.sh/"
    exit 1
fi

echo "Installing build tools..."
brew install cmake ninja

echo "Installing graphics and math libraries..."
brew install glfw glm

echo "Installing model and data loaders..."
brew install tinyobjloader tinygltf nlohmann-json

echo "Installing Vulkan SDK (includes MoltenVK for macOS)..."
brew install --cask vulkan-sdk

echo "Setting up compiler tools..."
xcode-select --install 2>/dev/null || echo "Compiler tools already present."

echo ""
echo "IMPORTANT: Add these lines to your ~/.zshrc to make it IDE-agnostic:"
echo 'export VULKAN_SDK=/usr/local/share/vulkan/explicit_layer.d'
echo 'export PATH="/usr/local/bin:$PATH"'
echo ""
echo "To build from any terminal (including VSCode terminal):"
echo "cmake -B build -S . -G Ninja"
echo "cmake --build build"