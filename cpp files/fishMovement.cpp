// ************* CREATE EVENT *************
fishSpeed = .85; // fish speed can be changed 

xPosition = 0;   // x & y position of fish - not moving 
yPosition = 0;

alarm[1] = 1; // fish begin moving 1 step after game starts 

// ************* STEP EVENT ************* 
// ------- CHECKS PLAYER DISTANCE TO FISH 
if(distance_to_object(instance_nearest(x,y,obj_player)) <= 25){
	move_towards_point(instance_nearest(x,y,obj_border).x, instance_nearest(x,y,obj_border).y,0.95);	
}
// !!!! needs alot of work --- NOTES BELOW:
// * cancel out alarm [1] or later it's movement maybe create a bool to trigger a different movement & adjust speed 
// * fish seem to swim to obj_border closest to em but adjust it to make sure
// * maybe add speed into the if statement above to force player to have more stealth, option for later tho 


// ------- UPDATE FISH'S MOVEMENT 
x += xPosition;
y += yPosition;

// ************* ALARM 1  *************

xPosition = 0;
yPosition = 0;

var alive = true;
if(alive){
	var dir = choose (1,2);//choose(1,2,3,4);
	switch(dir){
		case 1:
			xPosition = -fishSpeed;
			yPosition = fishSpeed;
			break;
		case 2:
			xPosition = -fishSpeed;
			yPosition = -fishSpeed;
			break;
		//case 3:
		//	yPosition = -fishSpeed; break;
		//case 4: 
		//	yPosition = fishSpeed; break;		
	}
}

alarm[1] = random_range(20, 35);

// ******** OUTSIDE ROOM EVENT ********
instance_destroy();
