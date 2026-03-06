robot=loadrobot("kukaIiwa14","DataFormat","row");
config=homeConfiguration(robot);
endEffector="iiwa_link_ee_kuka";
check_base=getTransform(robot,config,"iiwa_link_ee_kuka");
rotation=check_base(1:3,1:3);
disp(rotation);
eul=rotm2eul(rotation);
disp(eul);
%inital vector 
inital_ee_pos=check_base(1:3,4);
disp(inital_ee_pos);
disp(check_base);
%joystick sim
    
%{
joy=sim3d.io.Joystick();
while true 
    axes=axis(joy);
    buttons=button(joy);
    x=axes(1);
    y=axes(2);
    disp([x,y]);
    pause(0.01);
end
%}
dt=0.05;
velocities=[0.3,0.4,0.3,0,0,0]';
[ee_new_config , ~]=psudoinverse_function(endEffector,velocities);
show(robot,ee_new_config)
    %{
    J=geometricJacobian(robot,config,endEffector);
    dq=pinv(J)*velocities;
    disp(det(J*J'));
    config=config+dq' *dt;
    check_endeffector=getTransform(robot,config,endEffector);
    ee_pos=check_endeffector(1:3,4);
    disp(ee_pos);
    show(robot,config,"PreservePlot",false,"FastUpdate",true);
    drawnow
    %}
showdetails(robot);
