robot=loadrobot("kukaIiwa14","DataFormat","row");
config=randomConfiguration(robot);
check_base=getTransform(robot,config,"world");
endEffector="iiwa_link_ee_kuka";
disp(check_base);
show(robot,config);
showdetails(robot);
