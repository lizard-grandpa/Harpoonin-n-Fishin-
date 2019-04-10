// ************* CREATE EVENT *************
fishSpeed = 1; // can be changed later 

xPosition = 0; // fish wont be moving at the start of the game, can be changed later 
yPosition = 0;

alarm[1] = room_speed; //  alarm 1 will go off at room_speed = 60 frames = 1 second 

// ************* STEP EVENT ************* 
// ------- COLLISION CHECK
// horizontal
if(xPosition != 0){
	if(place_meeting(x + xPosition, y, obj_rock)){ // checks if fish's x & y collides w/ obj_rock's collision mask
		repeat(abs(xPosition)){					             // repeating for the absolute value amount of xPosition 
			if(!place_meeting(x + sign(xPosition), y ,obj_rock)) { x += sign(xPosition); } 
			else{ break; }	//  loop ends once fish's intended xPosition + or - 1, collides w/ obj_rock
		}
		xPosition = 0;	  // x movement is stopped  
	}
}
// vertical
if(yPosition !=0){
	if(place_meeting(x, y + yPosition, obj_rock)){
		repeat(abs(yPosition)){
			if(!place_meeting(x, y + sign(yPosition), obj_rock)) { y += sign(yPosition); }
			else { break; } //  loop ends once fish's intended yPosition + or - 1, collides w/ obj_rock
		}
		yPosition = 0;    // y movement is stopped 
	}
}

// ------ UPDATE MOVEMENT
x += xPosition;
y += yPosition;

// ************* ALARM 1  *************

xPosition = 0; //  we reset the fish to stop moving
yPosition = 0;

var idle = choose(0,1); // randomly choose between 0 & 1
if(idle == false){      // if it chooses "0", the fish may randomly move up, down, left or right, if it chooses "1" the fish idles 
	var dir = choose(1,2,3,4);
	switch(dir){
		case 1:
			xPosition = -fishSpeed; break;
		case 2:
			xPosition = fishSpeed; break;
		case 3:
			yPosition = -fishSpeed; break;
		case 4: 
			yPosition = fishSpeed; break;
	}
}

alarm[1] = random_range(2.5, 4) * room_speed; //  the alarm goes off again at a random # between 2.5 to 4 times 60: so most likey 2-4 seconds
