#pragma once

// анриаловский вид
#include "CoreMinimal.h"
#include "PhotoGalleryInterface.h"

#if PLATFORM_ANDROID // позволяет использовать методы и классы андроида
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

DECLARE_JAVA_METHOD(AndroidThunkJava_OpenGallery); // Here goes the name of the method in the Java side

// ее инициализация
#define INIT_JAVA_METHOD(name, signature) 
if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true)) {
	name = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, #name, signature, false); \
		check(name != NULL);
}
else {
	check(0);
}
#endif

DECLARE_DELEGATE_OneParam(FOnImageSelectedFromGallery, TArray<uint8>);

class EMPTYPROJECT_API AndroidPhotoLibrary : public IPhotoLibrary
{
#if PLATFORM_ANDROID
public:
	static struct _JNIEnv* ENV; // _JNIEnv -- это класс доступа к окружению, в котором работает Android.

	DECLARE_JAVA_METHOD(AndroidThunkJava_OpenGallery);

	JNIEXPORT void Java_com_epicgames_ue4_GameActivity_onImageSelected(JNIEnv* jni, jclass clazz, jbyteArray imageBytes)
	{
		AsyncTask(ENamedThreads::GameThread, [=]()
		{
			if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true))
			{
				jbyte* dataPtr = Env->GetByteArrayElements(imageBytes, NULL);
				jsize len = Env->GetArrayLength(imageBytes);
				TArray<uint8> result((uint8*)dataPtr, (int32)len);
				ImageSelectedFromGalleryProxy.ExecuteIfBound(result);
			}
		});
	}
#endif

	AndroidPhotoLibrary();

public:
	virtual void OpenGallery() override;
	static FOnImageSelectedFromGallery ImageSelectedFromGalleryProxy;
};