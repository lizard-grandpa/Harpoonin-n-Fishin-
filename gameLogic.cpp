
// *********** CREATE EVENT **********
randomize();      // ensures "random" functions appear random at every run of the game kinda like "srand(time(0));" in c++

score = 0;
global.seconds = 10;
global.minutes = 1;
rectX = 220;
rectX2 = 800;
rectY = 350;
rectY2 = 450;

// *********** STEP EVENT **********
if(keyboard_check_pressed(ord("R"))){ game_restart(); } // mostly for debugging so we can restart the game while it's running 

global.seconds -= 5/room_speed;

if(room != rm_powerUpsStore and room != rm_skinsStore){
global.seconds -= 1/room_speed;
}

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

if(room == rm_skinsStore or room == rm_powerUpsStore){
	
draw_set_color(c_black);
draw_set_alpha(0.3);
draw_rectangle(0, 0, room_width, room_height, false);
draw_set_alpha(0.5);
draw_rectangle(rectX, rectY, rectX2, rectY2, false);
draw_set_alpha(1);

draw_set_color(c_black);
draw_set_alpha(0.5);
draw_rectangle(rectX + 110, rectY + 100, rectX2 - 110, rectY2 + 75, false);
draw_set_alpha(1);

draw_set_color(make_color_rgb(0, 170, 165));
draw_line_width(rectX, rectY, rectX, rectY2, 3);
draw_line_width(rectX2, rectY, rectX2, rectY2, 3);
draw_line_width(rectX, rectY, rectX2, rectY, 3);
draw_line_width(rectX, rectY2, rectX2, rectY2, 3);



draw_text_transformed_colour(rectX + 300, rectY, "UNDER CONSTRUCTION", 1, 1, 0, make_color_rgb(0, 200, 195), make_color_rgb(0, 200, 195), make_color_rgb(0, 200, 195), make_color_rgb(0, 200, 195), 1);
draw_text_transformed_colour(rectX + 290, rectY + 100, "please press 'R' to return", .75, .75, 0, make_color_rgb(0, 170, 165), make_color_rgb(0, 170, 165), make_color_rgb(0, 170, 165), make_color_rgb(0, 170, 165), 1);

}
