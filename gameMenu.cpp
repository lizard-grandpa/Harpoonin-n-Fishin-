// ******* X AND Y COORDINATES ******* 
/*
rm_menu:
	obj_menu = (512, 224)
*/

// ******* CREATE EVENT ******
menuX = x;
menuY = y;
buttonHeight = 64;
titleHeight = -150;

// ------- create menu buttons array 
button[0] = "Start";
button[1] = "Skins Store";
button[2] = "Power Ups Store";
button[3] = "Exit";

buttons = array_length_1d(button); // store the length of the 'button' array 

punSelect = 0;
pun[0] = "Are you squidding me?";
pun[1] = "Whale, whale, whale...what do we have here?";
pun[2] = "Never gonna give you up, never gonna let you drown.";
pun[3] = "How do you tuna fish? Adjust their scales.";
pun[4] = "Why are fish so smart? They live in schools.";
pun[5] = "I'm hooked!";
pun[6] = "Create your own fish pun, don't leave it to salmon else.";
pun[7] = "I think you're fintastic.";
pun[8] = "You're so sofishticated!";
pun[9] = "How do you make an octopus laugh? Give it ten-tickles.";
pun[10] = "Why did the shopkeeper throw the clams out? They were past their shell-by-date.";
pun[11] = "Why is our game incomplete? We kept having to scale back ;^)";
pun[12] = "Why is our game incomplete? We kept having to scale back ;^)";
pun[13] = "Why is our game incomplete? We kept having to scale back ;^)";
pun[14] = "Why is our game incomplete? We kept having to scale back ;^)";
pun[15] = "Why is our game incomplete? We kept having to scale back ;^)";

punSelect = irandom_range(1,15);

menuIndex = 0;
lastSelected = 0; 

// ******* STEP EVENT ********
menuMove = keyboard_check_pressed(vk_down) - keyboard_check_pressed(vk_up);

menuIndex += menuMove;
if(menuIndex < 0)				{ menuIndex = buttons - 1; }
if(menuIndex > (buttons - 1))	{ menuIndex = 0; }

if(menuIndex != lastSelected){ audio_play_sound(s_menuSelect, 1, false); } // plays button switch audio in the menu 

lastSelected = menuIndex;

// ******** DRAW EVENT ********
// ------- drawing title
draw_set_colour(c_black);
draw_set_alpha(0.75);
draw_rectangle(menuX - 290, menuY + 350, menuX + 290, menuY - 150, false);
draw_set_alpha(1);

draw_set_color(make_color_rgb(0, 170, 165));
draw_line_width(menuX - 290, menuY + 350, menuX - 290, menuY - 150, 3);
draw_line_width(menuX + 290, menuY + 350, menuX + 290, menuY - 150, 3);
draw_line_width(menuX - 290, menuY + 350, menuX + 290, menuY + 350, 3);
draw_line_width(menuX - 290, menuY - 150, menuX + 290, menuY - 150, 3);

 
draw_set_font(f_2);
draw_set_halign(fa_center);
draw_set_color(make_color_rgb(0, 170, 165));
draw_text(menuX, menuY + titleHeight, "Harpoon' n' Fishin'");

// ------ drawing menu buttons

var i = 0; // "i" will be used to loop through the button array 

repeat(buttons){
	draw_set_font(f_1);
	draw_set_halign(fa_center);
	draw_set_color(make_color_rgb(0, 100, 95));
	
	if(menuIndex == i)	{ draw_set_color(make_color_rgb(0, 170, 165)); }
	draw_text(menuX, menuY + (buttonHeight * i) , button[i]);
	i++
}

draw_set_colour(c_black);
draw_set_alpha(0.75);
draw_rectangle(0, 625, room_width, 695, false);
draw_set_alpha(1);

draw_set_alpha(1);
draw_text_transformed_colour(512, 224 + 400, pun[punSelect], 0.7, 0.7, 0, make_color_rgb(0, 255, 247), make_color_rgb(0, 255, 247), make_color_rgb(0, 255, 257), make_color_rgb(0, 255, 247), .75);



// ******** KEY PRESS EVENT - ENTER KEY ********
switch(menuIndex){
	case 0:
		room_goto(rm_game); // will go directly to rm_demo after
		audio_play_sound(s_mainTheme, 1, true);
		break;
	case 1: 
		room_goto(rm_skinsStore);
		break;
	case 2: 
		room_goto(rm_powerUpsStore);
		break;
	case 3: 
		game_end(); // closes the game window
		break;
}
