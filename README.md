# MarkdownEditView

## How to Build

Create a build directory and run

    cmake -DCMAKE_PREFIX_PATH=<path_to_qtcreator> -DCMAKE_BUILD_TYPE=RelWithDebInfo <path_to_plugin_source>
    cmake --build .

where `<path_to_qtcreator>` is the relative or absolute path to a Qt Creator build directory, or to
a combined binary and development package, and `<path_to_plugin_source>` is the relative or absolute
path to this plugin directory.

## How to Run

Run a compatible Qt Creator with the additional command line argument

    -pluginpath <path_to_plugin>

where `<path_to_plugin>` is the path to the resulting plugin library in the build directory
(`<plugin_build>/lib/qtcreator/plugins` on Windows and Linux,
`<plugin_build>/Qt Creator.app/Contents/PlugIns` on macOS).

You might want to add `-temporarycleansettings` (or `-tcs`) to ensure that the opened Qt Creator
instance cannot mess with your user-global Qt Creator settings.

When building and running the plugin from Qt Creator, you can use

    -pluginpath "%{buildDir}/lib/qtcreator/plugins" -tcs

on Windows and Linux, or

    -pluginpath "%{buildDir}/Qt Creator.app/Contents/PlugIns" -tcs

for the `Command line arguments` field in the run settings


cmake -DCMAKE_PREFIX_PATH=/Users/erdincyilmaz/Qt/5.15.2/clang_64 -GNinja cmake -DCMAKE_PREFIX_PATH=/Users/erdincyilmaz/Qt/5.15.2/clang_64 -DCMAKE_BUILD_TYPE=RelWithDebInfo -GNinja ..

cmake -DCMAKE_PREFIX_PATH=/Users/erdincyilmaz/Qt/5.15.2/clang_64:/Users/erdincyilmaz/Projects/qt-creator-4.14/qtcreator_build -DCMAKE_BUILD_TYPE=RelWithDebInfo -GNinja -DCMAKE_CXX_COMPILER=/usr/bin/clang ..

https://foonathan.net/2016/07/cmake-dependency-handling/

cmake "-DCMAKE_PREFIX_PATH=/Users/erdincyilmaz/Projects/qt-creator-4.14/qtcreator_build:/Users/erdincyilmaz/Qt/5.15.2/clang_64" -DCMAKE_BUILD_TYPE=RelWithDebInfo -GNinja -DCMAKE_CXX_COMPILER=/usr/bin/clang++ -DCMAKE_C_COMPILER=/usr/bin/clang  ..
