# How to get started with Android Studio, the Experimental Gradle plugin, the NDK, JNI, C, and C++

The vast majority of Android development is done using Java.  However, there are times when
we want to access native code from Java.  For example, maybe you have some C or C++ code
that you want to use.  Whether this is a good idea or not is a separate
issue.  Assuming that you've c/o/n/s/u/l/t/e/d/ /y/o/u/r/ /8/-/b/a/l/l/ made your informed decision and have
decided to do it, let me share some tips that I found useful.

Overall, you'll be happy to know that doing this with Android Studio and Gradle is very feasible.
As of the time of writing (Aug 2015), this apparently is a recent development and all other
documentation that I have found was for doing this with Eclipse, the command line, or doing various
contortions to make it work with Android Studio and Gradle.  Fortunately none of that's necessary.

The key to success in this endeavor, IMHO, is to figure out the [experimental Gradle plugin]
(http://tools.android.com/tech-docs/new-build-system/gradle-experimental).
You'll need to also study the [Java Native Interface (JNI)]
(http://docs.oracle.com/javase/7/docs/technotes/guides/jni/spec/jniTOC.html) and the
[Android Native Development Kit (NDK)](http://developer.android.com/ndk/guides/index.html).
JNI is Java's spec for how Java should interact
with not-Java, and the NDK is the kit you need to connect Android/Java to JNI. 

The NDK is easy and
straight-forward to download and install and there are no hidden surprises here.  Start with README.txt
and nose around in /docs and see what you find. However, the docs and samples, as of ndk-r10e, are for Eclipse.  You can however import the samples into Android Studio and it will create suitable gradle.build files for you, using the experimental Gradle plugin.

One pleasant surprise is that the NDK is fully equipped with its own build tools.  I haven't
yet spelunked into the murky depths of this, but something in there can clearly compile
C and C++ code and build the relevant .so files, even on WinXP.

Another pleasant surpise is that the Gradle/NDK is fairly good at figuring out what to do,
by default, without a lot of hand-holding.  This illustrates the ole convention-over-configuration
principle.  So Gradle/NDK is able to find our source files and headers and libraries
 and all that stuff, and figure out what to do with whatever outputs it creates,
 without me having to micro-manage. Just sit back and enjoy a /f/a/t/ cold one while [Skynet takes over](https://www.youtube.com/watch?v=_Wlsd9mljiU).  No more futzing with cranky software.

Unfortunately, there are some nettlesome mysteries still lurking therein.

The biggest immediate problem that I found was that it's just not possible to debug the c/c++ code using the experimental Gradle Plugin and Android Studio.  Although promised soon, it ain't here yet.

##Tips from Tom!

One of the things that really bedeviled me in figuring this out was getting the naming
 right for C and C++ functions.  For example, if you declare native String foo, in Java class
 Bar, you will need a suitably named function _somewhere_ in your collection of C/C++ source files.
 The tedious rules for what exactly to name this include the Java package and class name of
 the Java doing the calling.  This in and of itself is not so difficult.  The problem is if
 you don't get this right, the exception messages are not helpful.  So the tip is...

 Declare your native method first, in your Java source, and let the Android Studio tell you
 that it can't find the expected function definition.  When doing so, AS will tell you
 specifically what it's looking for!  (Note: This seems to be a sporadically available "feature"
 so YMMV.)

Another thing... Apparently, neither Android.mk nor Application.mk are used
and thus we can just remove them.  Whatever they do, we can do with the experimental
Gradle plugin.

Another things... Be sure to examine the extern "C" { JNIEXPORT ... JNICALL stuff in the
cpp file.  We need it.  If it's not there, your Java cannot find the methods.


For this effort I'm using Android Studio 1.3.2, NDK r10e,
com.android.tools.build:gradle-experimental:0.2.0, on WinXP.
