function [x,y]=psudoinverse_function(endEffector,velocities)
arguments
    endEffector (1,64) char 
    velocities (1,6) int
end
    dt=0.05;
    robot=generalizedRobotforcodeGen();
    config=homeConfiguration(robot);
    for i=1:200
        J=geometricJacobian(robot,config,endEffector);
        dq=pinv(J)*velocities;
        config=config+dq' *dt;
        check_endeffector=getTransform(robot,config,endEffector);
        x=check_endeffector;
        
    end
    