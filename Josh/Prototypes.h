#ifndef PROTOTYPES
#define PROTOTYPES

void mapGeneration(char[][MAPSIZEX]);
void displayMap(char[][MAPSIZEX]);
void moving(int&, int&, int);
void playerView(Biome&, int, int);
void moveOptions(int, int, int, int[]);
void entityMapGen(char map[][MAPSIZEY][MAPSIZEX]);
void cave(Biome&, int, int);

#endif // PROTOTYPES
