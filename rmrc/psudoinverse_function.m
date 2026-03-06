function [x,y]=psudoinverse_function(endEffector,velocities)
arguments
    endEffector (1,:) char 
    velocities (6,1) double
end
    dt=0.05;
    robot=generalizedRobotforcodeGen();
    config=homeConfiguration(robot);
    for i=1:200
        J=geometricJacobian(robot,config,endEffector);
        dq=pinv(J)*velocities;
        config=config+dq' *dt;
        check_endeffector=getTransform(robot,config,endEffector);
        ee_pos=check_endeffector(1:3,4);
        disp(ee_pos);
        x=config;
        y=0;

        
    end
    