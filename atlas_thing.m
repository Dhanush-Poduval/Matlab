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
corners=-pi:pi/2:pi;
orientation=pi/4;
x=[cos(corners+orientation);cos(corners+orientation)]/cos(orientation);
y=[sin(corners+orientation);sin(corners+orientation)]/sin(orientation);
z=[-ones(size(corners));ones(size(corners))];
surf(x,y,z,'FaceColor','w');
sa=6*side*side;
hold on 
show(atlas,config);
hold off
