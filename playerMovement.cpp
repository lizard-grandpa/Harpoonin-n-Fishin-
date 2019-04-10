// *********CREATE EVENT**********
fastSwimSpeed = 10;
regularSwimSpeed = 4;
swimSpeed = regularSwimSpeed;

// *********STEP EVENT**********
fastSwimSpeed   = keyboard_check(vk_control); // speed variable check

move_left  = keyboard_check(vk_left);   // stored in move variables for collision checks
move_right = keyboard_check(vk_right);
move_up	   = keyboard_check(vk_up);
move_down  = keyboard_check(vk_down);

// ------ UPDATE CRAB SPEED
if(fastSwimSpeed) { swimSpeed = fastSwimSpeed; } // if user holds ctrl key, player's movement is faster
else		 {swimSpeed = regularSwimSpeed; }

// ------- RESET MOVEMENT VARIABLES
xPosition = 0;
yPosition = 0;


// ------- INTENDED MOVEMENT / OPPOSITE KEYS CAN CANCEL EACHOTHER OUT / 8-DIRECTIONAL MOVEMENT 
xPosition = (move_right - move_left) * swimSpeed;
yPosition = (move_down - move_up) * swimSpeed; 

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

// ------- UPDATE USER MOVEMENT
x += xPosition;
y += yPosition;
