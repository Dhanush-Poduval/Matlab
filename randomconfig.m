robot=loadrobot("fanucLRMate200ib");
showdetails(robot);
config=homeConfiguration(robot);
tform =getTransform(robot,config,'tool0','base');
disp(config);
disp(tform);
show(robot);