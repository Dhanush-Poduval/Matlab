function [x,y]=psudoinverse_function(endEffector,velocities)
arguments
    endEffector (1,:) char 
    velocities (6,1) double
end
    dt=0.05;
    persistent robot
    if isempty(robot)
        robot=generalizedRobotforcodeGen();
    end
    config=zeros(1,7);
    disp(config);
    for i=1:200
        J=geometricJacobian(robot,config,endEffector);
        dq=pinv(J)*velocities;
        config=config+dq' *dt;
        x=config;
        y=0;

        
    end
    