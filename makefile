CXX = g++
CXXFLAGS = -I./raylib/include -I./rlImGui -I./imgui -O2
LDFLAGS = -L./raylib/lib -lraylib -lGL -lm -lpthread -ldl

TARGET = render

SRC = window.cpp \
      rlImGui/rlImGui.cpp \
      imgui/imgui.cpp \
      imgui/imgui_draw.cpp \
      imgui/imgui_tables.cpp \
      imgui/imgui_widgets.cpp

OBJ = $(SRC:.cpp=.o)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJ)
