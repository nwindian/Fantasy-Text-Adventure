#ifndef PROTOTYPES
#define PROTOTYPES

void mapGeneration(char[][MAPSIZEX]);
void displayMap(char[][MAPSIZEX], int);
void moving(int&, int&, int, Biome&, Stamina&, int[]);
void playerView(Biome&, int, int, Stamina&);
void moveOptions(int, int, int, int[]);
void entityMapGen(char map[][MAPSIZEY][MAPSIZEX]);
void cave(Biome&, int, int);
void startMap();
void cursorSet(int, int);
char entityCheck(Biome&, int, int);
void village();

#endif // PROTOTYPES
