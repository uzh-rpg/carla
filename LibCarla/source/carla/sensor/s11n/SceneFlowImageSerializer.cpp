//
// Created by flo on 09.11.20.
//

#include "SceneFlowImageSerializer.h"
#include "carla/sensor/s11n/SceneFlowImageSerializer.h"

#include "carla/sensor/data/Image.h"

namespace carla {
  namespace sensor {
    namespace s11n {

      SharedPtr<SensorData> SceneFlowImageSerializer::Deserialize(RawData &&data) {
        auto image = SharedPtr<data::SceneFlowImage>(new data::SceneFlowImage{std::move(data)});
        return image;
      }

    } // namespace s11n
  } // namespace sensor
} // namespace carla
