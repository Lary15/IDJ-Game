#ifndef __RESOURCES_H__
#define __RESOURCES_H__

#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER

#include "SDL_include.h"

#include <string>
#include <unordered_map>

class Resources
{
  private:
    /* Atributos privados */
    static std::unordered_map<std::string, SDL_Texture*> imageTable;
    static std::unordered_map<std::string, Mix_Music*> musicTable;
    static std::unordered_map<std::string, Mix_Chunk*> soundTable;
    
  public:
    /* Metodos publicos */
    static SDL_Texture* GetImage(std::string file);
    static Mix_Music* GetMusic(std::string file);
    static Mix_Chunk* GetSound(std::string file);

    static void ClearImages();
    static void ClearMusics();
    static void ClearSounds();
};

#endif