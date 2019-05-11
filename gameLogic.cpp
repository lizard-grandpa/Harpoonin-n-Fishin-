// *********** CREATE EVENT **********
randomize();      // ensures "random" functions appear random at every run of the game kinda like "srand(time(0));" in c++
room_goto_next(); // goes to the next room of the game 

// *********** STEP EVENT **********
if(keyboard_check_pressed(ord("R"))){ game_restart(); } // mostly for debugging so we can restart the game while it's running 

// ---- creating fish instances
var fish_count = instance_number(obj_fish);
fish_x = choose(-120, 950);

if(fish_count < 10)
{ 
	instance_create_depth(fish_x, irandom_range(0, 765), 100, obj_fish); // x, y, depth, object
}
