#pragma once

#include "z5/handle/handle.hxx"

#ifndef BOOST_FILESYSTEM_NO_DEPERECATED
#define BOOST_FILESYSTEM_NO_DEPERECATED
#endif
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;


namespace z5 {
namespace io {

    template<typename T>
    class ChunkIoBase {

    public:
        virtual bool read(const handle::Chunk &, std::vector<T> &) const = 0;
        virtual void write(const handle::Chunk &, const T *, const size_t) const = 0;
        virtual void getChunkShape(const handle::Chunk &, types::ShapeType &) const = 0;
        virtual size_t getChunkSize(const handle::Chunk &) const = 0;
        virtual void findMinimumChunk(const unsigned, const fs::path &, const size_t, types::ShapeType &) const = 0;
        virtual void findMaximumChunk(const unsigned, const fs::path &, types::ShapeType &) const = 0;
    };


}
}
