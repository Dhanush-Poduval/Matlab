body1=rigidBody('Body1');
jnt1=rigidBodyJoint('jnt1','revolute');
setFixedTransform(jnt1,trvec2tform([0 0 0]));
jnt1.JointAxis=[0 0 1];
body1.Joint=jnt1;
robot=rigidBodyTree;
addBody(robot,body1,'base');
show(robot);