// **** CREATE EVENT ****
fishSpeed = .85;

xPosition = 0;
yPosition = 0;

spawnRight = 1028;
spawnLeft  = 20;
spawnPoint = spawnRight;; // fish spawn point 

var tempDirection = irandom_range(0,100); // temp variable to choose left or right fish 

if(tempDirection <= 50){
	fishDirection = 1;
	image_angle = -45;
}
else{
	fishDirection = 0;
	image_angle = 48;
	image_xscale *= -1;
}

if(fishDirection == 1 ){
	spawnPoint = spawnLeft;
}

alarm[1] = 1; // fish movement alarm 

// **** STEP EVENT ****

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


var fish_count = instance_number(obj_fish);



if(fish_count < 10)

{ 
	instance_create_depth(spawnPoint, irandom_range(0, 1400), 100, obj_fish); // x, y, depth, object
}

// **** ALARM 1 EVENT ****
xPosition = 0;
yPosition = 0;

var alive = true;
if(alive){
	var dir = choose (1,2);
	if(fishDirection == 0){
		switch(dir){
			case 1:
				xPosition = -fishSpeed;
				yPosition =  fishSpeed;
				break;
			case 2:
				xPosition = -fishSpeed;
				yPosition = -fishSpeed;
				break;	
		}
	}
	if(fishDirection == 1){
		switch(dir){
			case 1:
				xPosition = fishSpeed;
				yPosition = fishSpeed;
				break;
			case 2:
				xPosition =  fishSpeed;
				yPosition = -fishSpeed;
				break;	
		}
	}
}

alarm[1] = random_range(20, 35);

// ****  COLLISION EVENT W/ HARPOON ****
instance_destroy();

// **** OUTSIDE ROOM EVENT ****
instance_destroy();
