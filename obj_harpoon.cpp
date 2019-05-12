// **** CREATE EVENT ****
speed = 6;

// **** COLLISION EVENT W/ OBJ_FISH ****
score += 10;
instance_destroy();

// **** COLLISION EVENT W/ OBJ_OIL_BARREL
instance_create_depth(view_xport[0], view_yport[0], -100, obj_oil_spill);
 
// **** OUTSIDE ROOM EVENT ****
instance_destroy();
