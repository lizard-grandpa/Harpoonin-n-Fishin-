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

// ******** KEY PRESS EVENT - ENTER KEY ********
switch(menuIndex){
	case 0:
		room_goto(rm_game); // will go directly to rm_demo after
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
