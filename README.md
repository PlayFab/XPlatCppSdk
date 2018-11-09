# XPlatCppSdk

**SECURITY ISSUE WARNING: We have found security vulnerabilities in version 2.x of the XPlatCppSdk. We are working to resolve this issue immediately. Version 2.x should be abandoned as soon as possible, and replaced with version 3.x as soon as it's released.**

Cross Platform C++ SDK

This SDK lets you make REST API calls to the PlayFab service. It depends on jsoncpp and curl nuget packages (installed via nuget manager in VS).

This SDK is generated from our [SdkGenerator](https://github.com/PlayFab/SdkGenerator)

BETA!

Currently, this SDK is not yet part of our normal publish pipeline, nor does it have the full testing. (We're working on this). The features that are most in need of testing are json <-> timestamp conversions, and arbitrary input/output parameters, such as WriteEvent and Cloud Script. (These two may not be fully working yet).

Also TODO, we intend to make this to be a nuget package.

Once this SDK is fully tested and integrated, we may deprecate the WindowsSDK, as they have essentially the same interface, but XPlatCppSdk has more compact dependencies which should pose fewer conflicts with customer projects. This most likely won't happen until end of 2018 or later.

## 1. Overview:

This document describes the process of configuring and building the PlayFab Cross Platform C++ SDK. This SDK is still in beta. It is a theoretical replacement for WindowsSDK, which only supports C++ on Windows.

There is no upgrade guide at this time, and will likely not happen if/until the WindowsSDK becomes deprecated. The main differences are:

* XPlatCppSdk uses std::string, instead of the string types inherited from the CppRestSdk
* XPlatCppSdk uses Json::Value from JsonCpp library, rather than the web::json::value inherited from the CppRestSdk

Almost all other syntax and generated code should be nearly identical.


## 2. Prerequisites:

* Visual Studio 2017
* The built in Linux project is designed to be built remotely on a Linux machine, from a Windows Visual Studio
    * Detailed Linux setup instructions will be released soon
* Users should be very familiar with the topics covered in our [getting started guide](https://api.playfab.com/docs/general-getting-started).


## 3. Installation & Configuration Instructions:

Currently this project is a combined SDK and Example.

A new project will need to include the JsonCpp and curl/libcurl nuget libraries, copy paste the playfab code.

It is a high priority to make this project a proper nuget package soon, with dependencies properly defined.


## 4. Troubleshooting:

For a complete list of available APIs, check out the [online documentation](http://api.playfab.com/Documentation/).

#### Contact Us
We love to hear from our developer community!
Do you have ideas on how we can make our products and services better?

Our Developer Success Team can assist with answering any questions as well as process any feedback you have about PlayFab services.

[Forums, Support and Knowledge Base](https://community.playfab.com/index.html)


## 5. Copyright and Licensing Information:

Apache License --
  Version 2.0, January 2004
  http://www.apache.org/licenses/

  Full details available within the LICENSE file.
