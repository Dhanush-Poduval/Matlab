robot=loadrobot("kukaIiwa14","DataFormat","row");
config=[-0.7305,10.3247,1.0762,-4.4834,-0.1019,-0.0022,1.1616];
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
velocities=[0,0,1,0,0,0]';
%show(robot,config);

for i=1:200
 [ee_new_config , ~]=psudoinverse_function(endEffector,velocities,config);
 config=ee_new_config;
 ee_pos=getTransform(robot,config,"iiwa_link_ee_kuka");
 test_ee_pos=ee_pos(1:3,4);
 delta=test_ee_pos-inital_ee_pos;
 fprintf("dx : %.6f dy : %.6f dz : %.6f\n",delta(1),delta(2),delta(3));
 show(robot,ee_new_config,"PreservePlot",false,"FastUpdate",true);
 drawnow;
 inital_ee_pos=test_ee_pos;
end
disp(test_ee_pos);

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
