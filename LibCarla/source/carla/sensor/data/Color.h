// Copyright (c) 2017 Computer Vision Center (CVC) at the Universitat Autonoma
// de Barcelona (UAB).
//
// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.

#pragma once

#include "carla/rpc/Color.h"

#include <cstdint>

namespace carla {
namespace sensor {
namespace data {

#pragma pack(push, 1)
  /// A 32-bit BGRA color.
  struct Color {
    Color() = default;
    Color(const Color &) = default;

    Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255u)
      : b(b), g(g), r(r), a(a) {}

    Color &operator=(const Color &) = default;

    bool operator==(const Color &rhs) const  {
      return (r == rhs.r) && (g == rhs.g) && (b == rhs.b);
    }

    bool operator!=(const Color &rhs) const  {
      return !(*this == rhs);
    }

    operator rpc::Color() const {
      return {r, g, b};
    }

    uint8_t b = 0u;
    uint8_t g = 0u;
    uint8_t r = 0u;
    uint8_t a = 0u;
  };
#pragma pack(pop)

  static_assert(sizeof(Color) == sizeof(uint32_t), "Invalid color size!");

#pragma pack(push, 1)
  /// Optical flow pixel format. 2 channel float data.
  struct OpticalFlowPixel {
    OpticalFlowPixel() = default;
    OpticalFlowPixel(const OpticalFlowPixel &) = default;

    OpticalFlowPixel(float x, float y)
      : x(x), y(y) {}

    OpticalFlowPixel &operator=(const OpticalFlowPixel &) = default;

    bool operator==(const OpticalFlowPixel &rhs) const  {
      return (x == rhs.x) && (y == rhs.y);
    }

    bool operator!=(const OpticalFlowPixel &rhs) const  {
      return !(*this == rhs);
    }

    float x = 0;
    float y = 0;
  };
#pragma pack(pop)

#pragma pack(push, 1)
  /// Scene flow pixel format. 3 channel float data.
  struct SceneFlowPixel {
    SceneFlowPixel() = default;
    SceneFlowPixel(const SceneFlowPixel &) = default;

    SceneFlowPixel(float x, float y)
      : x(x), y(y) {}

    SceneFlowPixel &operator=(const SceneFlowPixel &) = default;

    bool operator==(const SceneFlowPixel &rhs) const  {
      return (x == rhs.x) && (y == rhs.y) && (z == rhs.z);
    }

    bool operator!=(const SceneFlowPixel &rhs) const  {
      return !(*this == rhs);
    }

    float x = 0;
    float y = 0;
    float z = 0;
  };
#pragma pack(pop)

} // namespace data
} // namespace sensor
} // namespace carla
