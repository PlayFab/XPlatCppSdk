# XPlatCppSdk GDK build
Cross-Platform C++ PlayFab SDK, compatible with [GDK](https://github.com/microsoft/GDK)

It currently supports the following platforms:
- Windows (Win32) x64
- Xbox Series X|S & Xbox One


This SDK lets you make REST API calls to the PlayFab service. It depends on some external third-party open source libraries referenced as git submodules in directory `/external`. Please make sure to use `--recurse-submodules` command line parameter when cloning SDK's git repo:
```
git clone --recurse-submodules <git-repo-url>
```
or run the following commands to sync the content of submodules if the repo was cloned earlier without the `--recurse-submodules` parameter:

```
git submodule update --init --recursive
```
This source code of SDK itself is generated from our [SdkGenerator](https://github.com/PlayFab/SdkGenerator) and [XPlatCoreTemplate](https://github.com/PlayFab/XPlatCoreTemplate).

---
## Before Building the SDK from downloading from GitHub as a .zip
Please run set-gitmodules.bat before attempting to build the SDK. We rely on a particular commit of jsoncpp that this file will direct you to. 


### Setup:

1. IDE or a build tool specific to platform (Visual Studio 2022 for Windows, Xbox)
1. Users should be very familiar with the topics covered in our [getting started guide](https://api.playfab.com/docs/general-getting-started).
1. When we built this for windows we used platform toolset v141 in the project files. If you have a different toolset installed on your dev box it is safe to update this to later versions of the platform toolsets, feel free to re-target the projects as you see fit your projects needs.
1. [GDK](https://github.com/microsoft/GDK) should be installed on the system. PlayFab relies on XCurl which must exist. Double click PGDK.exe from this repo to get the correct install setup. The lib and dll dependencies should exist under C:\Program Files (x86)\Microsoft GDK\220600\GRDK\ExtensionLibraries\Xbox.XCurl.API\ 
1. When adding PlayFab to your .vcxproj file, add <GDKExtLibNames>Xbox.XCurl.API</GDKExtLibNames> to the top Property Group Globals. You may still need to add the XCurl lib in Additional Dependencies per project in the same vcxproj file. See [Our Test Project for an example of how we added the XCurl lib](https://github.com/PlayFab/XPlatCppSdk/blob/master/build/GDK/TestClientApp.vcxproj)
1. If the above is completed, try running our [example unit test build](https://github.com/PlayFab/XPlatCppSdk/build/GDK/XPlatCppGdk.sln) (NOTE: configure [the TestApp.cpp file first with your PlayFab title Id and email and comment out the return 1]([https://github.com/PlayFab/XPlatCppSdk/build/GDK/XPlatCppGdk.sln](https://github.com/PlayFab/XPlatCppSdk/blob/master/test/TestApp/TestApp.cpp#L70)) before you hit F5
1. This should result in the output XPlatCppGdk lib under the expected output path: {Root XPlatCppSdk directory}/XPlatCppSdk/build/GDK/{Gaming.Desktop.x64 | Gaming.Xbox.XboxOne.x64 | Gaming.Xbox.Scarlett.x64}/{Debug | Release}/XPlatCppGdk/ 
