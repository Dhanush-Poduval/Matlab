robot=loadrobot("kukaIiwa14","DataFormat","row");
config=homeConfiguration(robot);
endEffector="iiwa_link_ee_kuka";
check_base=getTransform(robot,config,endEffector);
rotation=check_base(1:3,1:3);
disp(rotation);
eul=rotm2eul(rotation);
%inital vector 
inital_ee_pos=check_base(1:3,4);
disp(inital_ee_pos);
disp(check_base);
%joystick sim

joy=sim3d.io.Joystick();
while true 
    axes=axis(joy);
    buttons=button(joy);
    x=axes(1);
    y=axes(2);
    disp([x,y]);
    pause(0.01);
end

%show(robot,config);
%showdetails(robot);
