
// *********** CREATE EVENT **********
randomize();      // ensures "random" functions appear random at every run of the game kinda like "srand(time(0));" in c++

score = 0;
global.seconds = 10;
global.minutes = 1;

// *********** STEP EVENT **********
if(keyboard_check_pressed(ord("R"))){ game_restart(); } // mostly for debugging so we can restart the game while it's running 

global.seconds -= 5/room_speed;

if (global.seconds > 0) and (global.seconds < 0.1) and ((global.minutes >= 1)){
	global.seconds = 60;
	global.minutes -= 1;
}

if ((global.seconds < 1) and (global.minutes == 0)){
	room_goto(rm_end);
	instance_destroy(game);
}

// *********** DRAW GUI EVENT **********

if (room = rm_game){
	
	//draws score to screen
	var drawSec;
	drawSec = floor(global.seconds);

	draw_set_colour(c_black);
	draw_set_alpha(0.75);
	draw_rectangle(10, 20, 205, 105, false);
	draw_set_alpha(1);
	draw_set_color(make_color_rgb(0, 170, 165));

	draw_set_color(make_color_rgb(0, 170, 165));
	draw_line_width(10, 20, 10, 105, 3);
	draw_line_width(10, 20, 205, 20, 3);
	draw_line_width(205, 20, 205, 105, 3);
	draw_line_width(10, 105, 205, 105, 3);

	draw_text(105, 15, "Gold: " + string(score));
	
	//draws timer to screen
	draw_set_colour(c_black);
	draw_set_alpha(0.75);
	draw_rectangle(815, 20, 1010, 105, false);
	draw_set_alpha(1);
	draw_set_color(make_color_rgb(0, 170, 165));

	draw_set_color(make_color_rgb(0, 170, 165));
	draw_line_width(815, 20, 815, 105, 3);
	draw_line_width(815, 20, 1010, 20, 3);
	draw_line_width(1010, 20, 1010, 105, 3);
	draw_line_width(815, 105, 1010, 105, 3);

	if (drawSec < 10){
		draw_text(910, 8, string(global.minutes) + ":0" + string(drawSec));
	}
	else {
		draw_text(910, 8, string(global.minutes) + ":" + string(drawSec));
	}
}
