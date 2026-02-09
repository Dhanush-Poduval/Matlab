atlas=loadrobot("atlas");
showdetails(atlas);
config=homeConfiguration(atlas);
config(7).JointPosition=pi/2;
disp(config);
endEffector="l_hand_force_torque";
ik=inverseKinematics("RigidBodyTree",atlas);
%creation of the cube
side=0.5;
volume=side*side*side;
sa=6*side*side;


show(atlas,config);
