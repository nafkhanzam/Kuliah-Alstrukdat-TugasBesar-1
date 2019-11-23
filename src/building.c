#include "building.h"

Building new_Building(char c, int x, int y, int owner) {
    Building res;
    position(&res) = (Point*) malloc(sizeof(Point));
    *position(&res) = new_Point(x, y);
    armyCount(&res) = Building_getStartingArmy(c);
    level(&res) = 1;
    owner(&res) = owner;
    type(&res) = c;
    return res;
}

boolean Building_levelUp(Building* p) {
    
}

void Building_printList(Game* p, List list, char* title) {
    
}

void Building_printStatus(Building* p, int number) {
    printf("%d. %s (%d,%d) %d lv. %d\n", number, Building_getName(type(p)), x(position(p)), y(position(p)), armyCount(p), level(p));
}

int Building_getMaxArmy(char type, int level) {
    switch (type) {
        case 'C': return 20*(level+1);
        case 'T': return 10*(level+1);
        case 'F': return 20*level;
        case 'V': return 10*(level+1);
    }
    return -1;
}

int Building_getArmyAddition(char type, int level) {
    switch (type) {
        case 'C': return 5*(level+1);
        case 'T': return 10*(level-1) + (level == 1 ? 5 : 0);
        case 'F': return 10*level;
        case 'V': return 5*level;
    }
    return -1;
}

char* Building_getName(char type) {
    switch (type) {
        case 'C': return "Castle";
        case 'T': return "Tower";
        case 'F': return "Fort";
        case 'V': return "Village";
    }
    return NULL;
}

boolean Building_isShielded(char type, int level) {
    return type != 'C' && type != 'V' && (type == 'T' || level >= 3);
}

int Building_getStartingArmy(char type) {
    switch (type) {
        case 'C': return 40;
        case 'T': return 30;
        case 'F': return 80;
        case 'V': return 20;
    }
    return -1;
}

void Building_setOwner(Building* p, Game* gp, int toOwner) {
    
}
