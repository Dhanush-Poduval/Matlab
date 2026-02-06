L1=0.3;
L2=0.3;
EE=0.05;
body1=rigidBody('Body1');
jnt1=rigidBodyJoint('jnt1','revolute');
setFixedTransform(jnt1,trvec2tform([0 0 0]));
jnt1.JointAxis=[0 0 1];
addVisual(body1,'Cylinder',[0.03 0.3]);
body1.Joint=jnt1;
robot=rigidBodyTree;
addBody(robot,body1,'base');
body2=rigidBody('body2');
jnt2=rigidBodyJoint('jnt2','revolute');
setFixedTransform(jnt2,trvec2tform([L1 0 0]))
addVisual(body2,'Cylinder',[0.03 0.3])
body2.Joint=jnt2;
jnt2.JointAxis=[0 0 1];
addBody(robot,body2,'Body1');
body3=rigidBody('tool_tip');
jnt3=rigidBodyJoint('jnt3','fixed');
setFixedTransform(jnt3,trvec2tform([L2+EE 0 0]));
%jnt3.JointAxis=[0 0 1];
addVisual(body3,'Cylinder',[0.03 0.3]);
body3.Joint=jnt3;
q1=pi/4;
q2=pi/6;
addBody(robot,body3,'body2');
showdetails(robot);
config=homeConfiguration(robot);
%config=randomConfiguration(robot);
config(1).JointPosition=q1;
config(2).JointPosition=q2;
disp(config);
%This is Forward kinematics in matlab
t=getTransform(robot,config,"tool_tip","base");
x_m=t(1,4);
y_m=t(2,4);
%analytical fk
x_a = L1*cos(q1) + (L2+EE)*cos(q1+q2);
y_a = L1*sin(q1) + (L2+EE)*sin(q1+q2);
disp([x_a ,y_a]);
disp([x_m ,y_m]);
pos=tform2trvec(t);
disp(pos);
s=show(robot ,config);
hold(s,'on');

%circle formation for later ik
center_x=0.3;
center_y=0.1;
r=0.15;
theta=linspace(0,2*pi,500);
x=center_x+r*cos(theta);
y=center_y+r*sin(theta);
points=[x;y;zeros(size(x))];
r_points=points';
disp(size(r_points));
plot(x,y,'b','LineWidth',2)
axis(s,'equal')
grid (s,'on')
%the ik part using normal inverseKinematics function as dont need multiple
%constraints
q0=homeConfiguration(robot);
ik=inverseKinematics('RigidBodyTree',robot);
weights=[0,0,0,1,1,0];
endEffector='tool_tip';
q_initial=q0;
for i=1:10
    point=r_points(i,:);
    
    [a,b]=ik(endEffector,trvec2tform(point),weights,q_initial);
    %ik_arr(i,:)=ik_var;
    q_initial=ik_var;
end
disp(b);
