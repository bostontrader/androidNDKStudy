#Understanding the Android SDK

As you may have discovered by now, in order to develop for Android you'll need to download the Android SDK.

##Android SDK vs API Versioning
The first thing to understand about the SDK is that the SDK and the Android platform are versioned separately. Although there is a method to their madness, we cannot rely upon getting SDK version N in order to support Android platform version N.  That's not how it works.  I'll explain how it _does_ work shortly.

###Android API Versioning
Android devices have some API that programs can use.  This API is obviously versioned and we need some method of unambiguously specifying a particular version.

There are three versioning systems in use.  Although they are roughly parallel there is not a 1-to-1 correspondence between them.

* API Level. This is the most specific and unambiguous versioning system. The API levels are sequential integers starting with 1.  Not easy to get confused here.

* Android Platform. This is "Android 2.0," "Android 4.4," etc.

* Codenames. These are the desert names such as "cupcake" or "kitkat."

Here's a [handy chart](http://developer.android.com/guide/topics/manifest/uses-sdk-element.html#ApiLevels) of all of this.

###Android SDK Versioning
The SDK uses a versioning system that roughly follows the Android API Level.  For example, the "r23" that's embedded in the file name of the SDK that we download indicated that API Level 23 is a contemparary of this SDK.  It _does not_ mean that you will get API 23 out of the box.

##The Default SDK
That said, when we download the SDK, what do we get? We get some collection of tools to get us started.  And the first thing we need to do with these tools is to download a particular "platform." In this context a "platform" is some collection of tools required to develop for a particular API level.

##SDK Tools vs. Platform Tools
The [docs](http://developer.android.com/tools/help/index.html) make a distinction between "SDK tools" and "platform tools."  

The distinction is that some tools (the SDK tools) are required no matter which Android platform you develop for, and some are specific for particular platforms (the platform tools).

For example, __android__,  __emulator__, and __ddms__ are required no matter which platform you're working with and are just categorized (by the docs) as "SDK Tools."  But __adb__ is more wedded to each particular platform, and hence is considered (by the docs) to be a "platform tool."

##Installation

Installation is a snap.  Unpack the downloaded file where ever you want it and you're good to go.






 
 