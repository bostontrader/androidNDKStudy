/*
 * @author Thomas Radloff  bostontrader@gmail.com https://bostontrader.github.io/androidNDKStudy
*/
#include <string.h>
#include <jni.h>


extern "C" {
    JNIEXPORT jstring JNICALL
    Java_spartacus_androidndkstudy_MainActivity_stringFromCpp(JNIEnv *env, jobject thiz) {
        return env->NewStringUTF("This is a String from Cpp");
    }
}

extern "C" {
    JNIEXPORT jlong JNICALL
    Java_spartacus_androidndkstudy_MainActivity_longFromCpp(JNIEnv *env, jobject thiz) {
        return 6666;
    }
}