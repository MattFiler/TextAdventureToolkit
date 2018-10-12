#include "../AngryStructs/AngryFlightVars.h"

int FlightVars::pullback_force = 0; //The force applied by the player to a bird
int FlightVars::pullback_angle = 0; //The angle applied by the player to a bird

float FlightVars::bird_flight_time = 0; //Resets every time a bird is fired
float FlightVars::bird_start_x = 0; //The starting position (X) of the bird
float FlightVars::bird_start_y = 0; //The starting position (Y) of the bird

float FlightVars::time_between_markers; //Time between the last placed marker and the current frame
int FlightVars::number_of_markers; //Number of markers in-world