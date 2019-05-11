// ***** CREATE EVENT ****
imageSpeed = .1;
oilSpillSize = 3;
fadeOilSpill = false;

alarm[1] = room_speed * 4; // 4 seconds

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
