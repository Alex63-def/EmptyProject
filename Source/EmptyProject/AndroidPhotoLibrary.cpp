#include "AndroidPhotoLibrary.h"

AndroidPhotoLibrary::AndroidPhotoLibrary()
{
#if PLATFORM_ANDROID
	ImageSelectedFromGalleryProxy = OnImageSelected;
	INIT_JAVA_METHOD(AndroidThunkJava_OpenGallery, "()V");
#endif
}

void AndroidPhotoLibrary::OpenGallery()
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true))
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AndroidThunkJava_OpenGallery);
#endif
}

