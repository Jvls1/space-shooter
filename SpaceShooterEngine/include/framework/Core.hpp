#pragma once
#include <stdio.h>
#include <memory>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace ss {
    template<typename T>
    using unique = std::unique_ptr<T>;

    template<typename T>
    using shared = std::shared_ptr<T>;

    template<typename T>
    using weak = std::weak_ptr<T>;

    template<typename T>
    using List = std::vector<T>;

    template<typename K, typename V, typename P = std::less<K>>
    using Map = std::map<K, V, P>;

    template<typename K, typename V, typename H = std::hash<K>>
    using Dictionary = std::unordered_map<K, V, H>;

    template<typename T>
    using Set = std::unordered_set<T>;

    using uint8 = unsigned char;
    
    #define LOG(M, ...) printf(M "\n", ##__VA_ARGS__)
}