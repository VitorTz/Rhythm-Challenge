#ifndef A376CF98_FC68_4ACE_B5E4_416B6AAFC61F
#define A376CF98_FC68_4ACE_B5E4_416B6AAFC61F
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <filesystem>
#include <memory>
#include <map>


class TexturePool {


    private:
        static std::map<std::filesystem::path, std::unique_ptr<sf::Texture>> textureMap;
    
    public:
        static void load(sf::Sprite* sprite, const std::filesystem::path& source);
        static void erase(const std::filesystem::path& source);

};

#endif /* A376CF98_FC68_4ACE_B5E4_416B6AAFC61F */
