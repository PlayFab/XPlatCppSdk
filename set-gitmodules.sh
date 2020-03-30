#!/bin/bash

#echo ========= Setting Git Submodules to specific commits (BEGIN) =========
if [ ".git" ]
then
    git submodule update --init --recursive
else
    git init
    git submodule add https://github.com/open-source-parsers/jsoncpp.git ./external/jsoncpp
    if [ $? != 0 ]
    then
        exit $?
    fi
fi

pushd "external/jsoncpp"
git checkout 2baad4923e6d9a7e09982cfa4b1c5fd0b67ebd87
git reset --hard 2baad4923e6d9a7e09982cfa4b1c5fd0b67ebd87
if [ $? != 0 ]
then
    exit $?
fi
popd

#echo ========= Setting Git Submodules to specific commits (END) =========