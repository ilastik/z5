#pragma once

#include "z5/compression/compressor_base.hxx"

namespace z5 {
namespace compression {

    // dummy compressor if no compression is activated
    template<typename T>
    class RawCompressor : public CompressorBase<T> {

    public:
        RawCompressor() {
        }

        // dummy implementation, this should never be called !
        void compress(const T *, std::vector<T> &, size_t) const {
            throw std::runtime_error("Raw compressor should never be called!");
        }

        // dummy implementation, this should never be called !
        void decompress(const std::vector<T> &, T *, size_t) const {
            throw std::runtime_error("Raw compressor should never be called!");
        }

        virtual types::Compressor type() const {
            return types::raw;
        }

        virtual void getCodec(std::string & codec) const {
            codec = "raw";
        }
    };

}
}
