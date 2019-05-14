// **** CREATE EVENT ****
speed = 6;

// **** STEP EVENT ****
// ------- POSITION VARIABLES 
xPosition = 0;
yPosition = 0;

xPosition += speed;
yPosition += speed;
// ------- COLLISION CHECK WITH OBJECTS
// horizontal
barrel_collision = false;

if(xPosition != 0){
	if(place_meeting(x + xPosition, y, obj_oil_barrel)){ // checks if craboo's x & y position collides w/ obj_rock's collision mask
		repeat(abs(xPosition)){					   // repeating for the absolute value amount of xPosition 
			if(!place_meeting(x + sign(xPosition), y ,obj_oil_barrel)) { x += sign(xPosition); } 
			else{ break; }						   //  loop ends once craboo's intended xPosition + or - 1, collides w/ obj_rock
		}
		xPosition = 0;							   // x movement is stopped  
	}
}
// vertical
if(yPosition !=0){
	if(place_meeting(x, y + yPosition, obj_oil_barrel)){
		repeat(abs(yPosition)){
			if(!place_meeting(x, y + sign(yPosition), obj_oil_barrel)) { y += sign(yPosition); }
			else { break; } //  loop ends once craboo's intended yPosition + or - 1, collides w/ obj_rock
		}
		yPosition = 0;      // y movement is stopped 
		barrel_collision = true;
	}	
}

if(barrel_collision){ 
	instance_create_depth(view_xport[0]+ 200, view_yport[0]- 500, -100, obj_oil_spill);
	instance_destroy(obj_harpoon);
	audio_play_sound(Barrel, 10, false);
	
}
// **** COLLISION EVENT W/ OBJ_FISH ****
score += 10;
instance_destroy();
 
// **** OUTSIDE ROOM EVENT ****
instance_destroy();
