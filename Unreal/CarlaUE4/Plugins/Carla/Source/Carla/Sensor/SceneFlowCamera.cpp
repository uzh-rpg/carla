#include "Carla.h"
#include "Carla/Sensor/SceneFlowCamera.h"

#include "Carla/Sensor/PixelReader.h"

FActorDefinition ASceneFlowCamera::GetSensorDefinition()
{
  return UActorBlueprintFunctionLibrary::MakeCameraDefinition(TEXT("scene_flow"));
}

ASceneFlowCamera::ASceneFlowCamera(const FObjectInitializer &ObjectInitializer)
  : Super(ObjectInitializer)
{
  Enable16BitFormat(true);
  AddPostProcessingMaterial(
      TEXT("Material'/Carla/PostProcessingMaterials/PhysicLensDistortion.PhysicLensDistortion'"));
  AddPostProcessingMaterial(
          TEXT("Material'/Carla/PostProcessingMaterials/SceneFlowMaterial.VelocityMaterial'"));
}

void ASceneFlowCamera::PostPhysTick(UWorld *World, ELevelTick TickType, float DeltaSeconds)
{
  FPixelReader::SendPixelsInRenderThread(*this, true, true);
}
