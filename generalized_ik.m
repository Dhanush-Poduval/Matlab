robot=loadrobot("kukaIiwa14");
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
woah=struct2cell(q0);
out=cat(2,woah{:});
disp(out);
%vector_q0=[vector1 vector2 vector3 vector4 vector5 vector6 vector7];
%disp(vector_q0);
ik=inverseKinematics("RigidBodyTree",robot);
weights=[0 0 0 1 1 1];
[a,~]=ik(endEffector,trvec2tform(cup_position),weights,q0);
disp(a);
holy=struct2cell(a);
a_out=cat(2,holy{:});
disp(holy);
t = linspace(0, 1, 50);
qTrajectory = q0 + t' * (a - q0); 
overall_frames=size(qTrajectory,1);
disp(a);
figure
hold on;
axis equal;
surf(x,y,z);
for i=1:overall_frames
    show(robot,qTrajectory(i,:),"PreservePlot",false,"FastUpdate",true);
    plot(qTrajectory(i,:),'Color','r','LineStyle','--');
    disp(qTrajectory(i,:));
    drawnow;
end