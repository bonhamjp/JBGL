WILD_CARDS=*.cpp **/*.cpp **/**/*.cpp **/**/**/*.cpp **/**/**/**/*.cpp **/**/**/**/**/*.cpp **/**/**/**/**/**/*.cpp **/**/**/**/**/**/**/*.cpp
SOURCE_FILES=$(foreach w, $(WILD_CARDS), $(wildcard ./engine/$w))
FLAGS=-s WASM=1 -s LINKABLE=1 -s EXPORT_ALL=1 -s EXTRA_EXPORTED_RUNTIME_METHODS='["getValue"]' -s ENVIRONMENT='web'
OUTPUT_DIRECTORY=./server/assets/engine
TARGET_FILE=engine

MAC_COMPILER=/Users/johnbonham/Documents/emscripten/em++
MAC_INCLUDE_PATHS=/Users/johnbonham/Documents/glm /Users/johnbonham/Documents/emscripten/system/include ./engine
MAC_INCLUDE_PARAMS=$(foreach d, $(MAC_INCLUDE_PATHS), -I$d)

enginem:
	$(MAC_COMPILER) $(SOURCE_FILES) $(MAC_INCLUDE_PARAMS) $(FLAGS) -o $(OUTPUT_DIRECTORY)/$(TARGET_FILE).js

WINDOWS_COMPILER=em++.bat
WINDOWS_INCLUDE_PATHS=C:/emsdk/upstream/emscripten/system/include C:/glm engine
WINDOWS_INCLUDE_PARAMS=$(foreach d, $(WINDOWS_INCLUDE_PATHS), -I$d)

enginew:
	$(WINDOWS_COMPILER) $(SOURCE_FILES) $(WINDOWS_INCLUDE_PARAMS) $(FLAGS) -o $(OUTPUT_DIRECTORY)/$(TARGET_FILE).js

clean_engine:
	rm $(OUTPUT_DIRECTORY)/$(TARGET_FILE).wasm
	rm $(OUTPUT_DIRECTORY)/$(TARGET_FILE).js

client:
	cd ./client && npm run build --prefix

server:
	cd ./server && go run ./main.go
