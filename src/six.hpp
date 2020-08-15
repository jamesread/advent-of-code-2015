#pragma once

enum Action {
	TURN_ON,
	TURN_OFF,
	TOGGLE
};

struct SantaLightingCommandment {
	Action action;

	uint32_t fromCol;
	uint32_t fromRow;
   	uint32_t toCol;
	uint32_t toRow;	
}; 

SantaLightingCommandment* parseCommandment(string line);
void processCommandment(SantaLightingCommandment* slc);
void set(int row, int col, bool value);
int countLights();
