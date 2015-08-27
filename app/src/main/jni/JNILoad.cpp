/*
 * @author Thomas Radloff  bostontrader@gmail.com https://bostontrader.github.io/androidNDKStudy
 */

#include <android/log.h>
#include <jni.h>
#include "JNILoad.h"

/*
 * When the JNI library is loaded, this function will be invoked.
 * Returns the JNI version on success, -1 on failure.
 */
jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env = 0;

    __android_log_print(ANDROID_LOG_VERBOSE, "MyApp", "JNILoad- The value of n is %d", 500);

    /* success -- return valid version number */
    return JNI_VERSION_1_6;
}