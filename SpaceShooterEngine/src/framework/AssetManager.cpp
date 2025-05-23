#include "framework/AssetManager.hpp"

namespace ss {
    unique<AssetManager> AssetManager::assetManager = nullptr;

    AssetManager::AssetManager()
        :mRootDirectory{} {
    }

    AssetManager& AssetManager::Get() {
        if (!assetManager) {
            assetManager = unique<AssetManager>{new AssetManager};
        }
        return *assetManager;
    }

    shared<sf::Texture> AssetManager::LoadTexture(const std::string& path) {
        auto found = mLoadedTextureMap.find(path);
        if (found != mLoadedTextureMap.end()) {
            return found->second;
        }

        shared<sf::Texture> newTexture{new sf::Texture};
        if (newTexture->loadFromFile(mRootDirectory + path)) {
            mLoadedTextureMap.insert({path, newTexture});
            return newTexture;
        }

        return shared<sf::Texture> {nullptr};
    }

    void AssetManager::CleanCycle() {
        for (auto i = mLoadedTextureMap.begin(); i != mLoadedTextureMap.end();) {
            if (i->second.unique()) {
                i = mLoadedTextureMap.erase(i);
            } else {
                ++i;
            }
        }
    }

    void AssetManager::SetAssetRootDirectory(const std::string& directory) {
        mRootDirectory = directory;
    }
}