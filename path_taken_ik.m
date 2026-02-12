function [x,y]=path_taken_ik(q_inital,endEffector,final_pos)
%{
arguments
    q_inital (1,:) double
    endEffector (1,64) char
    final_pos  (1,:) double
end
%}
    b=generalizedRobotforcodeGen();
    weights=[1 1 1 1 1 1];
    ik=inverseKinematics("RigidBodyTree",b);
    %overall_size=size(q_trajectory,1);
    [x,y]=ik(endEffector,trvec2tform(final_pos),weights,q_inital);

       