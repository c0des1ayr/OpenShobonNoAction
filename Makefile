<<<<<<< Updated upstream
CXX = 
=======
CXX = g++
>>>>>>> Stashed changes
CXXFLAG = 
LIBS = `sdl-config --libs` -lSDL_gfx -lSDL_image -lSDL_mixer -lSDL_ttf

ShobonNoAction:main.o loadg.o DxLib.o
	$(CXX) $^ -o $@ $(LIBS)

%.o:%.cpp
	$(CXX) -c $^ -o $@ $(CXXFLAG)

.PHONY: clean
clean:
	-rm -rf *.o ShobonNoAction