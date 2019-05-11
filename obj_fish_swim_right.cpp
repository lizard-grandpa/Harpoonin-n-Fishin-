// ------- UPDATE FISH'S MOVEMENT 
x -= xPosition;
y -= yPosition;
image_xscale = -1;

var fish_count = instance_number(obj_fish_swim_right );



if(fish_count < 10)

{ 

	instance_create_depth(-20, irandom_range(0, 765), 100, obj_fish_swim_right); // x, y, depth, object
	x -= xPosition;
    y -= yPosition;


}
