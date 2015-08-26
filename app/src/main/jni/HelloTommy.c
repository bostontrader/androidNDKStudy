/*
 * @author Thomas Radloff  bostontrader@gmail.com https://bostontrader.github.io/androidNDKStudy
*/
#include <string.h>
#include <jni.h>

jstring
Java_spartacus_androidndkstudy_MainActivity_stringFromC(JNIEnv* env, jobject thiz )
{
    return (*env)->NewStringUTF(env, "This is a String from C");
}

jlong
Java_spartacus_androidndkstudy_MainActivity_longFromC(JNIEnv* env, jobject thiz )
{
    return 666;
}