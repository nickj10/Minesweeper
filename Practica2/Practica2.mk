##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Practica2
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/PGM/Documents/practica2_buscamines/Practica2
ProjectPath            :=C:/Users/PGM/Documents/practica2_buscamines/Practica2
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=PGM
Date                   :=05/04/2018
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/MinGW-4.8.1/bin/g++.exe
SharedObjectLinkerName :=C:/MinGW-4.8.1/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Practica2.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/MinGW-4.8.1/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)allegro-5.0.10-monolith-mt-debug 
ArLibs                 :=  "liballegro-5.0.10-monolith-mt-debug.a" 
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/MinGW-4.8.1/bin/ar.exe rcu
CXX      := C:/MinGW-4.8.1/bin/g++.exe
CC       := C:/MinGW-4.8.1/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/MinGW-4.8.1/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/LS_allegro.c$(ObjectSuffix) $(IntermediateDirectory)/ranking.c$(ObjectSuffix) $(IntermediateDirectory)/main.c$(ObjectSuffix) $(IntermediateDirectory)/draw.c$(ObjectSuffix) $(IntermediateDirectory)/game.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/LS_allegro.c$(ObjectSuffix): LS_allegro.c $(IntermediateDirectory)/LS_allegro.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/PGM/Documents/practica2_buscamines/Practica2/LS_allegro.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/LS_allegro.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/LS_allegro.c$(DependSuffix): LS_allegro.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/LS_allegro.c$(ObjectSuffix) -MF$(IntermediateDirectory)/LS_allegro.c$(DependSuffix) -MM LS_allegro.c

$(IntermediateDirectory)/LS_allegro.c$(PreprocessSuffix): LS_allegro.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/LS_allegro.c$(PreprocessSuffix) LS_allegro.c

$(IntermediateDirectory)/ranking.c$(ObjectSuffix): ranking.c $(IntermediateDirectory)/ranking.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/PGM/Documents/practica2_buscamines/Practica2/ranking.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ranking.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ranking.c$(DependSuffix): ranking.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ranking.c$(ObjectSuffix) -MF$(IntermediateDirectory)/ranking.c$(DependSuffix) -MM ranking.c

$(IntermediateDirectory)/ranking.c$(PreprocessSuffix): ranking.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ranking.c$(PreprocessSuffix) ranking.c

$(IntermediateDirectory)/main.c$(ObjectSuffix): main.c $(IntermediateDirectory)/main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/PGM/Documents/practica2_buscamines/Practica2/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/main.c$(DependSuffix) -MM main.c

$(IntermediateDirectory)/main.c$(PreprocessSuffix): main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.c$(PreprocessSuffix) main.c

$(IntermediateDirectory)/draw.c$(ObjectSuffix): draw.c $(IntermediateDirectory)/draw.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/PGM/Documents/practica2_buscamines/Practica2/draw.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/draw.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/draw.c$(DependSuffix): draw.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/draw.c$(ObjectSuffix) -MF$(IntermediateDirectory)/draw.c$(DependSuffix) -MM draw.c

$(IntermediateDirectory)/draw.c$(PreprocessSuffix): draw.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/draw.c$(PreprocessSuffix) draw.c

$(IntermediateDirectory)/game.c$(ObjectSuffix): game.c $(IntermediateDirectory)/game.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/PGM/Documents/practica2_buscamines/Practica2/game.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/game.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/game.c$(DependSuffix): game.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/game.c$(ObjectSuffix) -MF$(IntermediateDirectory)/game.c$(DependSuffix) -MM game.c

$(IntermediateDirectory)/game.c$(PreprocessSuffix): game.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/game.c$(PreprocessSuffix) game.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


