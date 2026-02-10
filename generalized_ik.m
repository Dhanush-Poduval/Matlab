robot=loadrobot("kukaIiwa14","DataFormat","row");
showdetails(robot);
grid on;
endEffector="iiwa_link_ee_kuka";
cup_Height=0.2;
cup_Radius=0.05;
cup_position=[-0.5,0.6,cup_Height/2];
[x,y,z]=cylinder(cup_Radius);
x=x-0.5;
y=y+0.6;
z=z*cup_Height;
q0=homeConfiguration(robot);


ik=inverseKinematics("RigidBodyTree",robot);
weights=[1 1 1 1 1 1];
[a,~]=ik(endEffector,trvec2tform(cup_position),weights,q0);
disp(a);

t = linspace(0, 1, 50);
qTrajectory = q0 + t' * (a - q0); 
overall_frames=size(qTrajectory,1);

figure
hold on;
axis equal;
surf(x,y,z);
for i=1:overall_frames
    show(robot,qTrajectory(i,:),"PreservePlot",false,"FastUpdate",true);
    disp(qTrajectory(i,:));
    drawnow;
end
