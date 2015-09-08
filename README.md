#How to debug c++ with Android's NDK.

##Introduction
The purpose of my quest is to figure out how to debug c++ code that's part of
an Android app that uses JNI/NDK.  I strongly desire that "debug" involve a graphical
debugger.

This goal has proven to be the Devil's work and I'm not done with it yet.  There are many
random approaches to be found on the Internet, but unfortunately, none of them have worked for me. Nevertheless, I'm closing in on this so I'm
organizing my notes into a sequential path of development in order to better clarify my
understanding of this.  Hopefully these notes will get you going with this as well.

##Why is this hard?
The first thing to realize about this puzzle is that there's some complexity afoot that
defies the lazy-man's "just read some recipes from the Internet" approach.  Although
said method frequently "works" with lesser goals, it has failed me here. So, failing
that, I've had to instead study the problem in greater depth.

The overall puzzle is composed of two related parts:

* We need to build something that goes onto an Android device.

* We need a debugger on a development machine to communicate with the code on the device.

A second and a half issue is that I for one would really like an easy-to-use graphical debugger.

Sand is injected into the machinery of this process in that:

* There are at least three operating systems plausibly involved if you only count Android, Linux, and Windows.  Plenty more confusion if you peer more closely at the various variations of each or their barefoot kinfolk such as Wine or Cygwin.

* You'll want the Android SDK and NDK.

* There are at least two main programming languages involved, Java and c++.  And more if you want to count shell scripting, c, Python, and Groovy.

* There are multiple build processes potentially at work.  Such as Gradle, Ant, to build the .apk
and ndk-build and make to build the c++ binaries.

* The build tools use lower level tool chains.

* There are at least two IDE's that are commonly used to invoke these build processes, Android Studio and Eclipse. Three if you want to count Visual Studio.  You can also do this via command line.

* All of the above can be found in many different versions, if you only count the public 
releases.  Heaven helps whoever gets their hands on some source code with the myriad of additional
versions thus available.

* Nothing you find on the Internet is going to _exactly_ match your particular circumstances. If not, is it close enough? Will you be able to adapt? Good luck with that!

So if you just got lucky and some permutation of the above works for you, congratulations.  For the rest of you all, read on...

##Digging deeper

###Development machine OS

You will need to pick an OS to use on your development machine. For purposes of example I'm using 64-bit Ubuntu 15.04 and the lowly Windows XP (which is always 32 bit.)

###Install the Android SDK
[Understanding the Android SDK](AndroidSDK.md)

###Install the Android NDK




1. Start with Eclipse, the ADT, Linux, and gdb.  At the time of writing, the NDK documentation and samples
all assume these things, so this is the easiest path to get started.

2. Android Studio and the experimental Gradle plugin allegedly can do this. But I have been unable to find
examples, documentation, or sufficient good-luck to stumble upon the answer.  There's a ferocious snake nest
of complexity in this and before we jump to that level, I think it's wise to start with the basics.

3. The Eclipse build process builds the Android app as usual. In doing so it incorporates some files created
by the NDK.  It also invokes NDK_BUILD and builds the c++ bits.


4. The basic drill is to invoke ndk-build whenever you see fit and then rebuild the Android app.  Sweet.

5. Realize that ndk-build is a shell script.  If you examine the source code, you'll find clues about
wtf it's doing, and what it might do if properly coaxed via command line args.  This trick is especially
useful if the NDK tools are taunting you with mysterious error messages.

ndk-build NDK_LOG=1 will start up the build and emit lots of logging messages.

6. In order to get debugging going, our first task is to get ndk-debug to work.  This one was particularly
obnoxious when I first went after it with my chainsaw.

ndk generated files (app/src/main/libs)
some particular face palms for me...

1. Make sure to apply NDK Nature to the Eclipse project!

2. There is some issue with ordinary users not being able to use the USB ports and this throws
a monkey into the wrench re: using adb, which ndk-build uses.

3. power!


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
