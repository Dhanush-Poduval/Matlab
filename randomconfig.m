robot=loadrobot("fanucLRMate200ib");
showdetails(robot);
config=homeConfiguration(robot);
tform =getTransform(robot,config,'tool0','base');
config(3).JointPosition=pi/2;
disp(config);
disp(tform);
show(robot,randomConfiguration(robot));