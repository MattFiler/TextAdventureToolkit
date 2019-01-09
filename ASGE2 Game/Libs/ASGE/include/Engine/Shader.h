//
// Created by huxy on 14/12/18.
//

#ifndef ASGE_SHADER_H
#define ASGE_SHADER_H

#include <array>
#include <map>
#include <memory>
#include "NonCopyable.h"
#include "Value.h"

namespace ASGE {
    namespace SHADER_LIB {
        using _UniformB = ASGE::ValueBase;
        using uniform_ptr = std::unique_ptr<_UniformB>;

        using Uniform1b   = bool;
        using Uniform1f   = float;
        using Uniform1i   = int;
        using Uniformv2b  = std::array<bool, 2>;
        using Uniformv2f  = std::array<float, 2>;
        using Uniformv3f  = std::array<float, 3>;
        using Uniformv4f  = std::array<float, 4>;
        using UniformMat2 = std::array<std::array<float, 2>, 2>;
        using UniformMat4 = std::array<std::array<float, 4>, 4>;

        /**
        *  @brief a shader instance.
        *  The shader is used in the rendering pipeline.
        */
        class Shader : public NonCopyable
        {
          public:
            Shader() = default;
            virtual ~Shader() = default;
            _UniformB *getUniform(const std::string &name);

          protected:
            using uniform_record = std::pair<std::string, uniform_ptr>;
            std::map<std::string, uniform_ptr> uniforms;
        };
    }
}
#endif //ASGE_SHADER_H
