robot=loadrobot('universalUR5',DataFormat='row');
gik=generalizedInverseKinematics( ... 
    RigidBodyTree=robot, ...
    SolverAlgorithm="fminconsqp",...
    ConstraintInputs={"orientation","cartesian"});
ee=robot.BodyNames{end};
ori=constraintOrientationTarget(ee);
ori.TargetOrientation=eul2quat([0 pi 0],"ZYX");
cartBnds=constraintCartesianBounds(ee);
cartBnds.Bounds = [-0.4 0.4; 0.4 0.8; 0.0 0.4];
initGuessConfig = [pi/2 -pi/3 0 0 0 0];
[config,solutionInfo] = gik(initGuessConfig,ori,cartBnds);
show(robot,config);
title("End effector meets orientation");
axis([-0.5 0.5 -0.1 0.9 -0.1 0.8]);
b = cartBnds.Bounds;
x = b(1,:); y = b(2,:); z = b(3,:);
vertices = [x(1) y(1) z(1); x(2) y(1) z(1); x(2) y(2) z(1); x(1) y(2) z(1); ...
            x(1) y(1) z(2); x(2) y(1) z(2); x(2) y(2) z(2); x(1) y(2) z(2)];
faces = [1 2 3 4; 5 6 7 8; 1 2 6 5; 2 3 7 6; 3 4 8 7; 4 1 5 8];

patch('Vertices', vertices, 'Faces', faces, 'FaceColor', 'b', 'FaceAlpha', 0.2);
view(3); grid on;
hold off

