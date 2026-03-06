function [x,y]=psudoinverse_function(endEffector,velocities,config)
arguments
    endEffector (1,:) char 
    velocities (6,1) double
    config (1,6) double
end
    lambda=0.05;
    dt=0.1;
    persistent robot
    if isempty(robot)
        robot=rmrcRobot();
    end
    new_config=config;
    J=geometricJacobian(robot,new_config,endEffector);
    J_pos=J(1:3,:);
    A=(J_pos*J_pos' + lambda^2 * eye(3)) \ velocities(1:3);
    dq= J_pos' * (A);
    new_config=new_config+dq' *dt;
    x=new_config;
    y=0;

        
    
    