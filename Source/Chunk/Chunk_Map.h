#ifndef CHUNK_MAP_H
#define CHUNK_MAP_H

#include <unordered_map>
#include <memory>

#include "Chunk_Position.h"
#include "Chunk.h"
#include "Texture.h"
#include "Shader.h"

#include "Chunk_Ground_Renderer.h"

class Camera;

class Chunk_Map
{
    public:
        Chunk_Map();
        Chunk* getChunkAt (const Chunk_Position& location);
        void addChunk(const Chunk_Position& location);

        void draw(const Camera& camera);

    private:
        void mangageChunk();


    private:
        std::unordered_map<Chunk_Position, std::unique_ptr<Chunk>> m_chunks;

        Texture_Atlas           m_blockTextures;
        Chunk_Ground_Renderer   m_renderer;
};

#endif // CHUNK_MAP_H