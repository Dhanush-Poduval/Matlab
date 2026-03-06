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
    new_config=config(1,:);
    J=geometricJacobian(robot,new_config,endEffector);
    size_J=size(J);
    disp(size_J);
    J_base=J(1:3,:);
    size_Jbase=size(J_base);
    disp(size_Jbase);
    dq= pinv(J_base)*velocities(1:3);
    %dq= J_base' * ((J_base*J_base' + lambda^2 * eye(3)) \ velocities(1:3));
    new_config=new_config+dq' *dt;
    x=new_config;
    y=0;

        
    
    