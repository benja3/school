# CMake notes

## Questions

Library Visibility

## CMake Purpose

Allows for specification of build information in a single text file

Handle a lot of tricky under the hood build processes automatically

Cross platform standard system

## General

Namespace: organization tool so can have functions with same names and different implementations

Buildsystem: describes how to build the projects executables and libraries

transitive: dependencies will automatically be propagated to anything that links to the library with transitive dependencies

Linking: process of combining mulitple source files into a single executable

refactor: changing internal structure of code without changing the external functionality that the user sees 

### Library Visibility

Static: code linked at compile time resulting in  

## Basic Starting Point

Most basic project is exacutable build from declarations in the ```CMakeLists.txt``` file

Must specify basic info at the top of this file such as version, project name, and executables that will be used

## Functions

set: create variables in Cmake

## Variables

PROJECT_BINARY_DIR: the directory where the build occurs

PROJECT_SOURCE_DIR: directory of the highest level CMakeLists.txt file




## Step 1

PROJECT_BINARY_DIR is the directory of the last ```project``` command, AKA the highest level directory in the project

## Step 3

CMAKE_CURRENT_SOURCE_DIR: path to the CMakeLists.txt file currently being processed; the direcotry that CmakeLists.txt is located in

When accessing a variable like ^, must use ${<var>}
