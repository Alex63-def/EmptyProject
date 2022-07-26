#pragma once

#include "PhotoGalleryInterface.generated.h"

// этот юинтерфейс позволяет видеть интерфейс айфото в анриале в принтах
UINTERFACE(MinimalAPI, Blueprintable)
class UPhotoLibrary : public UInterface
{
	GENERATED_BODY()
};

class IPhotoLibrary
{
	GENERATED_BODY()
public:
	virtual void OpenGallery() = 0;
};
