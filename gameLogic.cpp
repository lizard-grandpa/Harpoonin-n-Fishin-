// *********** CREATE EVENT **********
randomize();      // ensures "random" functions appear random at every run of the game kinda like "srand(time(0));" in c++
room_goto_next(); // goes to the next room of the game 

// *********** STEP EVENT **********
if(keyboard_check_pressed(ord("R"))){ game_restart(); } // mostly for debugging so we can restart the game while it's running 
