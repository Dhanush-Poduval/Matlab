L1=0.3;
L2=0.3;
EE=0.05;
body1=rigidBody('Body1');
jnt1=rigidBodyJoint('jnt1','revolute');
setFixedTransform(jnt1,trvec2tform([0 0 0]));
jnt1.JointAxis=[0 0 1];
%addVisual(body1,'Cylinder',[0.03 0.3]);
body1.Joint=jnt1;
robot=rigidBodyTree("DataFormat","row");
addBody(robot,body1,'base');
body2=rigidBody('body2');
jnt2=rigidBodyJoint('jnt2','revolute');
setFixedTransform(jnt2,trvec2tform([L1 0 0]))
%addVisual(body2,'Cylinder',[0.03 0.3])
body2.Joint=jnt2;
jnt2.JointAxis=[0 0 1];
addBody(robot,body2,'Body1');
body3=rigidBody('tool_tip');
jnt3=rigidBodyJoint('jnt3','fixed');
setFixedTransform(jnt3,trvec2tform([L2 0 0]));
%jnt3.JointAxis=[0 0 1];
%addVisual(body3,'Cylinder',[0.03 0.3]);
body3.Joint=jnt3;
q1=pi/4;
q2=pi/6;
addBody(robot,body3,'body2');
showdetails(robot);
config=homeConfiguration(robot);
%config=randomConfiguration(robot);

disp(config);
writeAsFunction(robot,'robotBuildforCodegen');
%s=show(robot ,config);
%hold(s,'on');

%circle formation for later ik
t = (0:0.2:10)';
count = length(t);
center_x=0.3;
center_y=0.1;
r=0.15;
theta=linspace(0,2*pi,500);
x=center_x+r*cos(theta);
y=center_y+r*sin(theta);
points=[x;y;zeros(size(x))];
r_points=points';
disp(size(r_points));
%plot(x,y,'b','LineWidth',2)
%axis(s,'equal')
%grid (s,'on')
%the ik part using normal inverseKinematics function as dont need multiple

%constraints
q0=homeConfiguration(robot);
ik=inverseKinematics('RigidBodyTree',robot);
weights=[0,0,0,1,1,0];
endEffector="tool_tip";
q_initial=q0;
num_points=size(r_points,1);
[q_arr,theta_array]=ik_function(endEffector,weights,r_points,q_initial,num_points);
%{
q_arr=zeros(num_points,2);
for i=1:num_points
    point=r_points(i,:);
    
    [a,b]=ik(endEffector,trvec2tform(point),weights,q_initial);
    q_arr(i,:)=a;
    q_initial=a;
    theta_array(i,:)=[a];

end

disp(b);
%}
disp(theta_array)
disp(size(theta_array))
%for like animating the movement
figure
view(2);
ax=gca;
ax.Projection='orthographic';
hold on;
plot(r_points(:,1),r_points(:,2));
overall_frames=size(q_arr,1);
%axis([-0.1 0.7 -0.3 0.5 -0.2 0.2])
%animate da ting
for i=1:overall_frames
    show(robot,q_arr(i,:),'PreservePlot',false,'FastUpdate',true);
    drawnow;
end


