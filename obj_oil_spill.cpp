// ***** CREATE EVENT ****
imageSpeed = .1;
oilSpillSize = 2;
fadeOilSpill = false;

alarm[1] = room_speed * 2; // 2 seconds

// ***** STEP EVENT *****
if(image_xscale < oilSpillSize){
	image_xscale += imageSpeed;
	image_yscale += imageSpeed;
}

else{
	image_xscale = oilSpillSize;
	image_yscale = oilSpillSize;
}

if(fadeOilSpill){
	image_alpha += -.01;
}

if(fadeOilSpill == -1){
	instance_destroy(obj_oil_spill);  // destroys instance after it isn't visible 
}
// **** ALARM 1 ****
fadeOilSpill = true;

// **** DRAW GUI EVENT ****
draw_sprite_ext(spr_oil_spill, 0, obj_oil_barrel.x, obj_oil_barrel.y, image_xscale, image_yscale, 0, c_white,image_alpha);
 
