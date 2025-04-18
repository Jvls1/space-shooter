#pragma once
#include "SFML/Graphics.hpp"
#include "framework/Core.hpp"

namespace ss {
    class AssetManager {
    public:
        static AssetManager& Get();
        shared<sf::Texture> LoadTexture(const std::string& path);
        void CleanCycle();
        void SetAssetRootDirectory(const std::string& directory);
    protected:
        AssetManager();
    private:
        static unique<AssetManager> assetManager;
        Dictionary<std::string, shared<sf::Texture>> mLoadedTextureMap;
        std::string mRootDirectory;
    };
}