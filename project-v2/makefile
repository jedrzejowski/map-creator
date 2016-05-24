
Gpp=g++ -std=c++11 -c $< -o $@

BinDir=debug
OutDir=bin

Objects=\
	$(BinDir)/program.o\
	$(BinDir)/map.o\
	$(BinDir)/settings.o\
	$(BinDir)/random.o\
	$(BinDir)/perlin.o\
	$(BinDir)/svg.o\
	$(BinDir)/color.o\
	$(BinDir)/point.o\
	$(BinDir)/svg-figures.o\
	$(BinDir)/svg-style.o\
	$(BinDir)/svg-gradient.o\
	$(BinDir)/terrain.o\
	$(BinDir)/terrain-land.o\
	$(BinDir)/terrain-forest.o\
	$(BinDir)/terrain-sand.o\
	$(BinDir)/terrain-rocky.o\
	$(BinDir)/terrain-water.o\
	$(BinDir)/terrain-deep.o

$(OutDir)/map.exe: $(Objects)
	g++ -std=c++11 $(Objects) -o $@

# Program

$(BinDir)/program.o: program.cpp
	$(Gpp)

# Map 

$(BinDir)/map.o: map.cpp map.h
	$(Gpp)

$(BinDir)/settings.o: settings.cpp settings.h
	$(Gpp)


# Random library

$(BinDir)/random.o: random.cpp random.h
	$(Gpp)

$(BinDir)/perlin.o: perlin.cpp perlin.h
	$(Gpp)


#
# SVG library
#

$(BinDir)/svg.o: svg.cpp svg.h
	$(Gpp)

$(BinDir)/color.o: color.cpp color.h
	$(Gpp)

$(BinDir)/point.o: point.cpp point.h
	$(Gpp)

$(BinDir)/svg-figures.o: svg-figures.cpp svg-figures.h
	$(Gpp)

$(BinDir)/svg-style.o: svg-style.cpp svg-style.h
	$(Gpp)

$(BinDir)/svg-gradient.o: svg-gradient.cpp svg-gradient.h
	$(Gpp)

#
# Terrain library
#

$(BinDir)/terrain.o: terrain.cpp terrain.h
	$(Gpp)

$(BinDir)/terrain-land.o: terrain-land.cpp terrain-land.h
	$(Gpp)

$(BinDir)/terrain-forest.o: terrain-forest.cpp terrain-forest.h
	$(Gpp)

$(BinDir)/terrain-sand.o: terrain-sand.cpp terrain-sand.h
	$(Gpp)

$(BinDir)/terrain-rocky.o: terrain-rocky.cpp terrain-rocky.h
	$(Gpp)

$(BinDir)/terrain-water.o: terrain-water.cpp terrain-water.h
	$(Gpp)

$(BinDir)/terrain-deep.o: terrain-deep.cpp terrain-deep.h
	$(Gpp)
