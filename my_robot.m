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
t=getTransform(robot,config,"tool_tip");
disp(t);
pos=tform2trvec(t);
disp(pos);
show(robot ,config);
