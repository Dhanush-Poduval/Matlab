function [x,y]=psudoinverse_function(endEffector,velocities,config)
arguments
    endEffector (1,:) char 
    velocities (6,1) double
    config (1,7) double
end
    dt=0.1;
    persistent robot
    if isempty(robot)
        robot=generalizedRobotforcodeGen();
    end
    new_config=config(1,:);
    disp(config);
    
    J=geometricJacobian(robot,new_config,endEffector);
    J_base=J(1:3,:);
    dq=pinv(J_base)*velocities(1:3);
    v_actual=J*dq;
    disp(v_actual);
    new_config=new_config+dq' *dt;
    x=new_config;
    y=0;

        
    
    