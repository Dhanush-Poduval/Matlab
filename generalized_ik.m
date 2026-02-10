robot=loadrobot("kukaIiwa14","DataFormat","row");
showdetails(robot);
endEffector="iiwa_link_ee_kuka";
cup_Height=0.2;
cup_Radius=0.05;
cup_position=[-0.5,0.6,cup_Height/2];
[x,y,z]=cylinder(cup_Radius);
x=x-0.5;
y=y+0.6;
z=z*cup_Height;
q0=homeConfiguration(robot);
%{
vector1=q0.vector1;
vector2=q0.vector2;
vector3=q0.vector3;
vector4=q0.vector4;
vector5=q0.vector5;
vector6=q0.vector6;
vector7=q0.vector7;
%}
%vector_q0=[vector1 vector2 vector3 vector4 vector5 vector6 vector7];
%disp(vector_q0);

current_pos=getTransform(robot,q0,endEffector);
end_effecter_pos=current_pos(1:3,4);
disp(end_effecter_pos);
ik=inverseKinematics("RigidBodyTree",robot);
weights=[1 1 1 1 1 1];
[a,~]=ik(endEffector,trvec2tform(cup_position),weights,q0);
t = linspace(0, 1, 50);
qTrajectory = q0 + t' * (a-q0); 
overall_frames=size(qTrajectory,1);
figure
hold on;
axis equal;
view(3);
scatter3(0,0,1.3060,'filled','MarkerFaceColor','y');
surf(x,y,z);
grid on;
show(robot,q0);
for i=1:overall_frames
    show(robot,qTrajectory(i,:),"PreservePlot",false,"FastUpdate",true);
    plot(qTrajectory(i,:),'Color','r','LineStyle','--');
    current_pos=getTransform(robot,qTrajectory(i,:),endEffector);
    current_ee_pos=current_pos(1:3,4);
    scatter3(current_ee_pos(1),current_ee_pos(2),current_ee_pos(3),'filled','MarkerFaceColor','y');
    disp(current_ee_pos);
    drawnow;
end