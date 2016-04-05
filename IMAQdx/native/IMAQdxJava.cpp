// IMAQdxJava.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

//////////////////////////////////////////////////////////////////////////////////////////

/*
* Class:     org_nowireless_imaqdx_IMAQdx
* Method:    _IMAQdxEnumerateCameras
* Signature: ([Ljava/nio/ByteBuffer;Ljava/nio/ByteBuffer;Z)I
*/
JNIEXPORT jint JNICALL Java_org_nowireless_imaqdx_IMAQdx__1IMAQdxEnumerateCameras
  (JNIEnv *env, jclass, jlong infoArray, jobject count, jboolean connected) {
	
	uInt32 *_count = (uInt32*)env->GetDirectBufferAddress(count);
	IMAQdxCameraInformation *infoptr = (IMAQdxCameraInformation *)infoArray;
	uInt32 count2;
	int result = IMAQdxEnumerateCameras(infoptr, &count2, connected);
	*_count = count2;
	return result;
}

///////////////////////////////////////////////////////////////////////////////////////////

/*
* Class:     org_nowireless_imaqdx_IMAQdx_IMAQdxCameraInformationArray
* Method:    _allocate
* Signature: (I)J
*/
JNIEXPORT jlong JNICALL Java_org_nowireless_imaqdx_IMAQdx_00024IMAQdxCameraInformationArray__1allocate
(JNIEnv *env, jclass, jint size) {
	return (jlong) new IMAQdxCameraInformation[size];
}

/*
* Class:     org_nowireless_imaqdx_IMAQdx_IMAQdxCameraInformationArray
* Method:    _get
* Signature: (I)J
*/
JNIEXPORT jlong JNICALL Java_org_nowireless_imaqdx_IMAQdx_00024IMAQdxCameraInformationArray__1get
(JNIEnv *env, jclass, jlong addr, jint element) {
	return (jlong) ((IMAQdxCameraInformation*)addr)+element;
}

///////////////////////////////////////////////////////////////////////////////////////////////

/*
* Class:     org_nowireless_imaqdx_IMAQdx_IMAQdxCameraInformation
* Method:    _type
* Signature: (J)I
*/
JNIEXPORT jint JNICALL Java_org_nowireless_imaqdx_IMAQdx_00024IMAQdxCameraInformation__1type
(JNIEnv *, jobject, jlong addr) {
	IMAQdxCameraInformation *info = (IMAQdxCameraInformation*)addr;
	return info->Type;
}

/*
* Class:     org_nowireless_imaqdx_IMAQdx_IMAQdxCameraInformation
* Method:    _version
* Signature: (J)I
*/
JNIEXPORT jint JNICALL Java_org_nowireless_imaqdx_IMAQdx_00024IMAQdxCameraInformation__1version
(JNIEnv *, jobject, jlong addr) {
	IMAQdxCameraInformation *info = (IMAQdxCameraInformation*)addr;
	return info->Version;
}

/*
* Class:     org_nowireless_imaqdx_IMAQdx_IMAQdxCameraInformation
* Method:    _flags
* Signature: (J)I
*/
JNIEXPORT jint JNICALL Java_org_nowireless_imaqdx_IMAQdx_00024IMAQdxCameraInformation__1flags
(JNIEnv *, jobject, jlong addr) {
	IMAQdxCameraInformation *info = (IMAQdxCameraInformation*)addr;
	return info->Flags;
}

/*
* Class:     org_nowireless_imaqdx_IMAQdx_IMAQdxCameraInformation
* Method:    _serialNumberHi
* Signature: (J)I
*/
JNIEXPORT jint JNICALL Java_org_nowireless_imaqdx_IMAQdx_00024IMAQdxCameraInformation__1serialNumberHi
(JNIEnv *, jobject, jlong addr) {
	IMAQdxCameraInformation *info = (IMAQdxCameraInformation*)addr;
	return info->SerialNumberHi;
}

/*
* Class:     org_nowireless_imaqdx_IMAQdx_IMAQdxCameraInformation
* Method:    _serialNumberLo
* Signature: (J)I
*/
JNIEXPORT jint JNICALL Java_org_nowireless_imaqdx_IMAQdx_00024IMAQdxCameraInformation__1serialNumberLo
(JNIEnv *, jobject, jlong addr) {
	IMAQdxCameraInformation *info = (IMAQdxCameraInformation*)addr;
	return info->SerialNumberHi;
}

/*
* Class:     org_nowireless_imaqdx_IMAQdx_IMAQdxCameraInformation
* Method:    _busType
* Signature: (J)I
*/
JNIEXPORT jint JNICALL Java_org_nowireless_imaqdx_IMAQdx_00024IMAQdxCameraInformation__1busType
(JNIEnv *, jobject, jlong addr) {
	IMAQdxCameraInformation *info = (IMAQdxCameraInformation*)addr;
	return info->BusType;
}

/*
* Class:     org_nowireless_imaqdx_IMAQdx_IMAQdxCameraInformation
* Method:    _interfaceName
* Signature: (J)Ljava/lang/String;
*/
JNIEXPORT jstring JNICALL Java_org_nowireless_imaqdx_IMAQdx_00024IMAQdxCameraInformation__1interfaceName
(JNIEnv *env, jobject, jlong addr) {
	IMAQdxCameraInformation *info = (IMAQdxCameraInformation*)addr;
	return env->NewStringUTF(info->InterfaceName);
}