function [x,y]=psudoinverse_function(endEffector,velocities)
arguments
    endEffector (1,64) char 
    velocities (1,6) int16
end
    robot=generalizedRobotforcodeGen();
    config=homeConfiguration(robot);
    