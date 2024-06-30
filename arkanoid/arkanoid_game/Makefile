#arkanoid utest makefile

CXX = g++
CC = $(CXX)

INCLUDE_PATH= ../inc
SOURCE_PATH= ../src

CFLAGS = -Wall -Werror
CFLAGS+= -Wextra
CFLAGS+= -pedantic
CFLAGS+= -g3


CXXFLAGS = $(CFLAGS)
CXXFLAGS += -std=c++17

# flags for preprocessor
CPPFLAGS= -I$(INCLUDE_PATH)

LDLIBS= -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio
#-lsfml-app 

VALGRIND = valgrind

VFLAGS= --leak-check=full --track-origins=yes --show-leak-kinds=all -s 

OBJECTS = utest.o $(SOURCE_PATH)/ball.o $(SOURCE_PATH)/global_standarts.o $(SOURCE_PATH)/brick.o $(SOURCE_PATH)/physics.o $(SOURCE_PATH)/paddle.o\
$(SOURCE_PATH)/brick_container.o $(SOURCE_PATH)/event_handler.o $(SOURCE_PATH)/level.o $(SOURCE_PATH)/shape_manager.o $(SOURCE_PATH)/graphics.o\
$(SOURCE_PATH)/player_info.o $(SOURCE_PATH)/file_manager.o $(SOURCE_PATH)/levels_manager.o $(SOURCE_PATH)/level_layout.o $(SOURCE_PATH)/game_manager.o\
$(SOURCE_PATH)/sound_manager.o $(SOURCE_PATH)/brick_resilient.o $(SOURCE_PATH)/brick_explosive.o $(SOURCE_PATH)/player.o


all: utest 

utest: $(OBJECTS) 

check: utest
	@./utest -v

clean:
	@$(RM) all $(OBJECTS)

.PHONY: clean all

valgrind:
	$(VALGRIND) $(VFLAGS) ./utest

# dependencies

utest.o:

$(SOURCE_PATH)/ball.o: $(INCLUDE_PATH)/ball.hpp $(INCLUDE_PATH)/global_standarts.hpp

$(SOUREC_PATH)/brick.o: $(INCLUDE_PATH)/brick.hpp $(INCLUDE_PATH)/global_standarts.hpp

$(SOUREC_PATH)/brick_regular.o: $(INCLUDE_PATH)/brick.hpp $(INCLUDE_PATH)/brick_regular.hpp

$(SOURCE_PATH)/global_standarts.o: $(INCLUDE_PATH)/global_standarts.hpp

$(SOURCE_PATH)/physics.o: $(INCLUDE_PATH)/physics.hpp

$(SOURCE_PATH)/paddle.o: $(INCLUDE_PATH)/paddle.hpp

$(SOURCE_PATH)/brick_container.o: $(INCLUDE_PATH)/brick_container.hpp

$(SOURCE_PATH)/event_handler.o: $(INCLUDE_PATH)/event_handler.hpp

$(SOURCE_PATH)/level.o: $(INCLUDE_PATH)/level.hpp

$(SOURCE_PATH)/shape_manager.o: $(INCLUDE_PATH)/shape_manager.hpp

$(SOURCE_PATH)/graphics.o: $(INCLUDE_PATH)/graphics.hpp

$(SOURCE_PATH)/game_manager.o: $(INCLUDE_PATH)/game_manager.hpp

$(SOURCE_PATH)/player_info.o: $(INCLUDE_PATH)/player_info.hpp

$(SOURCE_PATH)/file_manager.o: $(INCLUDE_PATH)/file_manager.hpp $(INCLUDE_PATH)/layout_formatting.hpp

$(SOURCE_PATH)/levels_manager.o: $(INCLUDE_PATH)/levels_manager.hpp

$(SOURCE_PATH)/level_layout.o: $(INCLUDE_PATH)/level_layout.hpp $(INCLUDE_PATH)/layout_formatting.hpp $(INCLUDE_PATH)/global_standarts.hpp

$(SOURCE_PATH)/sound_manager.o: $(INCLUDE_PATH)/sound_manager.hpp

$(SOURCE_PATH)/brick_resilient.o: $(INCLUDE_PATH)/brick_resilient.hpp

$(SOURCE_PATH)/brick_explosive.o: $(INCLUDE_PATH)/brick_explosive.hpp

$(SOURCE_PATH)/player.o: $(INCLUDE_PATH)/player.hpp
