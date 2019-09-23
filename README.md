# XPlatCppSdk
Cross-Platform C++ PlayFab SDK.

It currently supports the following platforms:
- Windows (Win32) x64
- Xbox One
- Linux

This SDK lets you make REST API calls to the PlayFab service. It depends on some external third-party open source libraries referenced as git submodules in directory `/external`. Please make sure to use `--recurse-submodules` command line parameter when cloning SDK's git repo:
```
git clone --recurse-submodules <git-repo-url>
```
or run the following commands to sync the content of submodules if the repo was cloned earlier without the `--recurse-submodules` parameter:

```
git submodule update --init --recursive
```
This source code of SDK itself is generated from our [SdkGenerator](https://github.com/PlayFab/SdkGenerator).

---
## Before Building the SDK from downloading from GitHub as a .zip
Please run set-gitmodules.bat before attempting to build the SDK. We rely on a particular commit of jsoncpp that this file will direct you to. 

---
## Building SDK
Locate build projects for a required platform in directory tree:
```
Xplat SDK
|
|-- build
    |
    |-- Linux
    |
    |-- Windows
    |
    |-- Xbox
    |
    |--  . . .
```
The build projects are created for a build tool that is popular or commonly used on that platform (e.g. Visual Studio projects for Windows, Xbox).

### 1. Prerequisites:

* IDE or a build tool specific to platform (Visual Studio 2017 for Windows, Xbox)
* Users should be very familiar with the topics covered in our [getting started guide](https://api.playfab.com/docs/general-getting-started).
* When we built this for windows we used platform toolset v141 in the project files. If you have a different toolset installed on your dev box it is safe to update this to later versions of the platform toolsets, feel free to re-target the projects as you see fit your projects needs.

### 2. Installation & Configuration Instructions:

Currently this project includes SDK and Example.

* Open projects/solution in the IDE/build tool
* Build SDK

### 3. Troubleshooting:

For a complete list of available APIs, check out the [online documentation](http://api.playfab.com/Documentation/).

### 4. Contact Us
We love to hear from our developer community!
Do you have ideas on how we can make our products and services better?

Our Developer Success Team can assist with answering any questions as well as process any feedback you have about PlayFab services.

[Forums, Support and Knowledge Base](https://community.playfab.com/index.html)

### 5. Copyright and Licensing Information:

Apache License --
  Version 2.0, January 2004
  http://www.apache.org/licenses/

  Full details available within the LICENSE file.
