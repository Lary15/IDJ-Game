#include "../inc/Resources.h"
#include "../inc/Game.h"

/* Inicializando variavel static */
std::unordered_map<std::string, SDL_Texture*> Resources::imageTable;
std::unordered_map<std::string, Mix_Music*>   Resources::musicTable;
std::unordered_map<std::string, Mix_Chunk*>   Resources::soundTable;

SDL_Texture* Resources::GetImage(std::string file) {
  /* Se arquivo nao for encontrado na tabela */
  if (imageTable.find(file) == imageTable.end()) {
    /* Adiciona nova textura na tabela */
    SDL_Texture* texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());

    if (texture) imageTable[file] = texture;
    else { /* Trata possivel erro de carregamento */
      SDL_Log("Unable to load texture: %s\n", IMG_GetError());
      return nullptr;
    }
  }

  /* Retorna textura */
  return imageTable[file];
}

Mix_Music* Resources::GetMusic(std::string file) {
  /* Se arquivo nao for encontrado na tabela */
  if (musicTable.find(file) == musicTable.end()) {
    /* Adiciona nova musica na tabela */
    Mix_Music* music = Mix_LoadMUS(file.c_str());

    if (music) musicTable[file] = music;
    else { /* Trata possivel erro de carregamento */
      SDL_Log("Unable to load music: %s\n", Mix_GetError());
      return nullptr;
    }
  }

  /* Retorna musica */
  return musicTable[file];
}

Mix_Chunk* Resources::GetSound(std::string file) {
  /* Se arquivo nao for encontrado na tabela */
  if (soundTable.find(file) == soundTable.end()) {
    /* Adiciona novo som na tabela */
    Mix_Chunk* sound = Mix_LoadWAV(file.c_str());

    if (sound) soundTable[file] = sound;
    else { /* Trata possivel erro de carregamento */
      SDL_Log("Unable to load sound: %s\n", Mix_GetError());
      return nullptr;
    }
  }

  /* Retorna som */
  return soundTable[file];
}

void Resources::ClearImages() {
  std::unordered_map<std::string, SDL_Texture*>:: iterator it;
  /* itera sobre todas os pares da tabela */
  for (it = imageTable.begin(); it != imageTable.end(); it++) {
    SDL_DestroyTexture(it->second); /* libera ponteiros guardados */
  }

  /* Esvazia tabela */
  imageTable.clear();
}

void Resources::ClearMusics() {
  std::unordered_map<std::string, Mix_Music*>:: iterator it;
  /* itera sobre todas os pares da tabela */
  for (it = musicTable.begin(); it != musicTable.end(); it++) {
    Mix_FreeMusic(it->second); /* libera ponteiros guardados */
  }

  /* Esvazia tabela */
  musicTable.clear();
}

void Resources::ClearSounds() {
  std::unordered_map<std::string, Mix_Chunk*>:: iterator it;
  /* itera sobre todas os pares da tabela */
  for (it = soundTable.begin(); it != soundTable.end(); it++) {
    Mix_FreeChunk(it->second); /* libera ponteiros guardados */
  }

  /* Esvazia tabela */
  soundTable.clear();
}