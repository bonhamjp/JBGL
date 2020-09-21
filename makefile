INCLUDE_PATHS=C:/emsdk/upstream/emscripten/system/include C:/glm engine
INCLUDE_PARAMS=$(foreach d, $(INCLUDE_PATHS), -I$d)
OUTPUT_DIRECTORY=./server/assets/engine
COMPILER=em++.bat
SOURCE_FILES=$(wildcard ./engine/*.cpp) $(wildcard ./engine/**/*.cpp) $(wildcard ./engine/**/**/*.cpp) $(wildcard ./engine/**/**/**/*.cpp) $(wildcard ./engine/**/**/**/**/*.cpp) $(wildcard ./engine/**/**/**/**/**/*.cpp) $(wildcard ./engine/**/**/**/**/**/**/*.cpp) # got to be a better way
FLAGS=-s WASM=1 -s LINKABLE=1 -s EXPORT_ALL=1 -s EXTRA_EXPORTED_RUNTIME_METHODS='["getValue"]' -s ENVIRONMENT='web'
TARGET_FILE=engine

engine:
	$(COMPILER) $(SOURCE_FILES) $(INCLUDE_PARAMS) $(FLAGS) -o $(OUTPUT_DIRECTORY)/$(TARGET_FILE).js

clean_engine:
	rm $(OUTPUT_DIRECTORY)/$(TARGET_FILE).wasm
	rm $(OUTPUT_DIRECTORY)/$(TARGET_FILE).js

client:
	npm run build --prefix ./client

server:
	cd ./server
	go run ./main.go

server_pid:
	@echo $(shell netstat -ano | findstr 8080)

server_kill:
	tskill $(pid)
