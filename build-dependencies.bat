@echo off
echo === Build Xplat C++ SDK dependencies (BEGIN) ===
echo ATTENTION!
echo This batch file must be run in "x64 Native Tools Command Prompt for VS 2017"

setlocal
pushd "%~dp0"

echo --- Building zlib ---
pushd "external/zlib"
nmake /f win32/Makefile.msc
if /I "%ERRORLEVEL%" neq "0" (
echo zlip build failed!
exit /B %ERRORLEVEL%
) else (
echo zlib build succeeded.
)
pause

rem - copy headers and binaries to deps
xcopy "*.h" "../deps/include/" /R /F /Y /H
xcopy "zlib.lib" "../deps/lib/" /R /F /Y /H
xcopy "zlib.pdb" "../deps/lib/" /R /F /Y /H
xcopy "zdll.lib" "../deps/lib/" /R /F /Y /H
xcopy "zdll.exp" "../deps/lib/" /R /F /Y /H
xcopy "zlib1.dll" "../deps/lib/" /R /F /Y /H
xcopy "zlib1.pdb" "../deps/lib/" /R /F /Y /H
popd

echo --- Building openssl ---
pushd "external/openssl-build"
rem nmake
if /I "%ERRORLEVEL%" neq "0" (
echo openssl build failed!
exit /B %ERRORLEVEL%
) else (
echo openssl build succeeded.
)
pause

rem - copy headers and binaries to deps
xcopy "../openssl/include/openssl/*.*" "../deps/include/openssl/" /E /R /F /Y /H
xcopy "include/*.*" "../deps/include/" /E /R /F /Y /H
xcopy "libssl.lib" "../deps/lib/" /R /F /Y /H
xcopy "libcrypto.lib" "../deps/lib/" /R /F /Y /H
popd

echo --- Building curl ---
pushd "external/curl"
rem call buildconf.bat
if /I "%ERRORLEVEL%" neq "0" (
echo curl build config failed!
exit /B %ERRORLEVEL%
) else (
echo curl build config succeeded.
)
pause

pushd "winbuild"
rem nmake /f Makefile.vc mode=static VC=15 WITH_SSL=static WITH_ZLIB=static MACHINE=x64
if /I "%ERRORLEVEL%" neq "0" (
echo curl build failed!
exit /B %ERRORLEVEL%
) else (
echo curl build succeeded.
)
popd
pause

rem - copy headers and binaries to deps
set curlBuildDir=builds/libcurl-vc15-x64-release-static-ssl-static-zlib-static-ipv6-sspi/
xcopy "%curlBuildDir%include/*.*" "../deps/include/" /E /R /F /Y /H
xcopy "%curlBuildDir%lib/libcurl_a.lib" "../deps/lib/" /R /F /Y /H
popd

echo --- Building jsoncpp ---
pushd "external/jsoncpp"

nmake /f win32/Makefile.msc
if /I "%ERRORLEVEL%" neq "0" (
echo zlip build failed!
exit /B %ERRORLEVEL%
) else (
echo zlib build succeeded.
)
pause

rem - copy headers and binaries to deps
xcopy "*.h" "../deps/include/" /R /F /Y /H
xcopy "zlib.lib" "../deps/lib/" /R /F /Y /H
xcopy "zlib.pdb" "../deps/lib/" /R /F /Y /H
xcopy "zdll.lib" "../deps/lib/" /R /F /Y /H
xcopy "zdll.exp" "../deps/lib/" /R /F /Y /H
xcopy "zlib1.dll" "../deps/lib/" /R /F /Y /H
xcopy "zlib1.pdb" "../deps/lib/" /R /F /Y /H
popd

popd
echo === Build Xplat C++ SDK dependencies (END) ===
echo All dependencies are built successfully.
exit /B 0