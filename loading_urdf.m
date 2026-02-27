robot=importrobot("./rudra_arm/urdf/rudra_arm.urdf");
robot.DataFormat="row";
showdetails(robot);
disp(robot.BaseName);
cyllinder_radius=0.05;
final_position=[1.6,0.2,0.2];
scatter3(final_position(1),final_position(2),final_position(3),'yellow');
[x,y,z]=cylinder(cyllinder_radius);
x=x+1.6;
y=y+0.4;
z=z*0.4;
config = homeConfiguration(robot);

check_base=getTransform(robot,config,"base_link");
disp(check_base);
q0=config;
ik=inverseKinematics("RigidBodyTree",robot);
endEffector="pulley";

weights=[1 1 1 1 1 1];
[a,~]=ik(endEffector,trvec2tform(final_position),weights,q0);
disp(a);

disp(config);

getTransform(robot,homeConfiguration(robot),"turntable","base_link")
figure;
ax=gca;
ax.Projection="orthographic";
hold on;
t = linspace(0, 1, 30);
qTrajectory = q0 + t' * (a-q0); 
overall_frames=size(qTrajectory,1);
surf(x,y,z);
grid on;
view(3);


for i=1:overall_frames
   
   
        show(robot,qTrajectory(i,:),"PreservePlot",false,"FastUpdate",true,"Frames","off");
    
       
        current_eepos=getTransform(robot,qTrajectory(i,:),"turntable");
        current_ee=current_eepos(1:3,4);
        %{
        current_eepos2=getTransform(robot,qTrajectory(i,:),"roll");
        current_ee2=current_eepos2(1:3,4);
        current_eepos3=getTransform(robot,qTrajectory(i,:),"worm_pitch");
        current_ee3=current_eepos3(1:3,4);
        current_eepos4=getTransform(robot,qTrajectory(i,:),"pitch");
        current_ee4=current_eepos4(1:3,4);
        %}
        scatter3(current_ee(1),current_ee(2),current_ee(3),'filled','y');
        %{
        scatter3(current_ee2(1),current_ee2(2),current_ee2(3),'filled','r');
        scatter3(current_ee3(1),current_ee3(2),current_ee3(3),'black');
        scatter3(current_ee4(1),current_ee4(2),current_ee4(3),'green');
        %}
        disp(current_ee);
        %disp(qTrajectory(i,:));
        drawnow;
    
end

%show(robot, a, "Frames","off", "PreservePlot", false);
%show(robot,a,"PreservePlot",true);
camlight;
lighting gouraud;
material metal;
%camorbit(90,0);