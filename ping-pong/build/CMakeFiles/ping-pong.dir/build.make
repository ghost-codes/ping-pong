# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.28.0/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.28.0/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/macbookpro/Documents/personal/graphics/ping-pong/ping-pong

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/macbookpro/Documents/personal/graphics/ping-pong/ping-pong/build

# Include any dependencies generated for this target.
include CMakeFiles/ping-pong.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ping-pong.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ping-pong.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ping-pong.dir/flags.make

CMakeFiles/ping-pong.dir/main.cpp.o: CMakeFiles/ping-pong.dir/flags.make
CMakeFiles/ping-pong.dir/main.cpp.o: /Users/macbookpro/Documents/personal/graphics/ping-pong/ping-pong/main.cpp
CMakeFiles/ping-pong.dir/main.cpp.o: CMakeFiles/ping-pong.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/macbookpro/Documents/personal/graphics/ping-pong/ping-pong/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ping-pong.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ping-pong.dir/main.cpp.o -MF CMakeFiles/ping-pong.dir/main.cpp.o.d -o CMakeFiles/ping-pong.dir/main.cpp.o -c /Users/macbookpro/Documents/personal/graphics/ping-pong/ping-pong/main.cpp

CMakeFiles/ping-pong.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ping-pong.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/macbookpro/Documents/personal/graphics/ping-pong/ping-pong/main.cpp > CMakeFiles/ping-pong.dir/main.cpp.i

CMakeFiles/ping-pong.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ping-pong.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/macbookpro/Documents/personal/graphics/ping-pong/ping-pong/main.cpp -o CMakeFiles/ping-pong.dir/main.cpp.s

CMakeFiles/ping-pong.dir/shader.cpp.o: CMakeFiles/ping-pong.dir/flags.make
CMakeFiles/ping-pong.dir/shader.cpp.o: /Users/macbookpro/Documents/personal/graphics/ping-pong/ping-pong/shader.cpp
CMakeFiles/ping-pong.dir/shader.cpp.o: CMakeFiles/ping-pong.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/macbookpro/Documents/personal/graphics/ping-pong/ping-pong/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ping-pong.dir/shader.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ping-pong.dir/shader.cpp.o -MF CMakeFiles/ping-pong.dir/shader.cpp.o.d -o CMakeFiles/ping-pong.dir/shader.cpp.o -c /Users/macbookpro/Documents/personal/graphics/ping-pong/ping-pong/shader.cpp

CMakeFiles/ping-pong.dir/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ping-pong.dir/shader.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/macbookpro/Documents/personal/graphics/ping-pong/ping-pong/shader.cpp > CMakeFiles/ping-pong.dir/shader.cpp.i

CMakeFiles/ping-pong.dir/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ping-pong.dir/shader.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/macbookpro/Documents/personal/graphics/ping-pong/ping-pong/shader.cpp -o CMakeFiles/ping-pong.dir/shader.cpp.s

CMakeFiles/ping-pong.dir/stb_image.cpp.o: CMakeFiles/ping-pong.dir/flags.make
CMakeFiles/ping-pong.dir/stb_image.cpp.o: /Users/macbookpro/Documents/personal/graphics/ping-pong/ping-pong/stb_image.cpp
CMakeFiles/ping-pong.dir/stb_image.cpp.o: CMakeFiles/ping-pong.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/macbookpro/Documents/personal/graphics/ping-pong/ping-pong/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ping-pong.dir/stb_image.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ping-pong.dir/stb_image.cpp.o -MF CMakeFiles/ping-pong.dir/stb_image.cpp.o.d -o CMakeFiles/ping-pong.dir/stb_image.cpp.o -c /Users/macbookpro/Documents/personal/graphics/ping-pong/ping-pong/stb_image.cpp

CMakeFiles/ping-pong.dir/stb_image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ping-pong.dir/stb_image.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/macbookpro/Documents/personal/graphics/ping-pong/ping-pong/stb_image.cpp > CMakeFiles/ping-pong.dir/stb_image.cpp.i

CMakeFiles/ping-pong.dir/stb_image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ping-pong.dir/stb_image.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/macbookpro/Documents/personal/graphics/ping-pong/ping-pong/stb_image.cpp -o CMakeFiles/ping-pong.dir/stb_image.cpp.s

CMakeFiles/ping-pong.dir/vertexManager.cpp.o: CMakeFiles/ping-pong.dir/flags.make
CMakeFiles/ping-pong.dir/vertexManager.cpp.o: /Users/macbookpro/Documents/personal/graphics/ping-pong/ping-pong/vertexManager.cpp
CMakeFiles/ping-pong.dir/vertexManager.cpp.o: CMakeFiles/ping-pong.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/macbookpro/Documents/personal/graphics/ping-pong/ping-pong/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ping-pong.dir/vertexManager.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ping-pong.dir/vertexManager.cpp.o -MF CMakeFiles/ping-pong.dir/vertexManager.cpp.o.d -o CMakeFiles/ping-pong.dir/vertexManager.cpp.o -c /Users/macbookpro/Documents/personal/graphics/ping-pong/ping-pong/vertexManager.cpp

CMakeFiles/ping-pong.dir/vertexManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ping-pong.dir/vertexManager.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/macbookpro/Documents/personal/graphics/ping-pong/ping-pong/vertexManager.cpp > CMakeFiles/ping-pong.dir/vertexManager.cpp.i

CMakeFiles/ping-pong.dir/vertexManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ping-pong.dir/vertexManager.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/macbookpro/Documents/personal/graphics/ping-pong/ping-pong/vertexManager.cpp -o CMakeFiles/ping-pong.dir/vertexManager.cpp.s

CMakeFiles/ping-pong.dir/windowManager.cpp.o: CMakeFiles/ping-pong.dir/flags.make
CMakeFiles/ping-pong.dir/windowManager.cpp.o: /Users/macbookpro/Documents/personal/graphics/ping-pong/ping-pong/windowManager.cpp
CMakeFiles/ping-pong.dir/windowManager.cpp.o: CMakeFiles/ping-pong.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/macbookpro/Documents/personal/graphics/ping-pong/ping-pong/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ping-pong.dir/windowManager.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ping-pong.dir/windowManager.cpp.o -MF CMakeFiles/ping-pong.dir/windowManager.cpp.o.d -o CMakeFiles/ping-pong.dir/windowManager.cpp.o -c /Users/macbookpro/Documents/personal/graphics/ping-pong/ping-pong/windowManager.cpp

CMakeFiles/ping-pong.dir/windowManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ping-pong.dir/windowManager.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/macbookpro/Documents/personal/graphics/ping-pong/ping-pong/windowManager.cpp > CMakeFiles/ping-pong.dir/windowManager.cpp.i

CMakeFiles/ping-pong.dir/windowManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ping-pong.dir/windowManager.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/macbookpro/Documents/personal/graphics/ping-pong/ping-pong/windowManager.cpp -o CMakeFiles/ping-pong.dir/windowManager.cpp.s

CMakeFiles/ping-pong.dir/glad.c.o: CMakeFiles/ping-pong.dir/flags.make
CMakeFiles/ping-pong.dir/glad.c.o: /Users/macbookpro/Documents/personal/graphics/ping-pong/ping-pong/glad.c
CMakeFiles/ping-pong.dir/glad.c.o: CMakeFiles/ping-pong.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/macbookpro/Documents/personal/graphics/ping-pong/ping-pong/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/ping-pong.dir/glad.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ping-pong.dir/glad.c.o -MF CMakeFiles/ping-pong.dir/glad.c.o.d -o CMakeFiles/ping-pong.dir/glad.c.o -c /Users/macbookpro/Documents/personal/graphics/ping-pong/ping-pong/glad.c

CMakeFiles/ping-pong.dir/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/ping-pong.dir/glad.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/macbookpro/Documents/personal/graphics/ping-pong/ping-pong/glad.c > CMakeFiles/ping-pong.dir/glad.c.i

CMakeFiles/ping-pong.dir/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/ping-pong.dir/glad.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/macbookpro/Documents/personal/graphics/ping-pong/ping-pong/glad.c -o CMakeFiles/ping-pong.dir/glad.c.s

# Object files for target ping-pong
ping__pong_OBJECTS = \
"CMakeFiles/ping-pong.dir/main.cpp.o" \
"CMakeFiles/ping-pong.dir/shader.cpp.o" \
"CMakeFiles/ping-pong.dir/stb_image.cpp.o" \
"CMakeFiles/ping-pong.dir/vertexManager.cpp.o" \
"CMakeFiles/ping-pong.dir/windowManager.cpp.o" \
"CMakeFiles/ping-pong.dir/glad.c.o"

# External object files for target ping-pong
ping__pong_EXTERNAL_OBJECTS =

ping-pong: CMakeFiles/ping-pong.dir/main.cpp.o
ping-pong: CMakeFiles/ping-pong.dir/shader.cpp.o
ping-pong: CMakeFiles/ping-pong.dir/stb_image.cpp.o
ping-pong: CMakeFiles/ping-pong.dir/vertexManager.cpp.o
ping-pong: CMakeFiles/ping-pong.dir/windowManager.cpp.o
ping-pong: CMakeFiles/ping-pong.dir/glad.c.o
ping-pong: CMakeFiles/ping-pong.dir/build.make
ping-pong: /usr/local/lib/libglfw.3.3.dylib
ping-pong: CMakeFiles/ping-pong.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/macbookpro/Documents/personal/graphics/ping-pong/ping-pong/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable ping-pong"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ping-pong.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ping-pong.dir/build: ping-pong
.PHONY : CMakeFiles/ping-pong.dir/build

CMakeFiles/ping-pong.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ping-pong.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ping-pong.dir/clean

CMakeFiles/ping-pong.dir/depend:
	cd /Users/macbookpro/Documents/personal/graphics/ping-pong/ping-pong/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/macbookpro/Documents/personal/graphics/ping-pong/ping-pong /Users/macbookpro/Documents/personal/graphics/ping-pong/ping-pong /Users/macbookpro/Documents/personal/graphics/ping-pong/ping-pong/build /Users/macbookpro/Documents/personal/graphics/ping-pong/ping-pong/build /Users/macbookpro/Documents/personal/graphics/ping-pong/ping-pong/build/CMakeFiles/ping-pong.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/ping-pong.dir/depend

