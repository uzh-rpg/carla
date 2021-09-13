#pragma once

#include "Carla/Sensor/ShaderBasedSensor.h"

#include "Carla/Actor/ActorDefinition.h"

#include "SceneFlowCamera.generated.h"

/// Sensor that produces "scene flow" images.
UCLASS()
class CARLA_API ASceneFlowCamera : public AShaderBasedSensor
{
  GENERATED_BODY()

public:

  static FActorDefinition GetSensorDefinition();

  ASceneFlowCamera(const FObjectInitializer &ObjectInitializer);

protected:

  void PostPhysTick(UWorld *World, ELevelTick TickType, float DeltaSeconds) override;
};
