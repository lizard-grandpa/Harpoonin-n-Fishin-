// *********CREATE EVENT**********
fastSwimSpeed = 10;
regularSwimSpeed = 4;
swimSpeed = regularSwimSpeed;
diagonalSpeed = round(swimSpeed * ((sqrt(2))/2)); // due to the pythagorean theorem output of c, we wanna round c to equal a & b 

// *********STEP EVENT**********
fastSwimSpeed   = keyboard_check(vk_control); // speed variable check

move_left  = keyboard_check(ord("A"));        // stored in move variables for collision checks
move_right = keyboard_check(ord("D"));
move_up	   = keyboard_check(ord("W"));
move_down  = keyboard_check(ord("S"));

// ------ UPDATE CRAB SPEED
if(fastSwimSpeed) { swimSpeed = fastSwimSpeed; } // if user holds ctrl key, player's movement is faster
else		  {swimSpeed = regularSwimSpeed; }

// ------- RESET MOVEMENT VARIABLES
xPosition = 0;
yPosition = 0;


// ------- INTENDED MOVEMENT / OPPOSITE KEYS CAN CANCEL EACHOTHER OUT / 8-DIRECTIONAL MOVEMENT 
xPosition = move_right - move_left; // constantly checks for which key is pressed, x-wise
yPosition = move_down - move_up;    // constantly checks for which key is pressed, y-wise 

if(xPosition != 0 && yPosition != 0)  // checks for diagonal movement to adjust speed
{ 
	swimSpeed  = diagonalSpeed; 
	xPosition *= swimSpeed;
	yPosition *= swimSpeed; 
} 
else
{ 
	xPosition *= swimSpeed;
	yPosition *= swimSpeed;
}

// ------- COLLISION CHECK 
// horizontal
if(xPosition != 0){
	if(place_meeting(x + xPosition, y, obj_rock)){ // checks if player's x & y position collides w/ obj_rock's collision mask
		repeat(abs(xPosition)){		       // repeating for the absolute value amount of xPosition 
			if(!place_meeting(x + sign(xPosition), y ,obj_rock)) { x += sign(xPosition); } 
			else{ break; }	//  loop ends once player's intended xPosition + or - 1, collides w/ obj_rock
		}
		xPosition = 0;	        // x movement is stopped  
	}
}
// vertical
if(yPosition !=0){
	if(place_meeting(x, y + yPosition, obj_rock)){
		repeat(abs(yPosition)){
			if(!place_meeting(x, y + sign(yPosition), obj_rock)) { y += sign(yPosition); }
			else { break; } //  loop ends once palyer's intended y Position + or - 1, collides w/ obj_rock
		}
		yPosition = 0;          // y movement is stopped 
	}
}

// ------- COLLISION CHECK WITH ROOM BORDER
// horizontal
if(xPosition != 0){
	if(place_meeting(x + xPosition, y, obj_border)){ // checks if craboo's x & y position collides w/ obj_rock's collision mask
		repeat(abs(xPosition)){					   // repeating for the absolute value amount of xPosition 
			if(!place_meeting(x + sign(xPosition), y ,obj_border)) { x += sign(xPosition); } 
			else{ break; }						   //  loop ends once craboo's intended xPosition + or - 1, collides w/ obj_rock
		}
		xPosition = 0;							   // x movement is stopped  
	}
}
// vertical
if(yPosition !=0){
	if(place_meeting(x, y + yPosition, obj_border)){
		repeat(abs(yPosition)){
			if(!place_meeting(x, y + sign(yPosition), obj_border)) { y += sign(yPosition); }
			else { break; } //  loop ends once craboo's intended yPosition + or - 1, collides w/ obj_rock
		}
		yPosition = 0;      // y movement is stopped 
	}
}

// ------- UPDATE USER MOVEMENT
x += xPosition;
y += yPosition;


// idle player
if (keyboard_lastkey == (ord("A"))) { 
	sprite_index = spr_character_left;
}
