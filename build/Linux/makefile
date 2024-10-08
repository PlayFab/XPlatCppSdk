# Instructions to build XPlatCppSDK with GCC on Linux:
#
# 1. Make sure to update apt packages:
#	sudo apt-get update
#	sudo apt-get upgrade
# 2. Make sure to have gcc installed:
#	sudo apt install gcc (if needed)
#	sudo apt-get install --reinstall build-essential (if needed, if you are getting "gcc: error trying to exec 'cc1plus': execvp: No such file or directory" on build)
# 3. Install curl:
#	sudo apt-get install libcurl4-openssl-dev
# 4. Install jsoncpp:
#	sudo apt-get install libjsoncpp-dev
# 5. Install openssl (used for the linux cpp test runner):
#	sudo apt-get install libssl-dev
# 6. Build and run XPlatCppLinux test app:
#	make all
#	./XPlatCppLinux

# Here is a simple Make Macro.
LINK_TARGET = XPlatCppLinux

# Here is a Make Macro that uses the backslash to extend to multiple lines.
OBJS = stdafx.o \
	PlayFabAuthenticationContext.o \
	PlayFabApiSettings.o \
	PlayFabAdminApi.o \
	PlayFabAdminInstanceApi.o \
	PlayFabClientApi.o \
	PlayFabClientInstanceApi.o \
	PlayFabServerApi.o \
	PlayFabServerInstanceApi.o \
	PlayFabAuthenticationApi.o \
	PlayFabAuthenticationInstanceApi.o \
	PlayFabCloudScriptApi.o \
	PlayFabCloudScriptInstanceApi.o \
	PlayFabDataApi.o \
	PlayFabDataInstanceApi.o \
	PlayFabEconomyApi.o \
	PlayFabEconomyInstanceApi.o \
	PlayFabEventsApi.o \
	PlayFabEventsInstanceApi.o \
	PlayFabExperimentationApi.o \
	PlayFabExperimentationInstanceApi.o \
	PlayFabInsightsApi.o \
	PlayFabInsightsInstanceApi.o \
	PlayFabGroupsApi.o \
	PlayFabGroupsInstanceApi.o \
	PlayFabProgressionApi.o \
	PlayFabProgressionInstanceApi.o \
	PlayFabLocalizationApi.o \
	PlayFabLocalizationInstanceApi.o \
	PlayFabMultiplayerApi.o \
	PlayFabMultiplayerInstanceApi.o \
	PlayFabProfilesApi.o \
	PlayFabProfilesInstanceApi.o \
	PlayFabMatchmakerApi.o \
	PlayFabMatchmakerInstanceApi.o \
	PlayFabAddonApi.o \
	PlayFabAddonInstanceApi.o \
	PlayFabCallRequestContainer.o \
	PlayFabCallRequestContainerBase.o \
	PlayFabError.o \
	PlayFabCurlHttpPlugin.o \
	PlayFabPluginManager.o \
	PlayFabSettings.o \
	PlayFabEvent.o \
	PlayFabEventApi.o \
	PlayFabEventBuffer.o \
	PlayFabEventPipeline.o \
	PlayFabEventRouter.o \
	PlayFabSpinLock.o \
	RegionResult.o \
	PlayFabQoSApi.o \
	QoSSocket.o \
	XPlatSocket.o \
    TestAppLinux.o \
    PlayFabEventTest.o \
    PlayFabTestMultiUserInstance.o \
    PlayFabTestMultiUserStatic.o \
    PlayFabTestAlloc.o \
    TestContext.o \
    TestUtils.o \
    TestReport.o \
    TestRunner.o \
    PlayFabApiTest.o \
    PlatformLoginTest_default.o \
    TestApp.o \
	main.o

# Relative path to the project root directory
PROJ_DIR = ../..

# Here is a Make Macro defined by two Macro Expansions.
# A Macro Expansion may be treated as a textual replacement of the Make Macro.
# Macro Expansions are introduced with $ and enclosed in (parentheses).
REBUILDABLES = $(OBJS) $(LINK_TARGET)

# Here is a simple Rule (used for "cleaning" your build environment).
# It has a Target named "clean" (left of the colon ":" on the first line),
# no Dependencies (right of the colon),
# and two Commands (indented by tabs on the lines that follow).
# The space before the colon is not required but added here for clarity.
clean : 
	rm -f $(REBUILDABLES)
	echo Clean done

# There are two standard Targets your Makefile should probably have:
# "all" and "clean", because they are often command-line Goals.
# Also, these are both typically Artificial Targets, because they don't typically
# correspond to real files named "all" or "clean".  

# The rule for "all" is used to incrementally build your system.
# It does this by expressing a dependency on the results of that system,
# which in turn have their own rules and dependencies.
all : $(LINK_TARGET)
	echo All done

# There is no required order to the list of rules as they appear in the Makefile.
# Make will build its own dependency tree and only execute each rule only once
# its dependencies' rules have been executed successfully.

# Here is a Rule that uses some built-in Make Macros in its command:
# $@ expands to the rule's target, in this case "test_me.exe".
# $^ expands to the rule's dependencies, in this case the three files
# main.o, test1.o, and  test2.o.
# -lstdc++ -L/usr/lib/x86_64-linux-gnu/ -ljsoncpp
$(LINK_TARGET) : $(OBJS)
	g++ -o $@ $^ -ljsoncpp -lcurl -lssl -lpthread
# Here is the compilation command Make Macro:
COMPILE_CMD = \
	g++ -include $(PROJ_DIR)/code/stdafx.h -I $(PROJ_DIR)/code -I $(PROJ_DIR)/code/include -I $(PROJ_DIR)/test/TestApp/ -include $(PROJ_DIR)/test/TestApp/TestAppPch.h -D ENABLE_PLAYFABADMIN_API -D ENABLE_PLAYFABSERVER_API -o $@ -c $<
# Here is a Pattern Rule, often used for compile-line.
# It says how to create a file with a .o suffix, given a file with a .cpp suffix.
# The rule's command uses some built-in Make Macros:
# $@ for the pattern-matched target
# $< for the pattern-matched dependency
%.o : $(PROJ_DIR)/code/source/playfab/%.cpp
	$(COMPILE_CMD)
%.o : $(PROJ_DIR)/code/source/playfab/QoS/%.cpp
	$(COMPILE_CMD)
%.o : $(PROJ_DIR)/test/TestApp/%.cpp
	$(COMPILE_CMD)
TestAppLinux.o : $(PROJ_DIR)/build/Linux/TestAppLinux.cpp
	$(COMPILE_CMD)
stdafx.o : $(PROJ_DIR)/code/stdafx.cpp
	$(COMPILE_CMD)
main.o : $(PROJ_DIR)/build/Linux/MainLinux.cpp
	$(COMPILE_CMD)
# These are Dependency Rules, which are rules without any command.
# Dependency Rules indicate that if any file to the right of the colon changes,
# the target to the left of the colon should be considered out-of-date.
# The commands for making an out-of-date target up-to-date may be found elsewhere
# (in this case, by the Pattern Rule above).
# Dependency Rules are often used to capture header file dependencies.

#Main.o : Main.h Test1.h Test2.h
#Test1.o : Test1.h Test2.h
#Test2.o : Test2.h

# Alternatively to manually capturing dependencies, several automated
# dependency generators exist.  Here is one possibility (commented out)...
# %.dep : %.cpp
#   g++ -M $(FLAGS) $< > $@
# include $(OBJS:.o=.dep)