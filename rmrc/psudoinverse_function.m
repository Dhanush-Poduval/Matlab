function [x,y]=psudoinverse_function(endEffector,velocities,config)
arguments
    endEffector (1,:) char 
    velocities (6,1) double
    config (1,7) double
end
    lambda=0.05;
    dt=0.1;
    persistent robot
    if isempty(robot)
        robot=generalizedRobotforcodeGen();
    end
    new_config=config;
    J=geometricJacobian(robot,new_config,endEffector);
    
    
    A=(J*J' + lambda^2 * eye(6)) \ velocities;
    dq= J' * (A);
    new_config=new_config+dq' *dt;
    x=new_config;
    y=0;

        
    
    